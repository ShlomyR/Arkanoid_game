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
    void right();
    void left();
    void escape();

    void highlightFirstWordInPage();
private:
    void init();
    void initVars();
    void initMap();
    void handelUp(int&, int, std::vector<sf::Color>&, std::string);
    void handelRight(int &, int, std::vector<sf::Color>&);
    void handelLeft(int &, int, std::vector<sf::Color>&);
    void handelDown(int&, int, std::vector<sf::Color>&, std::string);
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
    int m_currVolume;
    int m_maxIndexVolume;
    std::vector<sf::Color> m_volumeColors;
    int m_currDifficulty;
    int m_maxIndexDifficulty;
    std::vector<sf::Color> m_difficultyColors;

    std::unordered_map<std::string,std::vector<std::shared_ptr<MenuOption>>> m_map;
    // std::vector<sf::Text> m_texts;
};