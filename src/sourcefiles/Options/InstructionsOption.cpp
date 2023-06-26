#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "InstructionsOption.hpp"
#include "GameState.hpp"

bool InstructionsOption::m_isMusicPlayed;

void InstructionsOption::draw(sf::RenderWindow& window)
{
    window.draw(m_instructionsText);
}

void InstructionsOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void InstructionsOption::updateColor(sf::Text &text, sf::Color color)
{
    text.setOutlineColor(color);
    text.setFillColor(color);
}


bool InstructionsOption::handleInput(InputHandler &, GameState &gameState)
{
    // auto color = sf::Color{ 128,128,128 };
    // bool mouseHover = m_instructionsText.getGlobalBounds().contains(inputHandler.getMousePosition());
    bool mouseHover = false;
    if (sf::Joystick::isConnected(0)) {
        m_mouseCurser = false;
        gameState.getWindow().getRenderWindow().setMouseCursorVisible(false);
        if (m_instructionsText.getFillColor() == sf::Color::White) {
            // updateColor(m_instructionsText, sf::Color::White);
            if (!m_isMusicPlayed) {
                SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
                m_isMusicPlayed = true;
            }
            if (m_isSelected) {
                m_isSelected = false;
            }
        } else {
            m_isMusicPlayed = false;
            setIsSelected(false);
        }
    } else {
        m_mouseCurser = true;
    }
    if (mouseHover && m_mouseCurser) {
        // updateColor(m_instructionsText, sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            
        }
    } else if (m_mouseCurser) {
        m_isMusicPlayed = false;
        setIsSelected(false);
        // updateColor(m_instructionsText, color);
    }

    return false;
}


void InstructionsOption::makeButton(sf::RenderWindow&)
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_instructionsText.setString("INSTRUCTIONS");
    m_instructionsText.setFont(m_font);
    m_instructionsText.setCharacterSize(48);
    m_instructionsText.setFillColor(color);
    m_instructionsText.setOutlineThickness(2);
    m_instructionsText.setOutlineColor(color);
    m_instructionsText.setScale(0.5,0.5);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 300));
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
