#include "GameLoop.hpp"
#include "GameResetter.hpp"

GameLoopImpl::GameLoopImpl(WindowManager &window, InputHandler &inputHandler, GameStateUpdater &gameStateUpdater, Renderer &renderer, GameResetter &gameResetter)
: m_window(window)
, m_inputHandler(inputHandler)
, m_gameStateUpdater(gameStateUpdater)
, m_renderer(renderer)
, m_gameResetter(gameResetter)
{

}

void GameLoopImpl::run()
{
    while (m_window.isOpen()) {
        m_inputHandler.handleInput();
        m_gameStateUpdater.update();
        m_renderer.render();
        if (m_gameStateUpdater.gameOver()) {
            m_gameResetter.resetGameOver();
        }
    }
}
