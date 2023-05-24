#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "HighScoreManager.hpp"

class GameState;

class Hud {
public:
    Hud(sf::RenderWindow& window)
    : m_window(window)
    , m_highScoreManager()
    {
        if (!m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf")) {
            throw std::runtime_error("Could not load the font!!!");
        }
        makeText(m_scoreText, m_font, "NONE", sf::Vector2i(10, 10));
        makeText(m_healthText, m_font, "NONE", sf::Vector2i(window.getSize().x -150, 10));
        makeText(m_gameOverText, m_font, "NONE", sf::Vector2i(window.getSize().x / 2.f, window.getSize().y / 2.f));
        makeText(m_highScoreText, m_font, "NONE", sf::Vector2i(window.getSize().x - 500, 10));
        makeText(m_highScoreNamesText, m_font, "NONE", sf::Vector2i(100, 150));
        makeText(m_highScoreScoresText, m_font, "NONE", sf::Vector2i(600, 150));
        makeText(m_highScoreInputText, m_font, "NONE", sf::Vector2i(250, 20));
        makeText(m_inputText, m_font, name, sf::Vector2i(350, 45));
    }

    void update(int, int, int, GameState &);
    void draw(sf::RenderWindow &, std::string);
    std::string &getName();
    std::string &getHighScoreInputText();
    sf::Text &getInputText();
    HighScoreManager &getHighScoreManager();

private:
    void makeText(sf::Text&,sf::Font&,std::string,sf::Vector2i);
private:
    sf::RenderWindow& m_window;
    sf::Font m_font;
    sf::Text m_scoreText;
    sf::Text m_healthText;
    sf::Text m_gameOverText;
    sf::Text m_highScoreText;

    sf::Text m_highScoreNamesText;
    sf::Text m_highScoreScoresText;
    sf::Text m_highScoreInputText;

    std::string name;
    sf::Text m_inputText;

    HighScoreManager m_highScoreManager;
};
