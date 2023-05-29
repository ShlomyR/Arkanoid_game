#pragma once

#include "GameResetter.hxx"
#include "BlockParser.hpp"

#include <memory>

class Brick;
class Paddle;
class WindowManager;
class GameState;

class GameResetterImpl : public GameResetter
{
public:
    GameResetterImpl(Brick &brick, Paddle &paddle,WindowManager &window, GameState &gameState);
    void resetGameOver() override;
    void reset() override;
private:
    Brick &m_brick;
    Paddle &m_paddle;
    WindowManager &m_window;
    GameState &m_gameState;
};
