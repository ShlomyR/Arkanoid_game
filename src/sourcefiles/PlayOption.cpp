#include "../hederfiles/PlayOption.hpp"
#include "../hederfiles/InputHandler.hpp"
#include "../hederfiles/GameState.hpp"

void PlayOption::draw(sf::RenderWindow& window)
{
    window.draw(m_playText);
}

bool PlayOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_playText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_playText.setOutlineColor(sf::Color::Red);
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::PlayPage);
        
        }
    } else {
        setIsSelected(false);
        m_playText.setOutlineColor(sf::Color::White);
    }

    return false;
}


void PlayOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_playText.setString("PLAY");
    m_playText.setFont(m_font);
    m_playText.setCharacterSize(48);
    m_playText.setFillColor(sf::Color::White);
    m_playText.setOutlineThickness(2);
    m_playText.setOutlineColor(sf::Color::Black);
    m_playText.setPosition(sf::Vector2f(window.getSize().x / 2 - m_playText.getGlobalBounds().width / 2, window.getSize().y / 2 - 150));
}

bool PlayOption::isSelected() const
{

    return m_isSelected;
}

void PlayOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_playText.setOutlineColor(sf::Color::Red);
    } else {
        m_playText.setOutlineColor(sf::Color::White);

    }
}

sf::Text PlayOption::getText()
{
    return m_playText;
}
