#include "../hederfiles/WindowArrowsKey.hpp"
#include "../hederfiles/GameState.hpp"

WindowArrowsKey::WindowArrowsKey(sf::RenderWindow &window, GameState &gameState)
: m_window(window)
, m_gameState(gameState)
{

}

void WindowArrowsKey::escape()
{
    if (m_gameState.getState() != State::MenuPage) {
        m_gameState.setState(State::MenuPage);
    } else {
        m_window.close(); 
    }
}