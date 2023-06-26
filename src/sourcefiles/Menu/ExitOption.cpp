#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "ExitOption.hpp"
#include "GameState.hpp"

bool ExitOption::m_isMusicPlayed;

void ExitOption::draw(sf::RenderWindow& window)
{
    window.draw(m_exitText);
}

bool ExitOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_exitText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_exitText.setOutlineColor(sf::Color::Blue);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::Exit);
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_exitText.setOutlineColor(sf::Color::White);
    }
    
    return false;
}

void ExitOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_exitText.setString("EXIT");
    m_exitText.setFont(m_font);
    m_exitText.setCharacterSize(48);
    m_exitText.setFillColor(sf::Color::Green);
    m_exitText.setOutlineThickness(2);
    m_exitText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_exitText.getGlobalBounds().width / 2, window.getSize().y / 2 + 100);
    m_exitText.setPosition(buttonPos);
}

bool ExitOption::isSelected() const
{
    return m_isSelected;
}

void ExitOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_exitText.setOutlineColor(sf::Color::Blue);
    } else {
        m_exitText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* ExitOption::getText()
{
    return &m_exitText;
}