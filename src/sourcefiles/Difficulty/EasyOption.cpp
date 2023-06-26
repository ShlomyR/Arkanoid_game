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
        m_easyText.setOutlineColor(sf::Color::Blue);
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
        m_easyText.setOutlineColor(sf::Color::White);
    }

    return false;
}


void EasyOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_easyText.setString("EASY");
    m_easyText.setFont(m_font);
    m_easyText.setCharacterSize(48);
    m_easyText.setFillColor(sf::Color::Green);
    m_easyText.setOutlineThickness(2);
    m_easyText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_easyText.getGlobalBounds().width / 2, window.getSize().y / 2 - 200);
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
        m_easyText.setFillColor(sf::Color::Transparent);
    } else {
        m_easyText.setFillColor(sf::Color::Green);
    }
}

void EasyOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_easyText.setOutlineColor(sf::Color::Blue);
    } else {
        m_easyText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* EasyOption::getText()
{
    return &m_easyText;
}
