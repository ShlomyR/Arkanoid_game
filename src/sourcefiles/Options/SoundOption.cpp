#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "SoundOption.hpp"
#include "GameState.hpp"

bool SoundOption::m_isMusicPlayed;

void SoundOption::draw(sf::RenderWindow& window)
{
    window.draw(m_soundText);
}

bool SoundOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_soundText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_soundText.setOutlineColor(sf::Color::Blue);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::VolumePage);
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_soundText.setOutlineColor(sf::Color::White);
    }

    return false;
}


void SoundOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_soundText.setString("SOUND");
    m_soundText.setFont(m_font);
    m_soundText.setCharacterSize(48);
    m_soundText.setFillColor(sf::Color::Green);
    m_soundText.setOutlineThickness(2);
    m_soundText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_soundText.getGlobalBounds().width / 2, window.getSize().y / 2 - 250);
    m_soundText.setPosition(buttonPos);
}

bool SoundOption::isSelected() const
{
    return m_isSelected;
}

void SoundOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_soundText.setOutlineColor(sf::Color::Blue);
    } else {
        m_soundText.setOutlineColor(sf::Color::White);

    }
}

sf::Text* SoundOption::getText()
{
    return &m_soundText;
}
