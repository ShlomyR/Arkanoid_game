#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "MediumOption.hpp"
#include "GameState.hpp"

bool MediumOption::m_isMusicPlayed;

void MediumOption::draw(sf::RenderWindow& window)
{
    window.draw(m_mediumText);
}

bool MediumOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_mediumText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover || m_mediumText.getFillColor() == sf::Color::White) {
        m_mediumText.setOutlineColor(sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;

        }
        if (m_isSelected) {
            for (auto& option : gameState.getDifficulty().getOptions()) {
                if (option.get() != this) {
                    option->setIsTranslucent(true);
                    gameState.setBallSpeed_(0.05);
                } else {
                    option->setIsTranslucent(false);
                }
            }
            m_isSelected = false;
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_mediumText.setOutlineColor(m_color);
    }

    return false;
}


void MediumOption::makeButton(sf::RenderWindow&)
{
    m_color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_mediumText.setString("MEDIUM");
    m_mediumText.setFont(m_font);
    m_mediumText.setCharacterSize(48);
    m_mediumText.setFillColor(m_color);
    m_mediumText.setOutlineThickness(2);
    m_mediumText.setOutlineColor(m_color);
    m_mediumText.setScale(0.5, 0.5);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 150));
    m_mediumText.setPosition(buttonPos);
}

bool MediumOption::isSelected() const
{
    return m_isSelected;
}

void MediumOption::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    if (m_isTranslucent) {
        m_mediumText.setFillColor(m_color);
    } else {
        m_mediumText.setFillColor(sf::Color::White);
    }
}

void MediumOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void MediumOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_mediumText.setOutlineColor(m_color);
    } else {
        m_mediumText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* MediumOption::getText()
{
    return &m_mediumText;
}
