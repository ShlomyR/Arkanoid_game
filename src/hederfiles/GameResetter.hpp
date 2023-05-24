#pragma once

#include "../hederfiles/GameResetter.hxx"

class Brick;
class Paddle;
class WindowManager;
class GameState;

#include "BlockParser.hpp"

#include <memory>

class GameResetterImpl : public GameResetter {
public:
    GameResetterImpl(Brick &brick, Paddle &paddle,WindowManager &window, GameState &gameState);

    void resetGameOver() override;
    void reset() override;

private:
    Brick &m_brick;
    Paddle &m_paddle;
    WindowManager &m_window;
    GameState &m_gameState;
    BlockParser m_blockParser;
};
