#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "../hederfiles/Ball.hpp"
#include "../hederfiles/Paddle.hpp"
#include "../hederfiles/Border.hpp"
#include "../hederfiles/Brick.hpp"
#include "../hederfiles/WindowManager.hpp"
#include "../hederfiles/GameLoop.hpp"
#include "../hederfiles/InputHandler.hpp"
#include "../hederfiles/GameState.hpp"
#include "../hederfiles/GameStateUpdater.hpp"
#include "../hederfiles/Renderer.hpp"
#include "../hederfiles/Menu.hpp"
#include "../hederfiles/MouseButton.hpp"
#include "../hederfiles/PhysicsManager.hpp"
#include "../hederfiles/Hud.hpp"
#include "../hederfiles/StateChanger.hpp"
#include "../hederfiles/Points.hpp"
#include "../hederfiles/HighScoreManager.hpp"
#include "../hederfiles/Parser_1.hpp"
#include "../hederfiles/GameResetter.hpp"

class InitObjects {
public:
    InitObjects(sf::Vector2u windowSize, std::string windowTitle, int startingLives, int startingLevel, int maxLevel);

    void init();
    void run();

private:
    WindowManager m_window;
    Border m_border;
    Paddle m_paddle;
    Ball m_ball;
    GameState m_gameState;
    Brick m_brick;
    Points m_points;
    Menu m_menu;
    Hud m_hud;
    Parser m_parser;
    PaddleArrowsHandnling m_paddleKeys;
    std::unique_ptr<GameResetter> m_gameResetter;
    PhysicsManager m_physicsManager;
    std::unique_ptr<InputHandler> m_inputHandler;
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<GameStateUpdater> m_gameStateUpdater;
    std::unique_ptr<GameLoop> m_gameLoop;

};