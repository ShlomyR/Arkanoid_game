#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "ResX800.hpp"
#include "GameState.hpp"

bool ResX800::m_isMusicPlayed;

void ResX800::draw(sf::RenderWindow& window)
{
    window.draw(m_resX800Text);
}

bool ResX800::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    sf::VideoMode resolution(800, 600);
    bool mouseHover = m_resX800Text.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_resX800Text.setOutlineColor(sf::Color::Blue);
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
        m_resX800Text.setOutlineColor(sf::Color::White);
    }
    return false;
}


void ResX800::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_resX800Text.setString("800 X 600");
    m_resX800Text.setFont(m_font);
    m_resX800Text.setCharacterSize(48);
    m_resX800Text.setFillColor(sf::Color::Green);
    m_resX800Text.setOutlineThickness(2);
    m_resX800Text.setOutlineColor(sf::Color::Black);
    sf::Vector2f buttonPos = sf::Vector2f(window.getSize().x / 2 - m_resX800Text.getGlobalBounds().width / 2, window.getSize().y / 2 - 100);
    m_resX800Text.setPosition(buttonPos);
}

bool ResX800::isSelected() const
{
    return m_isSelected;
}

void ResX800::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    if (m_isTranslucent) {
        m_resX800Text.setFillColor(sf::Color::Transparent);
    } else {
        m_resX800Text.setFillColor(sf::Color::Green);
    }
}

void ResX800::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_resX800Text.setOutlineColor(sf::Color::Blue);
    } else {
        m_resX800Text.setOutlineColor(sf::Color::White);
    }
}

sf::Text* ResX800::getText()
{
    return &m_resX800Text;
}
