#pragma once

#include "Paddle.hpp"
#include "WindowManager.hpp"

class PaddleArrowsHandnling
{
public:
    PaddleArrowsHandnling(Paddle &paddle);
    ~PaddleArrowsHandnling() = default;
    void left();
    void right();
    void space();
    
private:
    Paddle &m_paddle;
};

// class WindowArrowsHandnling
// {
// public:
//     WindowArrowsHandnling(WindowManager &window_manager);
//     ~WindowArrowsHandnling() = default;
//     void exit();
//     void q();
    
// private:
//     WindowManager &m_window_manager;
// };

// class MenuArrowsHandnling
// {
// public:
//     MenuArrowsHandnling(Menu &menu);
//     ~MenuArrowsHandnling() = default;
//     void enter();
//     void up();
//     void down();
    
// private:
//     Menu &m_menu;
// };