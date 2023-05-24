#pragma once

enum class State;

class GameStateUpdater {
public:
    virtual ~GameStateUpdater() = default;
    virtual void update() = 0;
    virtual bool gameOver() const = 0;
    virtual void updateState() = 0;
    virtual void setGameState(State) = 0;
};
