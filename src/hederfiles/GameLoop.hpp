#include "GameLoop.hxx"
#include "GameStateUpdater.hxx"
#include "Renderer.hxx"
#include "InputHandler.hxx"
#include "GameResetter.hxx"

class GameLoopImpl : public GameLoop {
public:
    GameLoopImpl(WindowManager &window, InputHandler &inputHandler, GameStateUpdater &m_gameStateUpdater, Renderer &m_renderer, GameResetter &gameResetter);
    void run() override;
private:
    WindowManager &m_window;
    InputHandler& m_inputHandler;
    GameStateUpdater& m_gameStateUpdater;
    Renderer& m_renderer;
    GameResetter &m_gameResetter;
};
