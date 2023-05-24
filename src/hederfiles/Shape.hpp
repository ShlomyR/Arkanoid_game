#pragma once

#include <SFML/Graphics.hpp>
// #include "WindowManager.hpp"


#include <cmath>
#include <memory>

class Shape
{
public:
    virtual void move(float, float) = 0;
    virtual void setPosition(float, float) = 0;
    virtual void draw(sf::RenderWindow &) = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual float getRadius() const = 0;
};