#pragma once

#include <SFML/Graphics.hpp>

class ControlTypeHandler 
{
public:
    virtual void initializeGUI() = 0;
    virtual void draw() = 0;
    virtual void updateText(const sf::Vector2u&) = 0;
    virtual void handleMouseMovedInput(sf::Vector2f& mousePosition) = 0;
    virtual void handleKeyPressedInput(const sf::Event& event, sf::Vector2f& mousePosition) = 0;
};
