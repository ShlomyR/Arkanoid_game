#include "../hederfiles/MouseButton.hpp"
#include "../hederfiles/InputHandler.hpp"
#include "../hederfiles/GameState.hpp"
#include "../hederfiles/Menu.hpp"

MouseButton::MouseButton(sf::RenderWindow &window, Menu &menu, GameState &gameState)
: m_window(window)
, m_menu(menu)
, m_gameState(gameState)
{}

void MouseButton::left(bool const& value)
{
    m_menu.setIsMenuShown(value);
}
