#pragma once

#include "Rectangle.hpp"

class Paddle : public Rectangle
{
public:
    Paddle() = default;
    Paddle(const sf::Vector2f &, const sf::Vector2f &, const sf::Color &);
    ~Paddle() = default;

    void move(float, float) override;
    void update();
    void setPosition(float, float) override;
    void draw(sf::RenderWindow &) override;
    sf::Vector2f getPosition() const override;
    float getRadius() const override;
    
    std::shared_ptr<sf::RectangleShape> &getShape();
    void setIsPressed(bool);
    bool getIsPressed();
    sf::Vector2f getCenterPosition();
private:
    std::shared_ptr<sf::RectangleShape> m_shape;
    bool m_isPressed = false;
    bool m_paused = false;
    float m_speed = 10;
};