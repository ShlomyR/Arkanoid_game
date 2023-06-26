#pragma once

#include <SFML/Graphics.hpp>

class InputHandler;
class GameState;

class MenuOption
{
public:
    virtual ~MenuOption() = default;
    virtual void draw(sf::RenderWindow& ) = 0;
    virtual bool handleInput(InputHandler& ,GameState &) = 0;
    virtual void makeButton(sf::RenderWindow&) = 0;
    virtual bool isSelected() const = 0;
    virtual void setIsSelected(bool) = 0;
    virtual void setIsTranslucent(bool value) = 0;
    virtual sf::Text* getText() = 0;
protected:
    sf::Font m_font;
    int m_firstButtonPos;
};
