#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "SoundOption.hpp"
#include "GameState.hpp"

bool SoundOption::m_isMusicPlayed;

void SoundOption::draw(sf::RenderWindow& window)
{
    window.draw(m_soundText);
}

void SoundOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void SoundOption::updateColor(sf::Text &text, sf::Color color)
{
    text.setOutlineColor(color);
    text.setFillColor(color);
}

bool SoundOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    auto color = sf::Color{ 128,128,128 };
    bool mouseHover = m_soundText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (sf::Joystick::isConnected(0)) {
        m_mouseCurser = false;
        gameState.getWindow().getRenderWindow().setMouseCursorVisible(false);
        if (m_soundText.getFillColor() == sf::Color::White) {
            updateColor(m_soundText, sf::Color::White);
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
        }
    } else {
        m_mouseCurser = true;
    }
    if (mouseHover && m_mouseCurser) {
        updateColor(m_soundText, sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::VolumePage);
        }
    } else if (m_mouseCurser) {
        m_isMusicPlayed = false;
        setIsSelected(false);
        updateColor(m_soundText, color);
    }

    return false;
}


void SoundOption::makeButton(sf::RenderWindow&)
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_soundText.setString("SOUND");
    m_soundText.setFont(m_font);
    m_soundText.setCharacterSize(48);
    m_soundText.setFillColor(color);
    m_soundText.setOutlineThickness(2);
    m_soundText.setOutlineColor(color);
    m_soundText.setScale(0.5,0.5);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 150));
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
        m_soundText.setOutlineColor(sf::Color{ 128,128,128 });

    }
}

sf::Text* SoundOption::getText()
{
    return &m_soundText;
}
