#include "Renderer.hxx"
#include "GameState.hpp"
#include "Menu.hpp"

class PhysicsManager;
class Hud;
class Paddle;
class Ball;
class Brick;
class Border;

class RendererImpl : public Renderer {
public:
    RendererImpl(WindowManager &window,GameState &gameState,Menu &menu,PhysicsManager &physicsManager, Hud &hud, Paddle &paddle, Ball &ball, Brick &brick, Border &border);
    void render() override;
private:
    WindowManager &m_window;
    GameState &m_gameState;
    Menu &m_menu;
    PhysicsManager &m_physicsManager;
    Hud &m_hud;
    Paddle &m_paddle;
    Ball &m_ball;
    Brick &m_brick;
    Border &m_border;
};