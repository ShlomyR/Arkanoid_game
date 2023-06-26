#include "SoundManager.hpp"
#include "InputHandlerImpl.hpp"
#include "ResX800.hpp"
#include "GameState.hpp"

bool ResX800::m_isMusicPlayed;

void ResX800::draw(sf::RenderWindow& window)
{
    window.draw(m_resX800Text);
}

bool ResX800::handleInput(InputHandler& , GameState &gameState)
{
    sf::VideoMode resolution(800, 600);
    // auto color = sf::Color{ 128,128,128 };
    // bool mouseHover = m_resX800Text.getGlobalBounds().contains(inputHandler.getMousePosition());
     bool mouseHover = false;
    if (mouseHover) {
        // m_resX800Text.setOutlineColor(sf::Color::White);
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
        // m_resX800Text.setOutlineColor(color);
    }
    return false;
}


void ResX800::makeButton(sf::RenderWindow& )
{
    auto color = sf::Color{ 128,128,128 };
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_resX800Text.setString("800 X 600");
    m_resX800Text.setFont(m_font);
    m_resX800Text.setCharacterSize(48);
    m_resX800Text.setFillColor(color);
    m_resX800Text.setOutlineThickness(2);
    m_resX800Text.setOutlineColor(color);
    m_resX800Text.setScale(0.5, 0.5);
    sf::Vector2f buttonPos = sf::Vector2f(sf::Vector2f(m_boxBorder.getPosition().x + 40, m_boxBorder.getPosition().y + 200));
    m_resX800Text.setPosition(buttonPos);
}

bool ResX800::isSelected() const
{
    return m_isSelected;
}

void ResX800::setIsTranslucent(bool value)
{
    m_isTranslucent = value;
    auto color = sf::Color{ 128,128,128 };
    if (m_isTranslucent) {
        m_resX800Text.setFillColor(color);
    } else {
        m_resX800Text.setFillColor(sf::Color::White);
    }
}

void ResX800::setBoxBorder(sf::RectangleShape &recShape)
{
    m_boxBorder = recShape;
}

void ResX800::setIsSelected(bool value)
{
    m_isSelected = value;
    auto color = sf::Color{ 128,128,128 };
    if (m_isSelected) {
        m_resX800Text.setOutlineColor(color);
    } else {
        m_resX800Text.setOutlineColor(sf::Color::White);
    }
}

sf::Text* ResX800::getText()
{
    return &m_resX800Text;
}
