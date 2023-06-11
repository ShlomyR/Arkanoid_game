#include "WindowArrowsKey.hpp"
#include "GameState.hpp"

WindowArrowsKey::WindowArrowsKey(sf::RenderWindow &window, GameState &gameState)
: m_window(window)
, m_gameState(gameState)
{

}

void up()
{
    // m_menu.up();
}

void down()
{
    // m_menu.down();
}

void WindowArrowsKey::escape()
{
    if (m_gameState.getState() == State::DifficultyPage) {
        m_gameState.setState(State::OptionsPage);
    } else if (m_gameState.getState() == State::OptionsPage) {
        m_gameState.setState(State::MenuPage);
    } else if (m_gameState.getState() == State::MenuPage) {
        m_window.close();
    } else if (m_gameState.getState() == State::ControlSettingPage) {
        m_gameState.setState(State::OptionsPage);
    } else if (m_gameState.getState() == State::VideoPage) {
        m_gameState.setState(State::OptionsPage);
    } else if (m_gameState.getState() != State::OptionsPage) {
        m_gameState.setState(State::MenuPage);
    }
}
