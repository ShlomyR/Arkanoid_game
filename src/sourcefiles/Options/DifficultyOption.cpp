#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "DifficultyOption.hpp"
#include "GameState.hpp"

bool DifficultyOption::m_isMusicPlayed;

void DifficultyOption::draw(sf::RenderWindow& window)
{
    window.draw(m_difficultyText);
}

void DifficultyOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void DifficultyOption::updateColor(sf::Text &text, sf::Color color)
{
    text.setOutlineColor(color);
    text.setFillColor(color);
}

bool DifficultyOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    auto color = sf::Color{ 128,128,128 };
    bool mouseHover = m_difficultyText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (sf::Joystick::isConnected(0)) {
        m_mouseCurser = false;
        gameState.getWindow().getRenderWindow().setMouseCursorVisible(false);
        if (m_difficultyText.getFillColor() == sf::Color::White) {
            updateColor(m_difficultyText, sf::Color::White);
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
        }
    } else {
        m_mouseCurser = true;
    }
    if (mouseHover && m_mouseCurser) {
        updateColor(m_difficultyText, sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::DifficultyPage);
        }
    } else if (m_mouseCurser) {
        m_isMusicPlayed = false;
        setIsSelected(false);
        updateColor(m_difficultyText, color);
    }

    return false;
}


void DifficultyOption::makeButton(sf::RenderWindow&)
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_difficultyText.setString("DIFFICULTY");
    m_difficultyText.setFont(m_font);
    m_difficultyText.setCharacterSize(48);
    m_difficultyText.setFillColor(color);
    m_difficultyText.setOutlineThickness(2);
    m_difficultyText.setScale(0.5,0.5);
    m_difficultyText.setOutlineColor(color);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 200));
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
        m_difficultyText.setOutlineColor(sf::Color{ 128,128,128 });
    }
}

sf::Text* DifficultyOption::getText()
{
    return &m_difficultyText;
}
