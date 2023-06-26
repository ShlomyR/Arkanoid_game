#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "EasyOption.hpp"
#include "GameState.hpp"

bool EasyOption::m_isMusicPlayed;

void EasyOption::draw(sf::RenderWindow& window)
{
    window.draw(m_easyText);
}

bool EasyOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_easyText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_easyText.setOutlineColor(sf::Color::White);
        if (!m_isMusicPlayed) {
            SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
            m_isMusicPlayed = true;
        }

        if (m_isSelected) {
            for (auto& option : gameState.getDifficulty().getOptions()) {
                if (option.get() != this) {
                    option->setIsTranslucent(true);
                    gameState.setBallSpeed_(0.03);
                } else {
                    option->setIsTranslucent(false);
                }
            }
            m_isSelected = false;
            setIsSelected(false);
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_easyText.setOutlineColor(m_color);
    }

    return false;
}


void EasyOption::makeButton(sf::RenderWindow&)
{
    m_color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_easyText.setString("EASY");
    m_easyText.setFont(m_font);
    m_easyText.setCharacterSize(48);
    m_easyText.setFillColor(sf::Color::White);
    m_easyText.setOutlineThickness(2);
    m_easyText.setOutlineColor(sf::Color::White);
    m_easyText.setScale(0.5, 0.5);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 100));
    m_easyText.setPosition(buttonPos);
}

bool EasyOption::isSelected() const
{
    return m_isSelected;
}

void EasyOption::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    if (m_isTranslucent) {
        m_easyText.setFillColor(m_color);
    } else {
        m_easyText.setFillColor(sf::Color::White);
    }
}

void EasyOption::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void EasyOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_easyText.setOutlineColor(m_color);
    } else {
        m_easyText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* EasyOption::getText()
{
    return &m_easyText;
}
