#include "Renderer.hpp"
#include "PhysicsManager.hpp"
#include "Hud.hpp"
#include "Paddle.hpp"
#include "Ball.hpp"
#include "Brick.hpp"
#include "Border.hpp"
#include "Background.hpp"
#include "Options.hpp"
#include "Difficulty.hpp"
#include "Video.hpp"
#include "ControlSettingsMenu.hpp"
#include "VolumeManager.hpp"
#include "SquareWithBricks.hpp"

RendererImpl::RendererImpl(WindowManager &window
    , GameState &gameState
    , Menu &menu
    , Options &options
    , Difficulty &difficulty
    , Video &video
    , PhysicsManager &physicsManager
    , Hud &hud
    , Paddle &paddle
    , Ball &ball
    , Brick &brick
    , Border &border
    , Background &background
    , ControlSettingsMenu &controlSettingsMenu
    , VolumeManager &volume
    , SquareWithBricks &squareWithBricks
)
: m_window(window)
, m_gameState(gameState)
, m_menu(menu)
, m_options(options)
, m_difficulty(difficulty)
, m_video(video)
, m_physicsManager(physicsManager)
, m_hud(hud)
, m_paddle(paddle)
, m_ball(ball)
, m_brick(brick)
, m_border(border)
, m_background(background)
, m_controlSettingsMenu(controlSettingsMenu)
, m_volume(volume)
, m_squareWithBricks(squareWithBricks)
{
    
}

void RendererImpl::render()
{
    if (m_gameState.getState() == State::MenuPage) {
        m_window.clear();
        m_background.draw(m_window.getRenderWindow());
        m_menu.drew();
        m_window.display();
    } else if (m_gameState.getState() == State::PlayPage) {
        m_window.clear();
        m_background.draw(m_window.getRenderWindow());
        m_border.draw(m_window.getRenderWindow());
        m_brick.draw(m_window.getRenderWindow());
        // m_squareWithBricks.draw(m_window.getRenderWindow());
        m_ball.draw(m_window.getRenderWindow());
        m_hud.draw(m_window.getRenderWindow(), "PlayPage");
        m_paddle.draw(m_window.getRenderWindow());
        m_window.display();
    } else if (m_gameState.getState() == State::HighScorePage) {
        m_window.clear();
        m_background.draw(m_window.getRenderWindow());
        m_hud.draw(m_window.getRenderWindow(), "HighScorePage");
        m_window.display();
    } else if (m_gameState.getState() == State::UpdateHighScorePage) {
        m_window.clear();
        m_background.draw(m_window.getRenderWindow());
        m_hud.draw(m_window.getRenderWindow(), "UpdateHighScorePage");
        m_window.display();
    } else if (m_gameState.getState() == State::OptionsPage) {
        m_window.clear();
        m_background.draw(m_window.getRenderWindow());
        m_options.drew();
        m_window.display();
    } else if (m_gameState.getState() == State::DifficultyPage) {
        m_window.clear();
        m_background.draw(m_window.getRenderWindow());
        m_difficulty.drew();
        m_window.display();
    } else if (m_gameState.getState() == State::VideoPage) {
        m_window.clear();
        m_background.draw(m_window.getRenderWindow());
        m_video.drew();
        m_window.display();
    } else if (m_gameState.getState() == State::ControlSettingPage) {
        m_window.clear();
        m_background.draw(m_window.getRenderWindow());
        m_controlSettingsMenu.draw();
        m_window.display();
    } else if (m_gameState.getState() == State::VolumePage) {
        m_window.clear();
        m_background.draw(m_window.getRenderWindow());
        m_volume.draw();
        m_window.display();
    }
}
