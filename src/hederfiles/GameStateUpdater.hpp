#pragma once

#include "GameStateUpdater.hxx"
#include "GameState.hpp"
#include "Menu.hpp"

class PhysicsManager;
class Hud;
class Paddle;
class Brick;
class GameResetter;

#include <memory>

class GameStateUpdaterImpl : public GameStateUpdater {
public:
    GameStateUpdaterImpl(GameState &gameState,InputHandler &inputHandler,Menu &menu,PhysicsManager &physicsManager, Hud &hud, Paddle &paddle, Brick &brick, GameResetter &gameResetter);

    void update() override;
    bool gameOver() const override;
    void updateState() override;
    void setGameState(State) override;

private:
    GameState &m_gameState;
    InputHandler &m_inputHandler;
    Menu &m_menu;
    PhysicsManager &m_physicsManager;
    Hud &m_hud;
    Paddle &m_paddle;
    Brick &m_brick;
    GameResetter &m_gameResetter;
};

