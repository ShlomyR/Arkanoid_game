#include "InitObjects.hpp"
#include "BrickSetter.hpp"

InitObjects::InitObjects(sf::Vector2u windowSize, std::string windowTitle, int startingLives, int startingLevel, int maxLevel)
    : m_window(windowSize, windowTitle)
    , m_controlSettings()
    , m_controlSettingsMenu(m_controlSettings, m_window.getRenderWindow())
    , m_volumeManager(m_window.getRenderWindow())
    , m_border(sf::Vector2f(windowSize.x - 5, windowSize.y - 5),sf::Vector2f(windowSize.x - 797.f, windowSize.y - 597.f),sf::Color::Red)
    , m_paddle(sf::Vector2f(100.f, 10.f), sf::Vector2f(windowSize.x / 2.f - 50, windowSize.y - 20), sf::Color::Blue)
    , m_ball(10.f, sf::Vector2f(windowSize.x / 2.f, windowSize.y - 20), sf::Color::White)
    , m_menu(m_window)
    , m_options(m_window)
    , m_difficulty(m_window)
    , m_video(m_window)
    , m_brick(sf::Vector2f(25.f, 10.f), sf::Vector2f(windowSize.x / 2.f - 50, windowSize.y - 40), sf::Color::Yellow,m_gameState)
    , m_points(m_gameState)
    , m_hud(m_window.getRenderWindow())
    , m_resoloution(m_window, m_border, m_paddle, m_brick, m_hud, m_menu, m_options, m_difficulty, m_video, m_controlSettingsMenu, m_volumeManager)
    , m_gameState(startingLives, startingLevel, 0,0,maxLevel, m_video, m_difficulty, m_options, m_menu, m_ball, m_paddle, m_window, m_resoloution, m_controlSettings)
    , m_background()
    , m_paddleKeys(m_paddle, m_controlSettings)
    , m_gameResetter(std::make_unique<GameResetterImpl>(m_brick,m_paddle,m_window,m_gameState))
    , m_physicsManager(m_ball, m_brick, m_paddle, m_border, m_gameState, m_points)
    , m_inputHandler(std::make_unique<InputHandlerImpl>(m_window.getRenderWindow(), m_paddleKeys, m_gameState, m_menu, m_options, m_difficulty, m_video, m_hud, m_controlSettingsMenu, m_volumeManager))
    , m_renderer(std::make_unique<RendererImpl>(m_window, m_gameState, m_menu, m_options, m_difficulty, m_video, m_hud, m_paddle, m_ball, m_brick, m_border, m_background, m_controlSettingsMenu, m_volumeManager))
    , m_gameStateUpdater(std::make_unique<GameStateUpdaterImpl>(m_gameState, *m_inputHandler, m_menu, m_options, m_difficulty, m_video, m_physicsManager, m_hud, m_paddle, m_brick, *m_gameResetter, m_window, m_paddleKeys))
    , m_gameLoop(std::make_unique<GameLoopImpl>(m_window, *m_inputHandler, *m_gameStateUpdater, *m_renderer,*m_gameResetter))
{}

void InitObjects::init()
{
    m_brick.initializeLevels();
    m_brick.initVec();
}

void InitObjects::run()
{
    m_gameLoop->run();
}
