#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "VideoOption.hpp"
#include "GameState.hpp"

bool VideoOption::m_isMusicPlayed;

void VideoOption::draw(sf::RenderWindow& window)
{
    window.draw(m_videoText);
}

void VideoOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void VideoOption::updateColor(sf::Text &text, sf::Color color)
{
    text.setOutlineColor(color);
    text.setFillColor(color);
}

bool VideoOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    auto color = sf::Color{ 128,128,128 };
    bool mouseHover = m_videoText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (sf::Joystick::isConnected(0)) {
        m_mouseCurser = false;
        gameState.getWindow().getRenderWindow().setMouseCursorVisible(false);
        if (m_videoText.getFillColor() == sf::Color::White) {
            updateColor(m_videoText, sf::Color::White);
            if (!m_isMusicPlayed) {
                SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
                m_isMusicPlayed = true;
            }
            if (m_isSelected) {
                m_isSelected = false;
                gameState.setState(State::VideoPage);
            }
        } else {
            m_isMusicPlayed = false;
            setIsSelected(false);
        }
    } else {
        m_mouseCurser = true;
    }
    if (mouseHover && m_mouseCurser) {
        updateColor(m_videoText, sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::VideoPage);
        }
    } else if (m_mouseCurser) {
        m_isMusicPlayed = false;
        setIsSelected(false);
        updateColor(m_videoText, color);
    }
    return false;
}


void VideoOption::makeButton(sf::RenderWindow&)
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_videoText.setString("VIDEO");
    m_videoText.setFont(m_font);
    m_videoText.setCharacterSize(48);
    m_videoText.setFillColor(color);
    m_videoText.setOutlineThickness(2);
    m_videoText.setOutlineColor(color);
    m_videoText.setScale(0.5,0.5);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 250));
    m_videoText.setPosition(buttonPos);
}

bool VideoOption::isSelected() const
{
    return m_isSelected;
}

void VideoOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_videoText.setOutlineColor(sf::Color::Blue);
    } else {
        m_videoText.setOutlineColor(sf::Color{ 128,128,128 });
    }
}

sf::Text* VideoOption::getText()
{
    return &m_videoText;
}
