#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "ControlsOption.hpp"
#include "GameState.hpp"
#include "MenuScreenHandler.hpp"

bool ControlsOption::m_isMusicPlayed;

void ControlsOption::draw(sf::RenderWindow& window)
{
    window.draw(m_controlsText);
}

void ControlsOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void ControlsOption::updateColor(sf::Text &text, sf::Color color)
{
    text.setOutlineColor(color);
    text.setFillColor(color);
}

bool ControlsOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    auto color = sf::Color{ 128,128,128 };
    bool mouseHover = m_controlsText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (sf::Joystick::isConnected(0)) {
        m_mouseCurser = false;
        gameState.getWindow().getRenderWindow().setMouseCursorVisible(false);
        if (m_controlsText.getFillColor() == sf::Color::White) {
            updateColor(m_controlsText, sf::Color::White);
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
        }
    } else {
        m_mouseCurser = true;
    }
    if (mouseHover && m_mouseCurser) {
        updateColor(m_controlsText, sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::ControlSettingPage);
        }
    } else if (m_mouseCurser) {
        m_isMusicPlayed = false;
        setIsSelected(false);
        updateColor(m_controlsText, color);
    }

    return false;
}


void ControlsOption::makeButton(sf::RenderWindow& )
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_controlsText.setString("CONTROLS");
    m_controlsText.setFont(m_font);
    m_controlsText.setCharacterSize(48);
    m_controlsText.setFillColor(color);
    m_controlsText.setScale(0.5,0.5);
    m_controlsText.setOutlineThickness(2);
    m_controlsText.setOutlineColor(color);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 100));
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
        m_controlsText.setOutlineColor(sf::Color{ 128,128,128 });

    }
}

sf::Text* ControlsOption::getText()
{
    return &m_controlsText;
}
