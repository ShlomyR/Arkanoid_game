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
    auto color = sf::Color{ 128,128,128 };
    if (mouseHover) {
        m_fullScreenText.setOutlineColor(sf::Color::White);
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
            // gameState.getResoloution().changeResolution(resolution);
        }
    } else {
        m_isMusicPlayed = false;
        setIsSelected(false);
        m_fullScreenText.setOutlineColor(color);
    }
    return false;
}


void FullScreen::makeButton(sf::RenderWindow& )
{
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_fullScreenText.setString("Full screen");
    m_fullScreenText.setFont(m_font);
    m_fullScreenText.setCharacterSize(48);
    m_fullScreenText.setFillColor(sf::Color::White);
    m_fullScreenText.setOutlineThickness(2);
    m_fullScreenText.setOutlineColor(sf::Color::White);
    m_fullScreenText.setScale(0.5, 0.5);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 100));
    m_fullScreenText.setPosition(buttonPos);
}

bool FullScreen::isSelected() const
{
    return m_isSelected;
}

void FullScreen::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    auto color = sf::Color{ 128,128,128 };
    if (m_isTranslucent) {
        m_fullScreenText.setFillColor(color);
    } else {
        m_fullScreenText.setFillColor(sf::Color::White);
    }
}

void FullScreen::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void FullScreen::setIsSelected(bool value)
{
    m_isSelected = value;
    auto color = sf::Color{ 128,128,128 };
    if (m_isSelected) {
        m_fullScreenText.setOutlineColor(color);
    } else {
        m_fullScreenText.setOutlineColor(sf::Color::White);
    }
}

sf::Text* FullScreen::getText()
{
    return &m_fullScreenText;
}
