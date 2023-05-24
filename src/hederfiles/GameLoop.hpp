#include "../hederfiles/GameLoop.hxx"

#include "../hederfiles/GameStateUpdater.hxx"
#include "../hederfiles/Renderer.hxx"
#include "../hederfiles/InputHandler.hxx"
#include "../hederfiles/GameResetter.hxx"

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
