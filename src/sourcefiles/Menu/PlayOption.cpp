#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "PlayOption.hpp"
#include "GameState.hpp"

bool PlayOption::m_isMusicPlayed;

void PlayOption::draw(sf::RenderWindow& window)
{
    window.draw(m_playText);
}

bool PlayOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_playText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_playText.setOutlineColor(sf::Color::Blue);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            setIsSelected(false);
            gameState.setState(State::PlayPage);
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_playText.setOutlineColor(sf::Color::White);
    }

    return false;
}


void PlayOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_playText.setString("PLAY");
    m_playText.setFont(m_font);
    m_playText.setCharacterSize(48);
    m_playText.setFillColor(sf::Color::Green);
    m_playText.setOutlineThickness(2);
    m_playText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_playText.getGlobalBounds().width / 2, window.getSize().y / 2 - 200);
    m_playText.setPosition(buttonPos);
}

bool PlayOption::isSelected() const
{
    return m_isSelected;
}

void PlayOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_playText.setOutlineColor(sf::Color::Blue);
    } else {
        m_playText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* PlayOption::getText()
{
    return &m_playText;
}
