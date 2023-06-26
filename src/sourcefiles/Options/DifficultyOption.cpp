#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "DifficultyOption.hpp"
#include "GameState.hpp"

bool DifficultyOption::m_isMusicPlayed;

void DifficultyOption::draw(sf::RenderWindow& window)
{
    window.draw(m_difficultyText);
}

bool DifficultyOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_difficultyText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_difficultyText.setOutlineColor(sf::Color::Blue);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::DifficultyPage);
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_difficultyText.setOutlineColor(sf::Color::White);
    }

    return false;
}


void DifficultyOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_difficultyText.setString("DIFFICULTY");
    m_difficultyText.setFont(m_font);
    m_difficultyText.setCharacterSize(48);
    m_difficultyText.setFillColor(sf::Color::Green);
    m_difficultyText.setOutlineThickness(2);
    m_difficultyText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_difficultyText.getGlobalBounds().width / 2, window.getSize().y / 2 - 50);
    m_difficultyText.setPosition(buttonPos);
}

bool DifficultyOption::isSelected() const
{
    return m_isSelected;
}

void DifficultyOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_difficultyText.setOutlineColor(sf::Color::Blue);
    } else {
        m_difficultyText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* DifficultyOption::getText()
{
    return &m_difficultyText;
}
