#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "ResX1024.hpp"
#include "GameState.hpp"

bool ResX1024::m_isMusicPlayed;

void ResX1024::draw(sf::RenderWindow& window)
{
    window.draw(m_resX1024Text);
}

bool ResX1024::handleInput(InputHandler& , GameState &gameState)
{
    sf::VideoMode resolution(1024, 768);
    // auto color = sf::Color{ 128,128,128 };
    // bool mouseHover = m_resX1024Text.getGlobalBounds().contains(inputHandler.getMousePosition());
     bool mouseHover = false;
    if (mouseHover) {
        // m_resX1024Text.setOutlineColor(sf::Color::White);
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
        // m_resX1024Text.setOutlineColor(color);
    }
    return false;
}


void ResX1024::makeButton(sf::RenderWindow&)
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_resX1024Text.setString("1024 X 768");
    m_resX1024Text.setFont(m_font);
    m_resX1024Text.setCharacterSize(48);
    m_resX1024Text.setFillColor(color);
    m_resX1024Text.setOutlineThickness(2);
    m_resX1024Text.setOutlineColor(color);
    m_resX1024Text.setScale(0.5, 0.5);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 150));
    m_resX1024Text.setPosition(buttonPos);
}

bool ResX1024::isSelected() const
{
    return m_isSelected;
}

void ResX1024::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    auto color = sf::Color{ 128,128,128 };
    if (m_isTranslucent) {
        m_resX1024Text.setFillColor(color);
    } else {
        m_resX1024Text.setFillColor(sf::Color::White);
    }
}

void ResX1024::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void ResX1024::setIsSelected(bool value)
{
    m_isSelected = value;
    auto color = sf::Color{ 128,128,128 };
    if (m_isSelected) {
        m_resX1024Text.setOutlineColor(color);
    } else {
        m_resX1024Text.setOutlineColor(sf::Color::White);
    }
}

sf::Text* ResX1024::getText()
{
    return &m_resX1024Text;
}
