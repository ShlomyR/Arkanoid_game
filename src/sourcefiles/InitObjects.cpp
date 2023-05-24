#include "../hederfiles/InitObjects.hpp"

InitObjects::InitObjects(sf::Vector2u windowSize, std::string windowTitle, int startingLives, int startingLevel, int maxLevel)
    : m_window(windowSize, windowTitle)
    , m_border(sf::Vector2f(795.f, 595.f),sf::Vector2f(windowSize.x - 797.f, windowSize.y - 597.f),sf::Color::Red)
    , m_paddle(sf::Vector2f(100.f, 10.f), sf::Vector2f(windowSize.x / 2.f - 50, windowSize.y - 20), sf::Color::Blue)
    , m_ball(10.f, sf::Vector2f(windowSize.x / 2.f, windowSize.y - 20), sf::Color::White)
    , m_gameState(startingLives, startingLevel, 0,0,maxLevel)
    , m_brick(sf::Vector2f(25.f, 10.f), sf::Vector2f(windowSize.x / 2.f - 50, windowSize.y - 40), sf::Color::Yellow,m_gameState)
    , m_points(m_gameState)
    , m_menu(m_window, m_gameState)
    , m_hud(m_window.getRenderWindow())
    , m_blockParser()
    , m_paddleKeys(m_paddle)
    , m_gameResetter(std::make_unique<GameResetterImpl>(m_brick,m_paddle,m_window,m_gameState))
    , m_physicsManager(m_ball, m_brick, m_paddle, m_border, m_gameState, m_points, *m_gameResetter)
    , m_inputHandler(std::make_unique<InputHandlerImpl>(m_window.getRenderWindow(), m_paddleKeys, m_gameState, m_menu, m_hud))
    , m_renderer(std::make_unique<RendererImpl>(m_window, m_gameState, m_menu, m_physicsManager, m_hud, m_paddle, m_ball, m_brick, m_border))
    , m_gameStateUpdater(std::make_unique<GameStateUpdaterImpl>(m_gameState, *m_inputHandler, m_menu, m_physicsManager, m_hud, m_paddle, m_brick, *m_gameResetter))
    , m_gameLoop(std::make_unique<GameLoopImpl>(m_window, *m_inputHandler, *m_gameStateUpdater, *m_renderer,*m_gameResetter))
{}

void InitObjects::init()
{
    m_brick.initializeLevels(m_gameState.getMaxLevel());
}

void InitObjects::run()
{
    m_gameLoop->run();
}