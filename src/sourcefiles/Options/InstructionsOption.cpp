#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "InstructionsOption.hpp"
#include "GameState.hpp"

bool InstructionsOption::m_isMusicPlayed;

void InstructionsOption::draw(sf::RenderWindow& window)
{
    window.draw(m_instructionsText);
}

bool InstructionsOption::handleInput(InputHandler& inputHandler, GameState &)
{
    // bool mouseHover = m_instructionsText.getGlobalBounds().contains(inputHandler.getMousePosition());
    bool mouseHover = false;
    if (mouseHover) {
        // m_instructionsText.setOutlineColor(sf::Color::Blue);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            // gameState.setState(State::InstructionsPage);
        
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        // m_instructionsText.setOutlineColor(sf::Color::White);
    }

    return false;
}


void InstructionsOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_instructionsText.setString("INSTRUCTIONS");
    m_instructionsText.setFont(m_font);
    m_instructionsText.setCharacterSize(48);
    m_instructionsText.setFillColor(sf::Color::Transparent);
    m_instructionsText.setOutlineThickness(2);
    m_instructionsText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_instructionsText.getGlobalBounds().width / 2, window.getSize().y / 2 + 50);
    m_instructionsText.setPosition(buttonPos);
}

bool InstructionsOption::isSelected() const
{
    return m_isSelected;
}

void InstructionsOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_instructionsText.setOutlineColor(sf::Color::Blue);
    } else {
        m_instructionsText.setOutlineColor(sf::Color::White);

    }
}

sf::Text* InstructionsOption::getText()
{
    return &m_instructionsText;
}
