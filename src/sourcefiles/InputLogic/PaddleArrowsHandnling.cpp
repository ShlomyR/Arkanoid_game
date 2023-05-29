#include "PaddleArrowsHandnling.hpp"

PaddleArrowsHandnling::PaddleArrowsHandnling(Paddle &paddle)
: m_paddle(paddle)
{}

void PaddleArrowsHandnling::left()
{
    // m_paddle.move(-10,0);    
}

void PaddleArrowsHandnling::right()
{
    // m_paddle.move(10, 0);
}

void PaddleArrowsHandnling::space()
{
    m_paddle.setIsPressed(true);
}
