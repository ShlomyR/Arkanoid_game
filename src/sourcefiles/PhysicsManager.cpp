#include "PhysicsManager.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Border.hpp"
#include "Paddle.hpp"
#include "GameState.hpp"
#include "Points.hpp"
#include "GameResetter.hpp"

PhysicsManager::PhysicsManager(Ball& ball, Brick& brick, Paddle& paddle, Border& border, GameState& game_state, Points &points, GameResetter &gameResetter)
: m_ball(ball)
, m_brick(brick)
, m_paddle(paddle)
, m_border(border)
, m_game_state(game_state)
, m_points(points)
, m_gameResetter(gameResetter)
, m_ballSpeed(200.f)
{}

void PhysicsManager::update(float deltaTime) {
    checkPaddleCollision(m_ball, m_paddle);
    checkBrickCollision(m_ball, m_brick, m_game_state);
    checkBorderCollision(m_ball, m_border);
    checkPaddleBorderCollision(m_paddle, m_border);

    if (m_paddle.getIsPressed()) {
        m_ball.move(m_ball.getDirection().x * m_ballSpeed * deltaTime,m_ball.getDirection().y * m_ballSpeed * deltaTime);
    } else {
        m_ball.setPosition(m_paddle.getCenterPosition().x,m_paddle.getCenterPosition().y);
    }   
}

void PhysicsManager::checkPaddleCollision(Ball& m_ball, Paddle& m_paddle) {
    const sf::Vector2f ballPos = m_ball.getPosition();
    const sf::Vector2f ballSize = m_ball.getShape()->getScale();
    const sf::Vector2f paddlePos = m_paddle.getPosition();
    const sf::Vector2f paddleSize = m_paddle.getShape()->getSize();
    const sf::Vector2f ballVel = m_ball.getDirection();

    if (ballVel.y > 0 && m_paddle.getShape()->getGlobalBounds().intersects(m_ball.getShape()->getGlobalBounds()))
    {
        float overlap = ballPos.x + ballSize.x / 2 - paddlePos.x - paddleSize.x / 2;
        float maxOverlap = paddleSize.x / 2 + ballSize.x / 2;
        overlap = std::max(-maxOverlap, std::min(maxOverlap, overlap));
        float reflectAngle = overlap / maxOverlap * (M_PI / 3);
        sf::Vector2f newBallVel = sf::Vector2f(-sin(reflectAngle), -cos(reflectAngle));
        newBallVel.x *= sqrt(ballVel.x * ballVel.x + ballVel.y * ballVel.y);
        m_ball.setDirection(newBallVel);
    }
}

void PhysicsManager::checkBrickCollision(Ball& m_ball, Brick& m_brick,GameState& m_game_state) 
{
    sf::Vector2f ballPos = m_ball.getShape()->getPosition();
    sf::Vector2f ballVel = m_ball.getDirection() * m_ball.getBallVelocity().x;

    for (size_t i = 0; i < m_brick.getVecBricks()[m_game_state.getLevel()].size(); ++i) {
        auto currentBrick = m_brick.getBrick(i);
        sf::FloatRect brickBounds = currentBrick.sprite.getGlobalBounds();
        if (brickBounds.intersects(m_ball.getShape()->getGlobalBounds())) {
            sf::Vector2f normal;
            float overlapX = std::min(ballPos.x + m_ball.getRadius(), brickBounds.left + brickBounds.width) 
                             - std::max(ballPos.x - m_ball.getRadius(), brickBounds.left);
            float overlapY = std::min(ballPos.y + m_ball.getRadius(), brickBounds.top + brickBounds.height) 
                             - std::max(ballPos.y - m_ball.getRadius(), brickBounds.top);
            if (overlapX > overlapY) {
                normal = sf::Vector2f(0, ballPos.y < brickBounds.top ? -1 : 1);
            } else {
                normal = sf::Vector2f(ballPos.x < brickBounds.left ? -1 : 1, 0);
            }

            ballVel = reflect(ballVel, normal);

            if (overlapX > overlapY) {
                ballPos.y += overlapY * (ballVel.y > 0 ? -1 : 1);
            } else {
                ballPos.x += overlapX * (ballVel.x > 0 ? -1 : 1);
            }
            m_brick.deleteBrick(i);
            m_points.assignedColorPointes(m_brick.getBrick(i).color);
            break;
        }
    }

    m_ball.setDirection(ballVel / m_ball.getBallVelocity().x);
}


void PhysicsManager::checkBorderCollision(Ball& m_ball, Border& m_border) {
    if (m_ball.getShape()->getPosition().x - m_ball.getShape()->getRadius() <= m_border.getShape()->getGlobalBounds().left || 
        m_ball.getShape()->getPosition().x + m_ball.getShape()->getRadius() >= m_border.getShape()->getGlobalBounds().width) {
        m_ball.setDirection(sf::Vector2f(-m_ball.getDirection().x, m_ball.getDirection().y));
    }
    if (m_ball.getShape()->getPosition().y - m_ball.getShape()->getRadius() <= m_border.getShape()->getGlobalBounds().top) {
        m_ball.setDirection(sf::Vector2f(m_ball.getDirection().x, -m_ball.getDirection().y));
    }
    if (m_ball.getShape()->getPosition().y + m_ball.getShape()->getRadius() >= m_border.getShape()->getGlobalBounds().height) {
        m_game_state.decreaseHealth();
        m_paddle.setIsPressed(false);
    }
}

void PhysicsManager::checkPaddleBorderCollision(Paddle& m_paddle, Border& m_border)
{
    const sf::Vector2f borderPos = m_border.getPosition();
    const sf::Vector2f borderSize = m_border.getShape()->getSize();
    const sf::Vector2f paddlePos = m_paddle.getPosition();
    const sf::Vector2f paddleSize = m_paddle.getShape()->getSize();
    float newPaddleX = std::max(borderPos.x, std::min(paddlePos.x, borderPos.x + borderSize.x - paddleSize.x));
    if (newPaddleX != paddlePos.x)
    {
        m_paddle.setPosition(newPaddleX, paddlePos.y);
    }
}

float PhysicsManager::dotProduct(const sf::Vector2f &vec1, const sf::Vector2f &vec2)
{
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

sf::Vector2f PhysicsManager::reflect(const sf::Vector2f &vec, const sf::Vector2f &normal)
{
    return vec - 2.f * dotProduct(vec, normal) * normal;
}
