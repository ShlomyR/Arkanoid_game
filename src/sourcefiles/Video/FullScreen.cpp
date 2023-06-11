#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "FullScreen.hpp"
#include "GameState.hpp"

bool FullScreen::m_isMusicPlayed;

void FullScreen::draw(sf::RenderWindow& window)
{
    window.draw(m_fullScreenText);
}

bool FullScreen::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    sf::VideoMode resolution(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    bool mouseHover = m_fullScreenText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_fullScreenText.setOutlineColor(sf::Color::Blue);
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
        m_fullScreenText.setOutlineColor(sf::Color::White);
    }
    return false;
}


void FullScreen::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_fullScreenText.setString("Full screen");
    m_fullScreenText.setFont(m_font);
    m_fullScreenText.setCharacterSize(48);
    m_fullScreenText.setFillColor(sf::Color::Transparent);
    m_fullScreenText.setOutlineThickness(2);
    m_fullScreenText.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_fullScreenText.getGlobalBounds().width / 2, window.getSize().y / 2 - 200);
    m_fullScreenText.setPosition(buttonPos);
}

bool FullScreen::isSelected() const
{
    return m_isSelected;
}

void FullScreen::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    if (m_isTranslucent) {
        m_fullScreenText.setFillColor(sf::Color::Transparent);
    } else {
        m_fullScreenText.setFillColor(sf::Color::Green);
    }
}

void FullScreen::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_fullScreenText.setOutlineColor(sf::Color::Blue);
    } else {
        m_fullScreenText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* FullScreen::getText()
{
    return &m_fullScreenText;
}
