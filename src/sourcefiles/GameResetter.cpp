#include "../hederfiles/GameResetter.hpp"
#include "../hederfiles/Brick.hpp"
#include "../hederfiles/Paddle.hpp"
#include "../hederfiles/WindowManager.hpp"
#include "../hederfiles/GameState.hpp"

GameResetterImpl::GameResetterImpl(Brick &brick, Paddle &paddle,WindowManager &window, GameState &gameState)
: m_brick(brick)
, m_paddle(paddle)
, m_window(window)
, m_gameState(gameState)
, m_parser()
{}

void GameResetterImpl::resetGameOver()
{
    m_brick.deleteAllBricks();
    m_brick.initializeLevels(2);
    m_paddle.setIsPressed(false);
    m_paddle.setPosition(m_window.getSize().x / 2.f - 50, m_window.getSize().y - 20);
    m_gameState.reset();
    m_gameState.setState(State::MenuPage);
}

void GameResetterImpl::reset()
{
    m_brick.deleteAllBricks();
    m_brick.initializeLevels(2);
    m_paddle.setIsPressed(false);
    m_paddle.setPosition(m_window.getSize().x / 2.f - 50, m_window.getSize().y - 20);
    m_gameState.reset();
}