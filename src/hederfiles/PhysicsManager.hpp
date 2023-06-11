#pragma once

#include <SFML/Graphics.hpp>

class Ball;
class Brick;
class Border;
class Paddle;
class GameState;
class Points;
class GameResetter;


class PhysicsManager 
{
public:
    PhysicsManager(Ball&
        , Brick&
        , Paddle&
        , Border&
        , GameState&
        , Points &
        , GameResetter &
    );
        void update(float);
private:
    void checkPaddleBallCollision();
    void checkBrickBallCollision();
    void checkBorderBallCollision();
    void checkPaddleBorderCollision();
    float dotProduct(const sf::Vector2f&, const sf::Vector2f&);
    sf::Vector2f reflect(const sf::Vector2f&, const sf::Vector2f&);
private:
    Ball &m_ball;
    Brick &m_brick;
    Paddle &m_paddle;
    Border &m_border;
    GameState &m_game_state;
    Points &m_points;
    GameResetter &m_gameResetter;

    float m_deltaTime;
    float m_ballSpeed;
};