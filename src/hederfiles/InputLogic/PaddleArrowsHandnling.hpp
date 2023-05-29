#pragma once

#include "Paddle.hpp"
#include "WindowManager.hpp"

class PaddleArrowsHandnling
{
public:
    PaddleArrowsHandnling(Paddle &);
    ~PaddleArrowsHandnling() = default;
    void left();
    void right();
    void space();
private:
    Paddle &m_paddle;
};
