#pragma once



class Border;
class Paddle;
class Brick;
class Hud;
class Menu;
class Options;
class Difficulty;
class GameState;
class WindowManager;
class Video;
class ControlSettingsMenu;
class VolumeManager;
class SquareWithBricks;

#include "MenuOption.hxx"
#include "BrickType.hpp"

#include <SFML/Graphics.hpp>
#include "iostream"
#include <memory>


class Resoloution
{
public:
    Resoloution(WindowManager& 
        , Border&
        , Paddle&
        , Brick&
        , Hud&
        , Menu&
        , Options&
        , Difficulty&
        , Video&
        , ControlSettingsMenu &
        , VolumeManager &
        , SquareWithBricks &
    );
    void updateLayout(const sf::Vector2u&);
    void changeResolution(sf::VideoMode);
    void setVec(std::vector<std::vector<BrickLevel>>);
private:
    void updateTextPositions(const sf::Vector2u&);
    void updateBrickPositions(const sf::Vector2u&);
    void updateScoreTextPosition(const sf::Vector2u&);
    void updateBorderPosition(const sf::Vector2u&);
    void updatePaddlePosition(const sf::Vector2u&);
    void setPositionsWithOffset(std::vector<std::shared_ptr<MenuOption>>, const sf::Vector2u &, int);
    void updateBrickPositionsForResolution(const sf::Vector2f&);
private:
    WindowManager& m_window;
    Border& m_border;
    Paddle& m_paddle;
    Brick& m_brick;
    Hud& m_hud;
    Menu& m_menu;
    Options& m_options;
    Difficulty& m_difficulty;
    Video& m_video;
    ControlSettingsMenu &m_controlSettingsMenu;
    VolumeManager &m_volume;
    SquareWithBricks &m_squareWithBricks;
    static int m_count;
    sf::Vector2f m_initialWindowSize;
    sf::Vector2f m_firstBrickPos;
    std::vector<std::vector<BrickLevel>> m_brickVecPos;
};
