#pragma once

class Menu;
class Options;
class Difficulty;
class Video;
class MenuScreenHandler;

class MouseButton
{
public:
    MouseButton(Menu &, Options &, Difficulty &, Video &, MenuScreenHandler &);
    ~MouseButton() = default;
    void left(bool const&);
private:
    Menu &m_menu;
    Options &m_options;
    Difficulty &m_difficulty;
    Video &m_video;
    MenuScreenHandler &m_menuScreenHandler;
};
