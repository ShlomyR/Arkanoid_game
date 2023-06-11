#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "VideoOption.hpp"
#include "GameState.hpp"

bool VideoOption::m_isMusicPlayed;

void VideoOption::draw(sf::RenderWindow& window)
{
    window.draw(m_videoText);
}

bool VideoOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_videoText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_videoText.setOutlineColor(sf::Color::Blue);
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
        m_videoText.setOutlineColor(sf::Color::White);
    }
    return false;
}


void VideoOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_videoText.setString("VIDEO");
    m_videoText.setFont(m_font);
    m_videoText.setCharacterSize(48);
    m_videoText.setFillColor(sf::Color::Green);
    m_videoText.setOutlineThickness(2);
    m_videoText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_videoText.getGlobalBounds().width / 2, window.getSize().y / 2 + 150);
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
        m_videoText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* VideoOption::getText()
{
    return &m_videoText;
}
