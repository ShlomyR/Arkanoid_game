#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "PlayOption.hpp"
#include "GameState.hpp"

bool PlayOption::m_isMusicPlayed;

void PlayOption::draw(sf::RenderWindow& window)
{
    window.draw(m_playText);
}

void PlayOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void PlayOption::updateColor(sf::Text &text, sf::Color color)
{
    text.setOutlineColor(color);
    text.setFillColor(color);
}

bool PlayOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    auto color = sf::Color{ 128,128,128 };
    bool mouseHover = m_playText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (sf::Joystick::isConnected(0)) {
        m_mouseCurser = false;
        gameState.getWindow().getRenderWindow().setMouseCursorVisible(false);
        if (m_playText.getFillColor() == sf::Color::White) {
            updateColor(m_playText, sf::Color::White);
            if (!m_isMusicPlayed) {
                SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
                m_isMusicPlayed = true;
            }
            if (m_isSelected) {
                m_isSelected = false;
                setIsSelected(false);
                if (m_counter == 0) {
                    gameState.getResoloution().updateLayout(gameState.getWindow().getSize());
                    gameState.reset();
                    ++m_counter;
                }
                
                gameState.setState(State::PlayPage);
            }
        } else {
            m_isMusicPlayed = false;
            setIsSelected(false);
        }
    } else {
        m_mouseCurser = true;
    }
        
    if (mouseHover && m_mouseCurser) {
        updateColor(m_playText, sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }
        if (m_isSelected) {
            m_isSelected = false;
            setIsSelected(false);
            if (m_counter == 0) {
                gameState.getResoloution().updateLayout(gameState.getWindow().getSize());
                gameState.reset();
                ++m_counter;
            }
            
            gameState.setState(State::PlayPage);
        }
    } else if (m_mouseCurser) {
        m_isMusicPlayed = false;
        setIsSelected(false);
        updateColor(m_playText, color);
    }

    return false;
}


void PlayOption::makeButton(sf::RenderWindow& window)
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_playText.setString("PLAY");
    m_playText.setFont(m_font);
    m_playText.setCharacterSize(48);
    m_playText.setScale(0.5,0.5);
    m_playText.setFillColor(color);
    m_playText.setOutlineThickness(2);
    m_playText.setOutlineColor(color);
    sf::Vector2f buttonPos = sf::Vector2f((window.getSize().x - window.getSize().x) + 350, window.getSize().y / 2 - 50);
    m_playText.setPosition(buttonPos);
}

bool PlayOption::isSelected() const
{
    return m_isSelected;
}

void PlayOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_playText.setOutlineColor(sf::Color::Blue);
    } else {
        m_playText.setOutlineColor(sf::Color{ 128,128,128 });
    }
}

sf::Text* PlayOption::getText()
{
    return &m_playText;
}

void PlayOption::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    auto color = sf::Color{ 128,128,128 };
    if (m_isTranslucent) {
        m_playText.setFillColor(color);
    } else {
        m_playText.setFillColor(sf::Color::White);
    }
}
