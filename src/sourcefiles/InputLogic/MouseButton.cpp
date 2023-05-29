#include "MouseButton.hpp"
#include "InputHandlerImpl.hpp"
#include "GameState.hpp"
#include "Menu.hpp"

MouseButton::MouseButton(sf::RenderWindow &window, Menu &menu, GameState &gameState)
: m_window(window)
, m_menu(menu)
, m_gameState(gameState)
{}

void MouseButton::left(bool const& value)
{
    m_menu.setIsMenuShown(value);
}
