#include "GameStateUpdaterImpl.hpp"
#include "InputHandler.hxx"
#include "PhysicsManager.hpp"
#include "WindowManager.hpp"
#include "Hud.hpp"
#include "Paddle.hpp"
#include "Brick.hpp"
#include "GameResetter.hpp"
#include "SoundManager.hpp"
#include "Options.hpp"
#include "Difficulty.hpp"
#include "Video.hpp"
#include "PaddleArrowsHandnling.hpp"
#include "MenuScreenHandler.hpp"

#include <unistd.h>
#include <thread>

bool GameStateUpdaterImpl::m_isMusicPlayed;

GameStateUpdaterImpl::GameStateUpdaterImpl(GameState &gameState
    , InputHandler &inputHandler
    , Menu &menu
    , Options &options
    , Difficulty &difficulty
    , Video &video
    , PhysicsManager &physicsManager
    , Hud &hud
    , Paddle &paddle
    , Brick &brick
    , GameResetter &gameResetter
    , WindowManager &windowManager
    , PaddleArrowsHandnling &paddleKeys
    , MenuScreenHandler &menuScreenHandler
)
: m_gameState(gameState)
, m_inputHandler(inputHandler)
, m_menu(menu)
, m_options(options)
, m_difficulty(difficulty)
, m_video(video)
, m_physicsManager(physicsManager)
, m_hud(hud)
, m_paddle(paddle)
, m_brick(brick)
, m_gameResetter(gameResetter)
, m_windowManager(windowManager)
, m_paddleKeys(paddleKeys)
, m_menuScreenHandler(menuScreenHandler)
{
    m_isMusicPlayed = false;
    SoundManager::getInstance()->playMusic("The_Last_of_Us_Remastered_Main_Menu_at_4K_(All_Tracks).wav");
}

void GameStateUpdaterImpl::update()
{
    if (m_gameState.getState() == State::MenuPage) {
        updateMenuPage();
    } else if (m_gameState.getState() == State::PlayPage) {
        updatePlayPage();
    } else if (m_gameState.getState() == State::HighScorePage) {
        m_menuScreenHandler.setCurrPage("HighScorePage");
        m_menuScreenHandler.updateBox("HighScorePage");
        updateHighScorePage();
    } else if (m_gameState.getState() == State::UpdateHighScorePage) {
        updateRegisterHighScorePage();
    } else if (m_gameState.getState() == State::OptionsPage) {
        m_options.setIsOptionsPageShown(true);
        m_menu.setIsMenuPageShown(false);
        m_difficulty.setIsDifficultyPageShown(false);
        m_video.setIsVideoPageShown(false);
        m_menuScreenHandler.setCurrPage("OptionsPage");
        m_menuScreenHandler.updateBox("OptionsPage");
        m_options.handleInput(m_inputHandler, m_gameState);
    } else if (m_gameState.getState() == State::DifficultyPage) {
        m_options.setIsOptionsPageShown(false);
        m_menu.setIsMenuPageShown(false);
        m_difficulty.setIsDifficultyPageShown(true);
        m_video.setIsVideoPageShown(false);
        m_menuScreenHandler.setCurrPage("DifficultyPage");
        m_menuScreenHandler.updateBox("DifficultyPage");
        m_difficulty.handleInput(m_inputHandler, m_gameState);
    } else if (m_gameState.getState() == State::VideoPage) {
        m_options.setIsOptionsPageShown(false);
        m_menu.setIsMenuPageShown(false);
        m_difficulty.setIsDifficultyPageShown(false);
        m_video.setIsVideoPageShown(true);
        m_menuScreenHandler.setCurrPage("VideoPage");
        m_menuScreenHandler.updateBox("VideoPage");
        m_video.handleInput(m_inputHandler, m_gameState);
        m_gameResetter.reset();
    } else if (m_gameState.getState() == State::ControlSettingPage) {
        m_options.setIsOptionsPageShown(false);
        m_menu.setIsMenuPageShown(false);
        m_difficulty.setIsDifficultyPageShown(false);
        m_video.setIsVideoPageShown(false);
        m_menuScreenHandler.setCurrPage("ControlSettingPage");
        m_menuScreenHandler.updateBox("ControlSettingPage");
        m_hud.update(m_gameState);
    } else if (m_gameState.getState() == State::VolumePage) {
        m_options.setIsOptionsPageShown(false);
        m_menu.setIsMenuPageShown(false);
        m_difficulty.setIsDifficultyPageShown(false);
        m_video.setIsVideoPageShown(false);
        m_menuScreenHandler.setCurrPage("VolumePage");
        m_menuScreenHandler.updateBox("VolumePage");
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
   if (m_brick.getVecBricks()[m_gameState.getLevel()].empty() || m_gameState.getHealth() <= 0) {
        m_paddle.setIsPressed(false);
        m_gameState.resetBallPos();
        if (m_gameState.getLevel() != m_gameState.getMaxLevel()) {
            m_gameState.nextLevel();
            m_brick.setCurrLevel(m_gameState.getLevel());
        } else if (m_gameState.getScore() == m_gameState.getHighScore()) {
            m_gameState.setState(State::UpdateHighScorePage);
        } else {
            m_gameState.setState(State::GameOver);
            m_gameResetter.reset();
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
        SoundManager::getInstance()->playMusic();
        // SoundManager::getInstance()->setMusicLoop(true);
        m_isMusicPlayed = true;
    }
    m_menu.setIsMenuPageShown(true);
    m_windowManager.getRenderWindow().setMouseCursorVisible(true);
    m_menu.handleInput(m_inputHandler, m_gameState);
}

void GameStateUpdaterImpl::updatePlayPage()
{
    m_windowManager.getRenderWindow().setMouseCursorVisible(false);
    m_hud.getName() = " ";
    updateHighScore();
    updateNextLevelOrGameOver();
    m_isMusicPlayed = false;
    SoundManager::getInstance()->pausedMusic();
    m_physicsManager.update(0.03);
    m_hud.update(m_gameState);
    m_paddleKeys.update();
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
    m_windowManager.getRenderWindow().setMouseCursorVisible(false);
    m_gameResetter.reset();
    m_hud.update(m_gameState);
}

void GameStateUpdaterImpl::updateRegisterHighScorePage()
{
    m_windowManager.getRenderWindow().setMouseCursorVisible(false);
    m_hud.update(m_gameState);
}
