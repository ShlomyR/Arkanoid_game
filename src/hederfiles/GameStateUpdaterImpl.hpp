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

class GameStateUpdaterImpl : public GameStateUpdater
{
public:
    GameStateUpdaterImpl(GameState &
        , InputHandler &
        , Menu &
        , PhysicsManager &
        , Hud &
        , Paddle &
        , Brick &
        , GameResetter &
        , WindowManager &
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
    PhysicsManager &m_physicsManager;
    Hud &m_hud;
    Paddle &m_paddle;
    Brick &m_brick;
    GameResetter &m_gameResetter;
    WindowManager &m_windowManager;

    static bool m_isMusicPlayed;
};
