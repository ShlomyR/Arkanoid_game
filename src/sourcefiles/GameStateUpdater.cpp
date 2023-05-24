#include "../hederfiles/GameStateUpdater.hpp"
#include "../hederfiles/PhysicsManager.hpp"
#include "../hederfiles/Hud.hpp"
#include "../hederfiles/Paddle.hpp"
#include "../hederfiles/Brick.hpp"
#include "../hederfiles/GameStateUpdater.hpp"
#include "../hederfiles/GameResetter.hpp"
#include "../hederfiles/SoundManager.hpp"

#include <unistd.h>
#include <thread>

GameStateUpdaterImpl::GameStateUpdaterImpl(GameState &gameState,InputHandler &inputHandler,Menu &menu,PhysicsManager &physicsManager, Hud &hud, Paddle &paddle, Brick &brick, GameResetter &gameResetter)
: m_gameState(gameState)
, m_inputHandler(inputHandler)
, m_menu(menu)
, m_physicsManager(physicsManager)
, m_hud(hud)
, m_paddle(paddle)
, m_brick(brick)
, m_gameResetter(gameResetter)
{}

void GameStateUpdaterImpl::update()
{
    static bool isMusicPlayed = false;
    
    if (m_gameState.getState() == State::MenuPage) {
        if (!isMusicPlayed) {
            SoundManager::getInstance()->playMusic("src/sounds/b423b42.wav");
            SoundManager::getInstance()->setMusicLoop(true);
            isMusicPlayed = true;
        }
        m_menu.handleInput(m_inputHandler, m_gameState);
    } else if (m_gameState.getState() == State::PlayPage) {
        isMusicPlayed = false;
        // if (isMusicPlayed) {
        //     SoundManager::getInstance()->switchMusic("src/sounds/b423b42.wav");
        //     isMusicPlayed = false;
        // }
        SoundManager::getInstance()->stopSMusic();
        m_physicsManager.update(0.03);
        m_hud.update(m_gameState.getScore(), m_gameState.getHealth(), m_gameState.getHighScore(), m_gameState);
        m_paddle.update();
    } else if (m_gameState.getState() == State::HighScorePage) {
        m_gameResetter.reset();
        m_hud.update(m_gameState.getScore(), m_gameState.getHealth(), m_gameState.getHighScore(), m_gameState);
    } else if (m_gameState.getState() == State::UpdateHighScorePage) {
        // m_gameResetter.reset();
        m_hud.update(m_gameState.getScore(), m_gameState.getHealth(), m_gameState.getHighScore(), m_gameState);
    } else if (m_gameState.getState() == State::Exit) {
        //m_updateHighScore.update();
    }
}

bool GameStateUpdaterImpl::gameOver() const
{
    if (m_gameState.getState() == State::GameOver) {
        return true;
    } else {
        return false;

    }
}

void GameStateUpdaterImpl::updateState()
{
    if (m_gameState.getState() == State::BrickEmpty) {
       // m_brick.init();
        // m_reset.reset();
        m_gameState.nextLevel();
    } else if (m_gameState.getState() == State::BallOutOfBounds) {
        m_paddle.setIsPressed(false);
        m_gameState.decreaseHealth();
    } else if (m_gameState.getState() == State::NoHealth) {
        // m_reset.reset();
        sleep(3);
    }
}

void GameStateUpdaterImpl::setGameState(State state)
{
    m_gameState.setState(state);
}