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
        m_hardText.setOutlineColor(sf::Color::Blue);
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
        m_hardText.setOutlineColor(sf::Color::White);
    }

    return false;
}


void HardOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_hardText.setString("HARD");
    m_hardText.setFont(m_font);
    m_hardText.setCharacterSize(48);
    m_hardText.setFillColor(sf::Color::Transparent);
    m_hardText.setOutlineThickness(2);
    m_hardText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_hardText.getGlobalBounds().width / 2, window.getSize().y / 2);
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
        m_hardText.setFillColor(sf::Color::Transparent);
    } else {
        m_hardText.setFillColor(sf::Color::Green);
    }
}

void HardOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_hardText.setOutlineColor(sf::Color::Blue);
    } else {
        m_hardText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* HardOption::getText()
{
    return &m_hardText;
}
