#include "../hederfiles/ExitOption.hpp"
#include "../hederfiles/InputHandler.hpp"
#include "../hederfiles/GameState.hpp"

void ExitOption::draw(sf::RenderWindow& window)
{
    window.draw(m_exitText);
}

bool ExitOption::handleInput(InputHandler& inputHandler, GameState &gameState)
{
    bool mouseHover = m_exitText.getGlobalBounds().contains(inputHandler.getMousePosition());
    if (mouseHover) {
        m_exitText.setOutlineColor(sf::Color::Red);
        if (m_isSelected) {
            m_isSelected = false;
            gameState.setState(State::Exit);
        
        }
    } else {
        setIsSelected(false);
        m_exitText.setOutlineColor(sf::Color::White);
    }
    
    return false;
}

void ExitOption::makeButton(sf::RenderWindow& window)
{
    m_font.loadFromFile("src/fonts/kenVectoFutureThin2.ttf");
    m_exitText.setString("EXIT");
    m_exitText.setFont(m_font);
    m_exitText.setCharacterSize(48);
    m_exitText.setFillColor(sf::Color::White);
    m_exitText.setOutlineThickness(2);
    m_exitText.setOutlineColor(sf::Color::Black);
    m_exitText.setPosition(sf::Vector2f(window.getSize().x / 2 - m_exitText.getGlobalBounds().width / 2, window.getSize().y / 2 + 50));
}

bool ExitOption::isSelected() const
{

    return m_isSelected;
}

void ExitOption::setIsSelected(bool value)
{
    m_isSelected = value;
    if (m_isSelected) {
        m_exitText.setOutlineColor(sf::Color::Red);
    } else {
        m_exitText.setOutlineColor(sf::Color::White);

    }
}

sf::Text ExitOption::getText()
{
    return m_exitText;
}