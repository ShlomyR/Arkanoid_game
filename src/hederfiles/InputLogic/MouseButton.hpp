#pragma once

#include <SFML/Graphics.hpp>

class GameState;
class Menu;
class Options;
class Difficulty;
class Video;

class MouseButton
{
public:
    MouseButton(sf::RenderWindow &, Menu &, Options &, Difficulty &, Video &, GameState &);
    ~MouseButton() = default;
    void left(bool const&);
private:
    sf::RenderWindow &m_window;
    Menu &m_menu;
    Options &m_options;
    Difficulty &m_difficulty;
    Video &m_video;
    GameState &m_gameState;
};