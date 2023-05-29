#include "GameStateUpdaterImpl.hpp"
#include "PhysicsManager.hpp"
#include "WindowManager.hpp"
#include "Hud.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "GameResetter.hpp"
#include "SoundManager.hpp"

#include <unistd.h>
#include <thread>

bool GameStateUpdaterImpl::m_isMusicPlayed;

GameStateUpdaterImpl::GameStateUpdaterImpl(GameState &gameState
    , InputHandler &inputHandler
    , Menu &menu
    , PhysicsManager &physicsManager
    , Hud &hud
    , Paddle &paddle
    , Brick &brick
    , GameResetter &gameResetter
    , WindowManager &windowManager
)
: m_gameState(gameState)
, m_inputHandler(inputHandler)
, m_menu(menu)
, m_physicsManager(physicsManager)
, m_hud(hud)
, m_paddle(paddle)
, m_brick(brick)
, m_gameResetter(gameResetter)
, m_windowManager(windowManager)
{
    m_isMusicPlayed = false;
}

void GameStateUpdaterImpl::update()
{
    if (m_gameState.getState() == State::MenuPage) {
        updateMenuPage();
    } else if (m_gameState.getState() == State::PlayPage) {
        updatePlayPage();
    } else if (m_gameState.getState() == State::HighScorePage) {
        updateHighScorePage();
    } else if (m_gameState.getState() == State::UpdateHighScorePage) {
        updateRegisterHighScorePage();
    } else if (m_gameState.getState() == State::Exit) {
        m_windowManager.getRenderWindow().close();
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

void GameStateUpdaterImpl::updateNextLevelOrGameOver()
{
   if (m_brick.getVecBricks()[m_gameState.getLevel()].empty() || m_gameState.getHealth() == 0) {
        m_paddle.setIsPressed(false);
        if (m_gameState.getLevel() != m_gameState.getMaxLevel()) {
            m_gameState.nextLevel();
            m_brick.setCurrLevel(m_gameState.getLevel());
        } else if (m_gameState.getScore() == m_gameState.getHighScore()) {
            m_gameState.setState(State::UpdateHighScorePage);
        } else {
            m_gameResetter.reset();
            m_gameState.setState(State::GameOver);
        }
    } 
}

void GameStateUpdaterImpl::updateState()
{
    // if (m_gameState.getState() == State::BrickEmpty) {
    //    // m_brick.init();
    //     // m_reset.reset();
    //     m_gameState.nextLevel();
    // } else if (m_gameState.getState() == State::BallOutOfBounds) {
    //     m_paddle.setIsPressed(false);
    //     m_gameState.decreaseHealth();
    // } else if (m_gameState.getState() == State::NoHealth) {
    //     // m_reset.reset();
    //     sleep(3);
    // }
}

void GameStateUpdaterImpl::setGameState(State state)
{
    m_gameState.setState(state);
}

void GameStateUpdaterImpl::updateMenuPage()
{
    if (!m_isMusicPlayed) {
        SoundManager::getInstance()->playMusic("src/sounds/b423b42.wav");
        SoundManager::getInstance()->setMusicLoop(true);
        m_isMusicPlayed = true;
    }
    m_menu.handleInput(m_inputHandler, m_gameState);
}

void GameStateUpdaterImpl::updatePlayPage()
{
    m_isMusicPlayed = false;
    SoundManager::getInstance()->stopSMusic();
    m_physicsManager.update(0.03);
    m_hud.update(m_gameState);
    m_paddle.update();
    updateHighScore();
    updateNextLevelOrGameOver();
}

void GameStateUpdaterImpl::updateHighScore()
{
    if (m_gameState.getScore() < m_gameState.getHighScore()) {
        m_gameState.setHighScore(m_hud.getHighScoreManager().getData(0).score);
    } else {
        m_gameState.setHighScore(m_gameState.getScore());
    }
}

void GameStateUpdaterImpl::updateHighScorePage()
{
    m_gameResetter.reset();
    m_hud.update(m_gameState);
}

void GameStateUpdaterImpl::updateRegisterHighScorePage()
{
    m_hud.update(m_gameState);
}
