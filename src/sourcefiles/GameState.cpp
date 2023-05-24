#include "../hederfiles/GameState.hpp"
#include "GameState.hpp"

GameState::GameState(int health, int level, int score, int high_score, int maxLevel)
: m_health(health)
, m_level(level)
, m_max_level(maxLevel)
, m_score(score)
, m_high_score(high_score)
{

}

int GameState::getHealth() const {
    return m_health;
}

int GameState::getLevel() const {
    return m_level;
}

int GameState::getScore() const {
    return m_score;
}

int GameState::getHighScore() const
{
    return m_high_score;
}

int GameState::getMaxLevel() const
{
    return m_max_level;
}

State GameState::getState() const
{
    return currentState;
}

void GameState::setState(State state)
{
    currentState = state;
}

void GameState::setScore(int value)
{
    m_score += value;
}

void GameState::setHighScore(size_t new_high_score)
{
    m_high_score = new_high_score;
}

void GameState::reset()
{
    resetScore();
    resetHealth();
    m_level = 0;
}

void GameState::decreaseHealth()
{
    --m_health;
}

void GameState::increaseScore() {
    m_score += 10;
}

void GameState::resetScore()
{
    m_score = 0;
}

void GameState::resetHealth()
{
    m_health = 3;
}

void GameState::nextLevel()
{
    ++m_level;
}