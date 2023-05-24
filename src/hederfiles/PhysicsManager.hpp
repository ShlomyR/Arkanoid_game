#pragma once

#include <SFML/Graphics.hpp>
class Ball;
class Brick;
class Border;
class Paddle;
class GameState;
class Points;
class GameResetter;


class PhysicsManager {
public:
    PhysicsManager(
        Ball& ball
        , Brick& brick
        , Paddle& paddle
        , Border& border
        , GameState& game_state
        , Points &points
        , GameResetter &gameResetter
    );
        void update(float deltaTime);
private:
    void checkPaddleCollision(Ball& ball, Paddle& paddle);
    void checkBrickCollision(Ball& ball, Brick& brick,GameState& game_state);
    void checkBorderCollision(Ball& ball, Border& border);
    void checkPaddleBorderCollision(Paddle& paddle, Border& border);
    float dotProduct(const sf::Vector2f& vec1, const sf::Vector2f& vec2);
    sf::Vector2f reflect(const sf::Vector2f& vec, const sf::Vector2f& normal);
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