#pragma once

#include "Circle.hxx"

class Ball : public Circle
{
public:
    Ball() = default;
    Ball(float, const sf::Vector2f &, const sf::Color &);
    ~Ball() = default;

    void move(float, float) override;
    void setPosition(float , float ) override;
    void draw(sf::RenderWindow &) override;
    sf::Vector2f getPosition() const override;
    float getRadius() const override;

    void setDirection(const sf::Vector2f &) override;
    sf::Vector2f getDirection() const override;
    std::unique_ptr<sf::CircleShape> &getShape() override;
    void setBallVelocity(sf::Vector2f);
    sf::Vector2f getBallVelocity() const;
    void setBallSpeed(float);
    float getBallSpeed();
private:
    std::unique_ptr<sf::CircleShape> m_shape;
    sf::Vector2f m_direction;
    float m_BallSpeed;
};