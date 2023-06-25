#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "HardOption.hpp"
#include "GameState.hpp"

bool HardOption::m_isMusicPlayed;

void HardOption::draw(sf::RenderWindow& window)
{
    window.draw(m_hardText);
}

bool HardOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_hardText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_hardText.setOutlineColor(sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }


        if (m_isSelected) {
            for (auto& option : gameState.getDifficulty().getOptions()) {
                if (option.get() != this) {
                    option->setIsTranslucent(true);
                    gameState.setBallSpeed_(0.07);
                } else {
                    option->setIsTranslucent(false);
                }
            }
            m_isSelected = false;
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_hardText.setOutlineColor(m_color);
    }

    return false;
}


void HardOption::makeButton(sf::RenderWindow&)
{
    m_color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_hardText.setString("HARD");
    m_hardText.setFont(m_font);
    m_hardText.setCharacterSize(48);
    m_hardText.setFillColor(m_color);
    m_hardText.setOutlineThickness(2);
    m_hardText.setOutlineColor(m_color);
    m_hardText.setScale(0.5, 0.5);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 200));
    m_hardText.setPosition(buttonPos);
}

bool HardOption::isSelected() const
{
    return m_isSelected;
}

void HardOption::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    if (m_isTranslucent) {
        m_hardText.setFillColor(m_color);
    } else {
        m_hardText.setFillColor(sf::Color::White);
    }
}

void HardOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void HardOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_hardText.setOutlineColor(m_color);
    } else {
        m_hardText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* HardOption::getText()
{
    return &m_hardText;
}
