#include "Border.hpp"

Border::Border(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color)
: m_shape(std::make_unique<sf::RectangleShape>(size))
{
    m_shape->setFillColor(sf::Color::Transparent);
    m_shape->setOutlineColor(color);
    m_shape->setOutlineThickness(5.f);
    setPosition(position.x, position.y);
}

void Border::move(float x, float y)
{
    m_shape->move(x, y);
}

void Border::setPosition(float x, float y)
{
    m_shape->setPosition(x, y);
}

void Border::draw(sf::RenderWindow &window)
{
    window.draw(*m_shape);
}

sf::Vector2f Border::getPosition() const
{
    return m_shape->getPosition();
}

float Border::getRadius() const
{
    return 0.f;
}

std::unique_ptr<sf::RectangleShape> &Border::getShape()
{
    return m_shape;
}
