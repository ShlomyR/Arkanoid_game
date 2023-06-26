#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "ControlsOption.hpp"
#include "GameState.hpp"

bool ControlsOption::m_isMusicPlayed;

void ControlsOption::draw(sf::RenderWindow& window)
{
    window.draw(m_controlsText);
}

bool ControlsOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_controlsText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_controlsText.setOutlineColor(sf::Color::Blue);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::ControlSettingPage);
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_controlsText.setOutlineColor(sf::Color::White);
    }

    return false;
}


void ControlsOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_controlsText.setString("CONTROLS");
    m_controlsText.setFont(m_font);
    m_controlsText.setCharacterSize(48);
    m_controlsText.setFillColor(sf::Color::Green);
    m_controlsText.setOutlineThickness(2);
    m_controlsText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_controlsText.getGlobalBounds().width / 2, window.getSize().y / 2 - 150);
    m_controlsText.setPosition(buttonPos);
}

bool ControlsOption::isSelected() const
{
    return m_isSelected;
}

void ControlsOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_controlsText.setOutlineColor(sf::Color::Blue);
    } else {
        m_controlsText.setOutlineColor(sf::Color::White);

    }
}

sf::Text* ControlsOption::getText()
{
    return &m_controlsText;
}
