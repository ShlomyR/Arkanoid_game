#include "HighScoreOption.hpp"
#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "GameState.hpp"

bool HighScoreOption::m_isMusicPlayed;

void HighScoreOption::draw(sf::RenderWindow &window)
{
    window.draw(m_highScoreText);   
}

void HighScoreOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void HighScoreOption::updateColor(sf::Text &text, sf::Color color)
{
    text.setOutlineColor(color);
    text.setFillColor(color);
}

bool HighScoreOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    auto color = sf::Color{ 128,128,128 };
    bool mouseHover = m_highScoreText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (sf::Joystick::isConnected(0)) {
        m_mouseCurser = false;
        gameState.getWindow().getRenderWindow().setMouseCursorVisible(false);
        if (m_highScoreText.getFillColor() == sf::Color::White)
        {
            updateColor(m_highScoreText, sf::Color::White);
            if (!m_isMusicPlayed) {
                SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
                m_isMusicPlayed = true;
            }
            if (m_isSelected) {
                m_isSelected = false;
                gameState.setState(State::HighScorePage);
            }
        } else {
            m_isMusicPlayed = false;
            setIsSelected(false);
        }
    } else {
        m_mouseCurser = true;
    }
    if (mouseHover && m_mouseCurser) {
        updateColor(m_highScoreText, sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::HighScorePage);
        
        }
    } else if (m_mouseCurser) {
        m_isMusicPlayed = false;
        setIsSelected(false);
        updateColor(m_highScoreText, color);
    }
    
    return false;
}

void HighScoreOption::makeButton(sf::RenderWindow& window)
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_highScoreText.setString("HIGH SCORE");
    m_highScoreText.setFont(m_font);
    m_highScoreText.setCharacterSize(48);
    m_highScoreText.setScale(0.5,0.5);
    m_highScoreText.setFillColor(color);
    m_highScoreText.setOutlineThickness(2);
    m_highScoreText.setOutlineColor(color);
    sf::Vector2f buttonPos = sf::Vector2f((window.getSize().x - window.getSize().x) + 350, window.getSize().y / 2);
    m_highScoreText.setPosition(buttonPos);
}

bool HighScoreOption::isSelected() const
{

    return m_isSelected;
}

void HighScoreOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_highScoreText.setOutlineColor(sf::Color::Blue);
    } else {
        m_highScoreText.setOutlineColor(sf::Color{ 128,128,128 });

    }
}

sf::Text* HighScoreOption::getText()
{
    return &m_highScoreText;
}
