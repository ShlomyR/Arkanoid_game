#include "StateChanger.hpp"
#include "GameStateUpdaterImpl.hpp"

StateChanger::StateChanger(GameStateUpdater &gameStateUpdater)
: m_gameStateUpdater(gameStateUpdater)
{}

void StateChanger::changeState(State newState)
{
    if (newState == State::MenuPage) {
        //m_gameStateUpdater.reset();
        m_gameStateUpdater.setGameState(State::MenuPage);
    } else if (newState == State::PlayPage) {
        //m_gameStateUpdater.reset();
        m_gameStateUpdater.setGameState(State::PlayPage);
    } else if (newState == State::HighScorePage) {
        //m_gameStateUpdater.reset();
        m_gameStateUpdater.setGameState(State::HighScorePage);
    } else if (newState == State::UpdateHighScorePage) {
        //m_gameStateUpdater.reset();
        m_gameStateUpdater.setGameState(State::UpdateHighScorePage);
    } else if (newState == State::BrickEmpty) {
        //m_gameStateUpdater.reset();
        m_gameStateUpdater.setGameState(State::BrickEmpty);
    } else if (newState == State::BallOutOfBounds) {
        //m_gameStateUpdater.reset();
        m_gameStateUpdater.setGameState(State::BallOutOfBounds);
    } else if (newState == State::NoHealth) {
        //m_gameStateUpdater.reset();
        m_gameStateUpdater.setGameState(State::NoHealth);
    } else {
        throw std::runtime_error("The state is not exist");
    }
}
