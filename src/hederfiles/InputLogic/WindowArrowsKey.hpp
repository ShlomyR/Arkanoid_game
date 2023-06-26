#pragma once

#include "MenuOption.hxx"

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <memory>

class GameState;

class WindowArrowsKey
{
public:
    WindowArrowsKey(sf::RenderWindow &, GameState &);
    ~WindowArrowsKey() = default;

    void up();
    void down();
    void enter();
    void escape();
private:
    sf::RenderWindow &m_window;
    GameState &m_gameState;
    std::string currPage;
    int m_currMenu;
    int m_maxIndexMenu;
    std::vector<sf::Color> m_menuColors;
    int m_currVideo;
    int m_maxIndexVideo;
    std::vector<sf::Color> m_videoColors;
    int m_currOptions;
    int m_maxIndexOptions;
    std::vector<sf::Color> m_optionsColors;
    std::unordered_map<std::string,std::vector<std::shared_ptr<MenuOption>>> m_map;
};