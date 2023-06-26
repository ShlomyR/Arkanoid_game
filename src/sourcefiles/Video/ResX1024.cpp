#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "ResX1024.hpp"
#include "GameState.hpp"

bool ResX1024::m_isMusicPlayed;

void ResX1024::draw(sf::RenderWindow& window)
{
    window.draw(m_resX1024Text);
}

bool ResX1024::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    sf::VideoMode resolution(1024, 768);
    bool mouseHover = m_resX1024Text.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_resX1024Text.setOutlineColor(sf::Color::Blue);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }

        if (m_isSelected) {
            for (auto& option : gameState.getVideo().getOptions()) {
                if (option.get() != this) {
                    option->setIsTranslucent(true);
                } else {
                    option->setIsTranslucent(false);
                }
            }
            m_isSelected = false;
            setIsSelected(false);
            gameState.getResoloution().changeResolution(resolution);
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_resX1024Text.setOutlineColor(sf::Color::White);
    }
    return false;
}


void ResX1024::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_resX1024Text.setString("1024 X 768");
    m_resX1024Text.setFont(m_font);
    m_resX1024Text.setCharacterSize(48);
    m_resX1024Text.setFillColor(sf::Color::Transparent);
    m_resX1024Text.setOutlineThickness(2);
    m_resX1024Text.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_resX1024Text.getGlobalBounds().width / 2, window.getSize().y / 2);
    m_resX1024Text.setPosition(buttonPos);
}

bool ResX1024::isSelected() const
{
    return m_isSelected;
}

void ResX1024::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    if (m_isTranslucent) {
        m_resX1024Text.setFillColor(sf::Color::Transparent);
    } else {
        m_resX1024Text.setFillColor(sf::Color::Green);
    }
}

void ResX1024::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_resX1024Text.setOutlineColor(sf::Color::Blue);
    } else {
        m_resX1024Text.setOutlineColor(sf::Color::White);
    }
}

sf::Text* ResX1024::getText()
{
    return &m_resX1024Text;
}
