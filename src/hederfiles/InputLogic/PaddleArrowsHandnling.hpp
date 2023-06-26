#pragma once

#include "Paddle.hpp"
#include "WindowManager.hpp"
#include "ControlSettings.hpp"

class PaddleArrowsHandnling
{
public:
    PaddleArrowsHandnling(Paddle &, ControlSettings &);
    ~PaddleArrowsHandnling() = default;
    void left();
    void right();
    void update();
    void space();
private:
    Paddle &m_paddle;
    ControlSettings& m_controlSettings;
};
