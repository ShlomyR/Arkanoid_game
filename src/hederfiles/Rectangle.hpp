#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    ~Rectangle() = default;

    void move(float, float) = 0;
    void setPosition(float, float) = 0;
    void draw(sf::RenderWindow &) = 0;
    sf::Vector2f getPosition() const = 0;
    float getRadius() const = 0;
};