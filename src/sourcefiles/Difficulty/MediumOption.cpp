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
    if (mouseHover) {
        m_mediumText.setOutlineColor(sf::Color::Blue);
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
        m_mediumText.setOutlineColor(sf::Color::White); 
    }

    return false;
}


void MediumOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_mediumText.setString("MEDIUM");
    m_mediumText.setFont(m_font);
    m_mediumText.setCharacterSize(48);
    m_mediumText.setFillColor(sf::Color::Transparent);
    m_mediumText.setOutlineThickness(2);
    m_mediumText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_mediumText.getGlobalBounds().width / 2, window.getSize().y / 2 - 100);
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
        m_mediumText.setFillColor(sf::Color::Transparent);
    } else {
        m_mediumText.setFillColor(sf::Color::Green);
    }
}

void MediumOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_mediumText.setOutlineColor(sf::Color::Blue);
    } else {
        m_mediumText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* MediumOption::getText()
{
    return &m_mediumText;
}
