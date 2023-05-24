#include "../hederfiles/Hud.hpp"
#include "../hederfiles/HighScoreManager.hpp"
#include "../hederfiles/GameState.hpp"
#include "Hud.hpp"

void Hud::update(int score, int health, int highScore, GameState &gameState)
{
    m_scoreText.setString("Score: " + std::to_string(score));
    m_healthText.setString("Health: " + std::to_string(health));
    m_highScoreText.setString("High Score: " + std::to_string(highScore));
    m_highScoreManager.scoreNameTextLogic(m_highScoreNamesText);
    m_highScoreManager.scoreScoresTextLogic(m_highScoreScoresText);
    m_highScoreManager.updateInputTextLogic(m_highScoreInputText);
    if (gameState.getScore() < gameState.getHighScore()) {
        gameState.setHighScore(m_highScoreManager.getFirstHighScore());
    } else {
        gameState.setHighScore(gameState.getScore());
    }
    if (gameState.getHealth() == 0) {
        if (gameState.getScore() != gameState.getHighScore()) {
            gameState.setState(State::GameOver);
        } else {
            gameState.setState(State::UpdateHighScorePage);
        }
    }
    
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
    } else if (currentState == "game over") {
        
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