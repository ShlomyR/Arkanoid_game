#pragma once

#include "Video.hpp"
#include "Difficulty.hpp"
#include "Menu.hpp"
#include "Ball.hpp"
#include "WindowManager.hpp"
#include "Options.hpp"
#include "Resoloution.hpp"
#include "Paddle.hpp"
#include "ControlSettings.hpp"
#include "VolumeManager.hpp"
#include "ControlSettingsMenu.hpp"

#include <iostream>

enum class State
{
    MenuPage = 0,
    PlayPage,
    HighScorePage,
    UpdateHighScorePage,
    UpdateHighScore,
    Options,
    OptionsPage,
    DifficultyPage,
    VideoPage,
    ControlSettingPage,
    VolumePage,
    Exit,
    GameOver,
    BrickEmpty,
    BallOutOfBounds,
    NoHealth,
};

class GameState
{
public:
    GameState(int
        ,int
        , int
        , int
        , int
        , Video &
        , Difficulty &
        , Options &
        , Menu &
        , Ball &
        , Paddle &
        , WindowManager &
        , Resoloution &
        , ControlSettings&
        , VolumeManager&
        , ControlSettingsMenu &
    );
    int getHealth() const;
    int getLevel() const;
    int getScore() const;
    int getHighScore() const;
    int getMaxLevel() const;
    State getState() const;
    void setState(State);
    void setScore(int);
    void setHighScore(size_t);
    void reset();
    void decreaseHealth();
    void increaseScore();
    void nextLevel();
    void setBallSpeed_(float);
    float getBallSpeed_();
    void resetBallPos();
    void setControls(const std::string &, sf::Keyboard::Key);

    sf::Keyboard::Key getBallRelease() const;
    sf::Keyboard::Key getLeft() const;
    sf::Keyboard::Key getRight() const;
    

    Video& getVideo();
    Difficulty& getDifficulty();
    Options& getOptions();
    Menu& getMenu();
    WindowManager& getWindow();
    Resoloution& getResoloution();
    Paddle& getPaddle();
    VolumeManager& getVolumeManager();
    ControlSettingsMenu & getControlSettingsMenu();

    bool isBrickHit = false;
private:
    void resetScore();
    void resetHealth();
private:
    int m_health;
    int m_level;
    int m_max_level;
    int m_score;
    int m_high_score;
    State currentState = State::MenuPage;
    Video &m_video;
    Difficulty &m_difficulty;
    Options &m_options;
    Menu &m_menu;
    Ball &m_ball;
    Paddle &m_paddle;
    WindowManager &m_window;
    Resoloution &m_resoloution;
    ControlSettings &m_controlSettings;
    VolumeManager &m_volumeManager;
    ControlSettingsMenu &m_controlSettingsMenu;
};
