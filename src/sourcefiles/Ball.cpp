#include "../hederfiles/Ball.hpp"

Ball::Ball(float radius, const sf::Vector2f &position, const sf::Color &color)
:    m_shape(std::make_unique<sf::CircleShape>(radius))
,   m_direction(1.f, 1.f)
{
    m_shape->setFillColor(color);
    m_shape->setOrigin(radius, radius);
    setPosition(position.x, position.y);
}

void Ball::move(float x, float y)
{
    m_shape->move(x, y);
}

void Ball::setPosition(float x, float y)
{
    m_shape->setPosition(x, y);
}

void Ball::draw(sf::RenderWindow &window)
{
    window.draw(*m_shape);
}

sf::Vector2f Ball::getPosition() const
{
    return m_shape->getPosition();
}

float Ball::getRadius() const
{
    return m_shape->getRadius();
}

void Ball::setDirection(const sf::Vector2f &direction)
{
    m_direction = direction / std::sqrt(direction.x * direction.x + direction.y * direction.y);
}

sf::Vector2f Ball::getDirection() const
{
    return m_direction;
}

std::unique_ptr<sf::CircleShape> &Ball::getShape()
{
    return m_shape;
}