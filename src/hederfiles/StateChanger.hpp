#pragma once

class GameStateUpdater;
enum class State;

class StateChanger {
public:
    StateChanger(GameStateUpdater &gameStateUpdater);

    void changeState(State newState);
private:
    GameStateUpdater &m_gameStateUpdater;
};


// // Create a GameStateUpdaterImpl instance
// GameStateUpdaterImpl gameStateUpdater;

// // Create a StateChanger instance and pass in the GameStateUpdaterImpl instance
// StateChanger stateChanger(gameStateUpdater);

// // Change the state to the menu page
// stateChanger.changeState(State::MenuPage);

// // Change the state to the play page
// stateChanger.changeState(State::PlayPage);

// // Change the state to the high score page
// stateChanger.changeState(State::HighScorePage);

// // Change the state to the update high score page
// stateChanger.changeState(State::UpdateHighScorePage);

// // Change the state to the game over page
// stateChanger.changeState(State::GameOver);



