#include "Hud.hpp"
#include "HighScoreManager.hpp"
#include "GameState.hpp"

Hud::Hud(sf::RenderWindow& window)
: m_window(window)
, m_highScoreManager()
{
    if (!m_font.loadFromFile("src/fonts/DIN_Bold.ttf")) {
        throw std::runtime_error("Could not load the font!!!");
    }
    makeText(m_scoreText, m_font, "NONE", sf::Vector2i(10, 10));
    makeText(m_healthText, m_font, "NONE", sf::Vector2i(window.getSize().x -150, 10));
    makeText(m_gameOverText, m_font, "NONE", sf::Vector2i(window.getSize().x / 2.f, window.getSize().y / 2.f));
    makeText(m_highScoreText, m_font, "NONE", sf::Vector2i(window.getSize().x - 500, 10));
    makeText(m_highScoreNamesText, m_font, "NONE", sf::Vector2i(200, 300));
    makeText(m_highScoreScoresText, m_font, "NONE", sf::Vector2i(700, 300));
    makeText(m_highScoreInputText, m_font, "NONE", sf::Vector2i(300, 200));
    makeText(m_inputText, m_font, name, sf::Vector2i(370, 245));
}

void Hud::update(GameState &gameState)
{
    m_scoreText.setString("Score: " + std::to_string(gameState.getScore()));
    m_healthText.setString("Health: " + std::to_string(gameState.getHealth()));
    m_highScoreText.setString("High Score: " + std::to_string(gameState.getHighScore()));
    m_highScoreManager.scoreNameTextLogic(m_highScoreNamesText);
    m_highScoreManager.scoreScoresTextLogic(m_highScoreScoresText);
    m_highScoreManager.updateInputTextLogic(m_highScoreInputText);
}

void Hud::draw(sf::RenderWindow &window,std::string currentState)
{
    if (currentState == "PlayPage") {
        window.draw(m_scoreText);
        window.draw(m_healthText);
        window.draw(m_highScoreText);
    } else if (currentState == "HighScorePage") {
        window.draw(m_highScoreNamesText);
        window.draw(m_highScoreScoresText);
    } else if (currentState == "UpdateHighScorePage") {
        window.draw(m_highScoreNamesText);
        window.draw(m_highScoreScoresText);
        window.draw(m_highScoreInputText);   
        window.draw(m_inputText);
    } else {
        
    }
}

std::string &Hud::getName()
{
    return name;
}

sf::Text &Hud::getInputText()
{
    return m_inputText;
}

HighScoreManager &Hud::getHighScoreManager()
{
    return m_highScoreManager;
}

void Hud::makeText(sf::Text &text, sf::Font &font, std::string str, sf::Vector2i vec2i)
{
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setString(str);
    text.setPosition(vec2i.x,vec2i.y);
}

void Hud::updateResoloution(const sf::Vector2u &windowSize)
{
    m_scoreText.setPosition(10, 10);
    m_healthText.setPosition(windowSize.x -150, 10);
    m_highScoreText.setPosition(windowSize.x/2 - 80, 10);
}
