#include "Paddle.hpp"

#include <iostream>

Paddle::Paddle(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color)
: m_shape(std::make_shared<sf::RectangleShape>(size))
{
    m_shape->setFillColor(sf::Color::Blue);
    m_shape->setOutlineColor(color);
    m_shape->setOutlineThickness(1.f);
    setPosition(position.x, position.y);
}

void Paddle::move(float x, float y)
{
    m_shape->move(x, y);
}

void Paddle::setPosition(float x, float y)
{
    m_shape->setPosition(x, y);
}

void Paddle::draw(sf::RenderWindow &window)
{
    window.draw(*m_shape);
}

sf::Vector2f Paddle::getPosition() const
{
    return m_shape->getPosition();
}

float Paddle::getRadius() const
{
    return 0.f;
}

std::shared_ptr<sf::RectangleShape> &Paddle::getShape()
{
    return m_shape;
}

void Paddle::setIsPressed(bool val)
{
    m_isPressed = val;
}

bool Paddle::getIsPressed()
{
    return m_isPressed;
}

sf::Vector2f Paddle::getCenterPosition()
{
    return sf::Vector2f(m_shape->getGlobalBounds().left+50,m_shape->getGlobalBounds().top-13);
}
