#pragma once

#include "Rectangle.hxx"

class Border : public Rectangle
{
public:
    Border() = default;
    Border(const sf::Vector2f &, const sf::Vector2f &, const sf::Color &);
    ~Border() = default;

    void move(float, float) override;
    void setPosition(float, float) override;
    void draw(sf::RenderWindow &) override;
    sf::Vector2f getPosition() const override;
    float getRadius() const override;
    
    std::unique_ptr<sf::RectangleShape> &getShape();
private:
    std::unique_ptr<sf::RectangleShape> m_shape;
};