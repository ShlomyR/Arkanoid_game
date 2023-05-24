#pragma once

#include <SFML/Graphics.hpp>

class GameState;
class Menu;

class MouseButton
{
public:
    MouseButton(sf::RenderWindow &window, Menu &menu, GameState &gameState);
    ~MouseButton() = default;
    void left(bool const&);
private:
    sf::RenderWindow &m_window;
    Menu &m_menu;
    GameState &m_gameState;
};
