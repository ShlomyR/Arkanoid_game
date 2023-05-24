#pragma once

#include "PaddleArrowsHandnling.hpp"
#include <SFML/Graphics.hpp>
class MouseButton;

class InputHandler {
public:
    virtual ~InputHandler() = default;
    virtual void handleInput() = 0;
    virtual sf::Vector2f &getMousePosition() = 0;
    virtual bool isHandlerSelected() = 0;
    virtual void setIsSelected(bool) = 0;
};
