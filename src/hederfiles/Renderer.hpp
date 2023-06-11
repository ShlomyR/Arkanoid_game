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
class Options;
class Difficulty;
class Video;
class ControlSettingsMenu;
class VolumeManager;

class RendererImpl : public Renderer
{
public:
    RendererImpl(WindowManager &
        , GameState &
        , Menu &
        , Options &
        , Difficulty &
        , Video &
        , PhysicsManager &
        , Hud &
        , Paddle &
        , Ball &
        , Brick &
        , Border &
        , Background &
        , ControlSettingsMenu &
        , VolumeManager &
    );

    void render() override;
private:
    WindowManager &m_window;
    GameState &m_gameState;
    Menu &m_menu;
    Options &m_options;
    Difficulty &m_difficulty;
    Video &m_video;
    PhysicsManager &m_physicsManager;
    Hud &m_hud;
    Paddle &m_paddle;
    Ball &m_ball;
    Brick &m_brick;
    Border &m_border;
    Background &m_background;
    ControlSettingsMenu &m_controlSettingsMenu;
    VolumeManager &m_volume;
};