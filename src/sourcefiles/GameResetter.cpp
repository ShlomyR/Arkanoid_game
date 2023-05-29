#include "GameResetter.hpp"
#include "Brick.hpp"
#include "Paddle.hpp"
#include "WindowManager.hpp"
#include "GameState.hpp"

GameResetterImpl::GameResetterImpl(Brick &brick, Paddle &paddle,WindowManager &window, GameState &gameState)
: m_brick(brick)
, m_paddle(paddle)
, m_window(window)
, m_gameState(gameState)
{}

void GameResetterImpl::resetGameOver()
{
    m_brick.deleteAllBricks();
    m_brick.initializeLevels();
    m_paddle.setIsPressed(false);
    m_paddle.setPosition(m_window.getSize().x / 2.f - 50, m_window.getSize().y - 20);
    m_gameState.reset();
    m_gameState.setState(State::MenuPage);
}

void GameResetterImpl::reset()
{
    m_brick.deleteAllBricks();
    m_brick.initializeLevels();
    m_paddle.setIsPressed(false);
    m_paddle.setPosition(m_window.getSize().x / 2.f - 50, m_window.getSize().y - 20);
    m_gameState.reset();
}