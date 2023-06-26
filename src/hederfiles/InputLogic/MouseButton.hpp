#pragma once

class Menu;
class Options;
class Difficulty;
class Video;

class MouseButton
{
public:
    MouseButton(Menu &, Options &, Difficulty &, Video &);
    ~MouseButton() = default;
    void left(bool const&);
private:
    Menu &m_menu;
    Options &m_options;
    Difficulty &m_difficulty;
    Video &m_video;
};
