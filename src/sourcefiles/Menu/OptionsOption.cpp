#include "InputHandlerImpl.hpp"
#include "OptionsOption.hpp"
#include "SoundManager.hpp"
#include "GameState.hpp"

bool OptionsOption::m_isMusicPlayed;

void OptionsOption::draw(sf::RenderWindow& window)
{
    window.draw(m_optionsText);
}

bool OptionsOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_optionsText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_optionsText.setOutlineColor(sf::Color::Blue);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::OptionsPage);
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_optionsText.setOutlineColor(sf::Color::White);
    }
    
    return false;
}

void OptionsOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_optionsText.setString("OPTIONS");
    m_optionsText.setFont(m_font);
    m_optionsText.setCharacterSize(48);
    m_optionsText.setFillColor(sf::Color::Green);
    m_optionsText.setOutlineThickness(2);
    m_optionsText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_optionsText.getGlobalBounds().width / 2, window.getSize().y / 2);
    m_optionsText.setPosition(buttonPos);
}

bool OptionsOption::isSelected() const
{
    return m_isSelected;
}

void OptionsOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_optionsText.setOutlineColor(sf::Color::Blue);
    } else {
        m_optionsText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* OptionsOption::getText()
{
    return &m_optionsText;
}
