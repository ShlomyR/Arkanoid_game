#include "HighScoreOption.hpp"
#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "GameState.hpp"

bool HighScoreOption::m_isMusicPlayed;

void HighScoreOption::draw(sf::RenderWindow &window)
{
    window.draw(m_highScoreText);   
}

bool HighScoreOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_highScoreText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_highScoreText.setOutlineColor(sf::Color::Blue);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::HighScorePage);
        
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_highScoreText.setOutlineColor(sf::Color::White);
    }
    
    return false;
}

void HighScoreOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_highScoreText.setString("HIGH SCORE");
    m_highScoreText.setFont(m_font);
    m_highScoreText.setCharacterSize(48);
    m_highScoreText.setFillColor(sf::Color::Green);
    m_highScoreText.setOutlineThickness(2);
    m_highScoreText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_highScoreText.getGlobalBounds().width / 2, window.getSize().y / 2 - 100);
    m_highScoreText.setPosition(buttonPos);
}

bool HighScoreOption::isSelected() const
{

    return m_isSelected;
}

void HighScoreOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_highScoreText.setOutlineColor(sf::Color::Blue);
    } else {
        m_highScoreText.setOutlineColor(sf::Color::White);

    }
}

sf::Text* HighScoreOption::getText()
{
    return &m_highScoreText;
}
