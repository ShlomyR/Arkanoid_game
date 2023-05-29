#pragma once

#include "HighScoreManager.hpp"

#include <SFML/Graphics.hpp>
#include <string>


class GameState;

class Hud
{
public:
    Hud(sf::RenderWindow&);
    void update(GameState &);
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
