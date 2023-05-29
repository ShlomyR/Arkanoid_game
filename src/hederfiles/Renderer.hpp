#include "Renderer.hxx"
#include "GameState.hpp"
#include "Menu.hpp"

class PhysicsManager;
class Hud;
class Paddle;
class Ball;
class Brick;
class Border;
class Background;

class RendererImpl : public Renderer
{
public:
    RendererImpl(WindowManager &
        , GameState &
        , Menu &
        , PhysicsManager &
        , Hud &
        , Paddle &
        , Ball &
        , Brick &
        , Border &
        , Background &
    );

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
    Background &m_background;
};