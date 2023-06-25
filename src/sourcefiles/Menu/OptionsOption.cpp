#include "InputHandlerImpl.hpp"
#include "OptionsOption.hpp"
#include "SoundManager.hpp"
#include "GameState.hpp"

bool OptionsOption::m_isMusicPlayed;

void OptionsOption::draw(sf::RenderWindow& window)
{
    window.draw(m_optionsText);
}

void OptionsOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void OptionsOption::updateColor(sf::Text &text, sf::Color color)
{
    text.setOutlineColor(color);
    text.setFillColor(color);
}

bool OptionsOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    auto color = sf::Color{ 128,128,128 };
    bool mouseHover = m_optionsText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (sf::Joystick::isConnected(0)) {
        m_mouseCurser = false;
        gameState.getWindow().getRenderWindow().setMouseCursorVisible(false);
        if (m_optionsText.getFillColor() == sf::Color::White) {
            updateColor(m_optionsText, sf::Color::White);
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
        }
    } else {
        m_mouseCurser = true;
    }
    if (mouseHover && m_mouseCurser) {
        updateColor(m_optionsText, sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::OptionsPage);
        }
    } else if (m_mouseCurser) {
        m_isMusicPlayed = false;
        setIsSelected(false);
        updateColor(m_optionsText, color);
    }
    
    return false;
}

void OptionsOption::makeButton(sf::RenderWindow& window)
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_optionsText.setString("OPTIONS");
    m_optionsText.setFont(m_font);
    m_optionsText.setCharacterSize(48);
    m_optionsText.setScale(0.5,0.5);
    m_optionsText.setFillColor(color);
    m_optionsText.setOutlineThickness(2);
    m_optionsText.setOutlineColor(color);
    sf::Vector2f buttonPos = sf::Vector2f((window.getSize().x - window.getSize().x) + 350, window.getSize().y / 2 + 50);
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
        m_optionsText.setOutlineColor(sf::Color{ 128,128,128 });
    }
}

sf::Text* OptionsOption::getText()
{
    return &m_optionsText;
}
