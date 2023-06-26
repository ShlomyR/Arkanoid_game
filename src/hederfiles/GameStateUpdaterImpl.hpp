#pragma once

#include "GameStateUpdater.hxx"
#include "WindowManager.hpp"
#include "GameState.hpp"
#include "Menu.hpp"

#include <memory>

class PhysicsManager;
class Hud;
class Paddle;
class Brick;
class GameResetter;
class InputHandler;
class Options;
class Difficulty;
class Video;
class PaddleArrowsHandnling;

class GameStateUpdaterImpl : public GameStateUpdater
{
public:
    GameStateUpdaterImpl(GameState &
        , InputHandler &
        , Menu &
        , Options &
        , Difficulty &
        , Video &
        , PhysicsManager &
        , Hud &
        , Paddle &
        , Brick &
        , GameResetter &
        , WindowManager &
        , PaddleArrowsHandnling &
    );

    void update() override;
    bool gameOver() const override;
    void updateState() override;
    void setGameState(State) override;
private:
    void updateMenuPage();
    void updatePlayPage();
    void updateHighScorePage();
    void updateHighScore();
    void updateRegisterHighScorePage();
    void updateNextLevelOrGameOver();
private:
    GameState &m_gameState;
    InputHandler &m_inputHandler;
    Menu &m_menu;
    Options &m_options;
    Difficulty &m_difficulty;
    Video &m_video;
    PhysicsManager &m_physicsManager;
    Hud &m_hud;
    Paddle &m_paddle;
    Brick &m_brick;
    GameResetter &m_gameResetter;
    WindowManager &m_windowManager;
    PaddleArrowsHandnling &m_paddleKeys;

    static bool m_isMusicPlayed;
};
