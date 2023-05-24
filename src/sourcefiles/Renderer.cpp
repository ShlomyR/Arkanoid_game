#include "../hederfiles/Renderer.hpp"
#include "../hederfiles/PhysicsManager.hpp"
#include "../hederfiles/Hud.hpp"
#include "../hederfiles/Paddle.hpp"
#include "../hederfiles/Ball.hpp"
#include "../hederfiles/Brick.hpp"
#include "../hederfiles/Border.hpp"

RendererImpl::RendererImpl(WindowManager &window, GameState &gameState, Menu &menu,PhysicsManager &physicsManager, Hud &hud, Paddle &paddle, Ball &ball, Brick &brick, Border &border)
: m_window(window)
, m_gameState(gameState)
, m_menu(menu)
, m_physicsManager(physicsManager)
, m_hud(hud)
, m_paddle(paddle)
, m_ball(ball)
, m_brick(brick)
, m_border(border)
{}

void RendererImpl::render()
{
    if (m_gameState.getState() == State::MenuPage) {
        m_window.clear();
        m_menu.drew();
        m_window.display();
    } else if (m_gameState.getState() == State::PlayPage) {
        m_window.clear();
        m_border.draw(m_window.getRenderWindow());
        m_brick.draw(m_window.getRenderWindow());
        m_ball.draw(m_window.getRenderWindow());
        m_hud.draw(m_window.getRenderWindow(), "PlayPage");
        m_paddle.draw(m_window.getRenderWindow());
        m_window.display();
    } else if (m_gameState.getState() == State::HighScorePage) {
        m_window.clear();
        m_hud.draw(m_window.getRenderWindow(), "HighScorePage");
        m_window.display();
    } else if (m_gameState.getState() == State::UpdateHighScorePage) {
        m_window.clear();
        m_hud.draw(m_window.getRenderWindow(), "UpdateHighScorePage");
        m_window.display();
    } else if (m_gameState.getState() == State::Exit) {
        m_window.clear();
        //m_exit.render();
        m_window.display();
    } 
}
