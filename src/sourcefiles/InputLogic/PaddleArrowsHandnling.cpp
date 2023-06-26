#include "PaddleArrowsHandnling.hpp"

PaddleArrowsHandnling::PaddleArrowsHandnling(Paddle &paddle, ControlSettings &controlSettings)
: m_paddle(paddle)
, m_controlSettings(controlSettings)
{}

void PaddleArrowsHandnling::left()
{
    if (sf::Keyboard::isKeyPressed(m_controlSettings.getMapping("Left"))) {
        m_paddle.move(-10, 0);
    }
}

void PaddleArrowsHandnling::right()
{
    if (sf::Keyboard::isKeyPressed(m_controlSettings.getMapping("Right"))) {
        m_paddle.move(10, 0);
    }
}

void PaddleArrowsHandnling::update()
{
    left();
    right();
}

void PaddleArrowsHandnling::space()
{
    m_paddle.setIsPressed(true);
}
