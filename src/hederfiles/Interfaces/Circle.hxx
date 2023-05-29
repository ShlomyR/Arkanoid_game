#pragma once

#include "Shape.hxx"

class Circle : public Shape
{
public:
    ~Circle() = default;

    void move(float, float) = 0;
    void setPosition(float , float ) = 0;
    void draw(sf::RenderWindow &) = 0;
    sf::Vector2f getPosition() const = 0;
    float getRadius() const = 0;

    virtual void setDirection(const sf::Vector2f &) = 0;
    virtual sf::Vector2f getDirection() const = 0;
    virtual std::unique_ptr<sf::CircleShape> &getShape() = 0;
};
