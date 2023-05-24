#pragma once

#include <SFML/Graphics.hpp>

class GameState;

class WindowArrowsKey
{
public:
    WindowArrowsKey(sf::RenderWindow &window, GameState &gameState);
    ~WindowArrowsKey() = default;

    void escape();
private:
    sf::RenderWindow &m_window;
    GameState &m_gameState;
};
