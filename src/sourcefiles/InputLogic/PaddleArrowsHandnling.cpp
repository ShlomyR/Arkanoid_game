#include "PaddleArrowsHandnling.hpp"

PaddleArrowsHandnling::PaddleArrowsHandnling(Paddle &paddle, ControlSettings &controlSettings)
: m_paddle(paddle)
, m_controlSettings(controlSettings)
{}

void PaddleArrowsHandnling::left()
{
    if (sf::Joystick::isConnected(0)) {
        if (sf::Joystick::isButtonPressed(0,m_controlSettings.getPs4Mapping("Move Paddle Left"))) {
            m_paddle.move(-10, 0);
        }
    } else {
        if (sf::Keyboard::isKeyPressed(m_controlSettings.getMapping("Move Paddle Left"))) {
            m_paddle.move(-10, 0);
        }
    } 
}

void PaddleArrowsHandnling::right()
{
    if (sf::Joystick::isConnected(0)) {
        if (sf::Joystick::isButtonPressed(0,m_controlSettings.getPs4Mapping("Move Paddle Right"))) {
            m_paddle.move(10, 0);
        }
    } else {
        if (sf::Keyboard::isKeyPressed(m_controlSettings.getMapping("Move Paddle Right"))) {
            m_paddle.move(10, 0);
        }
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
