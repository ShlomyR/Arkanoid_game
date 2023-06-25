#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "ExitOption.hpp"
#include "GameState.hpp"

bool ExitOption::m_isMusicPlayed;

void ExitOption::draw(sf::RenderWindow& window)
{
    window.draw(m_exitText);
}

void ExitOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void ExitOption::updateColor(sf::Text &text, sf::Color color)
{
    text.setOutlineColor(color);
    text.setFillColor(color);
}

bool ExitOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    auto color = sf::Color{ 128,128,128 };
    bool mouseHover = m_exitText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (sf::Joystick::isConnected(0)) {
        m_mouseCurser = false;
        gameState.getWindow().getRenderWindow().setMouseCursorVisible(false);
        if (m_exitText.getFillColor() == sf::Color::White) {
            updateColor(m_exitText, sf::Color::White);
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
        }
    } else {
        m_mouseCurser = true;
    }
    if (mouseHover && m_mouseCurser) {
        updateColor(m_exitText, sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::Exit);
        }
    } else if (m_mouseCurser) {
        m_isMusicPlayed = false;
        setIsSelected(false);
        updateColor(m_exitText, color);
    }
    
    return false;
}

void ExitOption::makeButton(sf::RenderWindow& window)
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_exitText.setString("EXIT");
    m_exitText.setFont(m_font);
    m_exitText.setScale(0.5,0.5);
    m_exitText.setCharacterSize(48);
    m_exitText.setFillColor(color);
    m_exitText.setOutlineThickness(2);
    m_exitText.setOutlineColor(color);
    sf::Vector2f buttonPos = sf::Vector2f((window.getSize().x - window.getSize().x) + 350, window.getSize().y / 2 + 100);
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
        m_exitText.setOutlineColor(sf::Color{ 128,128,128 });
    }
}

sf::Text* ExitOption::getText()
{
    return &m_exitText;
}