#pragma once

#include <iostream>

enum class State
{
    MenuPage = 0,
    PlayPage,
    HighScorePage,
    UpdateHighScorePage,
    UpdateHighScore,
    Exit,
    GameOver,
    BrickEmpty,
    BallOutOfBounds,
    NoHealth,
};

class GameState
{
public:
    GameState(int health, int level, int score, int high_score, int maxLevel);
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
};
