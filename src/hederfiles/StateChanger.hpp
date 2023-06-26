#pragma once

class GameStateUpdater;
enum class State;

class StateChanger
{
public:
    StateChanger(GameStateUpdater &gameStateUpdater);

    void changeState(State newState);
private:
    GameStateUpdater &m_gameStateUpdater;
};
