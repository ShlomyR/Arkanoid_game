#include "../hederfiles/HighScoreOption.hpp"
#include "../hederfiles/InputHandler.hpp"
#include "../hederfiles/GameState.hpp"

void HighScoreOption::draw(sf::RenderWindow &window)
{
    window.draw(m_highScoreText);   
}

bool HighScoreOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_highScoreText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_highScoreText.setOutlineColor(sf::Color::Red);
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::HighScorePage);
        
        }
    } else {
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
    m_highScoreText.setFillColor(sf::Color::White);
    m_highScoreText.setOutlineThickness(2);
    m_highScoreText.setOutlineColor(sf::Color::Black);
    m_highScoreText.setPosition(sf::Vector2f(window.getSize().x / 2 - m_highScoreText.getGlobalBounds().width / 2, window.getSize().y / 2 - 50));
}

bool HighScoreOption::isSelected() const
{

    return m_isSelected;
}

void HighScoreOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_highScoreText.setOutlineColor(sf::Color::Red);
    } else {
        m_highScoreText.setOutlineColor(sf::Color::White);

    }
}

sf::Text HighScoreOption::getText()
{
    return m_highScoreText;
}