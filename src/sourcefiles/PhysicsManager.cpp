#include "PhysicsManager.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Border.hpp"
#include "Paddle.hpp"
#include "GameState.hpp"
#include "Points.hpp"

PhysicsManager::PhysicsManager(Ball& ball
    , Brick& brick
    , Paddle& paddle
    , Border& border
    , GameState& game_state
    , Points &points
)
: m_ball(ball)
, m_brick(brick)
, m_paddle(paddle)
, m_border(border)
, m_game_state(game_state)
, m_points(points)
, m_ballSpeed(200.f)
{}

void PhysicsManager::update(float )
{
    checkPaddleBallCollision();
    checkBrickBallCollision();
    checkBorderBallCollision();
    checkPaddleBorderCollision();
    m_ball.setBallSpeed(m_game_state.getBallSpeed_());
    if (m_paddle.getIsPressed()) {
        m_ball.move(m_ball.getDirection().x * m_ballSpeed * m_ball.getBallSpeed(), m_ball.getDirection().y * m_ballSpeed *  m_ball.getBallSpeed());
    } else {
        m_ball.setPosition(m_paddle.getCenterPosition().x, m_paddle.getCenterPosition().y);
    }   
}

void PhysicsManager::checkPaddleBallCollision()
{
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

void PhysicsManager::checkBrickBallCollision() 
{
    sf::Vector2f ballPos = m_ball.getPosition();
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


void PhysicsManager::checkBorderBallCollision()
{
    if (m_ball.getPosition().x - m_ball.getRadius() <= m_border.getShape()->getGlobalBounds().left+5 || 
        m_ball.getPosition().x + m_ball.getRadius() >= m_border.getShape()->getGlobalBounds().width-7) {
        m_ball.setDirection(sf::Vector2f(-m_ball.getDirection().x, m_ball.getDirection().y));
    }
    if (m_ball.getPosition().y - m_ball.getRadius() <= m_border.getShape()->getGlobalBounds().top +10) {
        m_ball.setDirection(sf::Vector2f(m_ball.getDirection().x, -m_ball.getDirection().y));
    }
    if (m_ball.getPosition().y + m_ball.getRadius() >= m_border.getShape()->getGlobalBounds().height) {
        m_game_state.decreaseHealth();
        m_paddle.setIsPressed(false);
    }
}

void PhysicsManager::checkPaddleBorderCollision()
{
    const sf::Vector2f borderPos = m_border.getPosition();
    const sf::Vector2f borderSize = m_border.getShape()->getSize();
    const sf::Vector2f paddlePos = m_paddle.getPosition();
    const sf::Vector2f paddleSize = m_paddle.getShape()->getSize();
    float newPaddleX = std::max(borderPos.x, std::min(paddlePos.x, borderPos.x + borderSize.x - paddleSize.x));
    if (newPaddleX != paddlePos.x) {
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
