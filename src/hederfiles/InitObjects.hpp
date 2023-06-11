#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#include "Ball.hpp"
#include "Paddle.hpp"
#include "Border.hpp"
#include "Brick.hpp"
#include "WindowManager.hpp"
#include "GameLoop.hpp"
#include "InputHandlerImpl.hpp"
#include "GameState.hpp"
#include "GameStateUpdaterImpl.hpp"
#include "Renderer.hpp"
#include "MouseButton.hpp"
#include "PhysicsManager.hpp"
#include "Hud.hpp"
#include "StateChanger.hpp"
#include "Points.hpp"
#include "HighScoreManager.hpp"
#include "Parser/BlockParser.hpp"
#include "GameResetter.hpp"
#include "Background.hpp"
#include "Menu.hpp"
#include "Options.hpp"
#include "Difficulty.hpp"
#include "Resoloution.hpp"
#include "Video.hpp"
#include "ControlSettings.hpp"
#include "ControlSettingsMenu.hpp"
#include "VolumeManager.hpp"

class InitObjects
{
public:
    InitObjects(sf::Vector2u windowSize, std::string windowTitle, int startingLives, int startingLevel, int maxLevel);

    void init();
    void run();

private:
    WindowManager m_window;
    ControlSettings m_controlSettings;
    ControlSettingsMenu m_controlSettingsMenu;
    VolumeManager m_volumeManager;
    Border m_border;
    Paddle m_paddle;
    Ball m_ball;
    Menu m_menu;
    Options m_options;
    Difficulty m_difficulty;
    Video m_video;
    Brick m_brick;
    Points m_points;
    Hud m_hud;
    Resoloution m_resoloution;
    GameState m_gameState;
    Background m_background;
    PaddleArrowsHandnling m_paddleKeys;
    std::unique_ptr<GameResetter> m_gameResetter;
    PhysicsManager m_physicsManager;
    std::unique_ptr<InputHandler> m_inputHandler;
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<GameStateUpdater> m_gameStateUpdater;
    std::unique_ptr<GameLoop> m_gameLoop;


};