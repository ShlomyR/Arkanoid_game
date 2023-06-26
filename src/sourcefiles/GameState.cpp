#include "GameState.hpp"


GameState::GameState(int health, int level, int score, int high_score, int maxLevel, Video &video, Difficulty &difficulty, Options &options, Menu &menu, Ball &ball, Paddle &paddle, WindowManager &window, Resoloution &resoloution, ControlSettings &controlSettings)
: m_health(health)
, m_level(level)
, m_max_level(maxLevel)
, m_score(score)
, m_high_score(high_score)
, m_video(video)
, m_difficulty(difficulty)
, m_options(options)
, m_menu(menu)
, m_ball(ball)
, m_paddle(paddle)
, m_window(window)
, m_resoloution(resoloution)
, m_controlSettings(controlSettings)
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

void GameState::setBallSpeed_(float f)
{
    m_ball.setBallSpeed(f);
}

float GameState::getBallSpeed_()
{
    return m_ball.getBallSpeed();   
}

Video &GameState::getVideo()
{
    return m_video;
}

void GameState::setHighScore(size_t new_high_score)
{
    m_high_score = new_high_score;
}

void GameState::resetBallPos()
{
    m_ball.setPosition(m_paddle.getCenterPosition().x, m_paddle.getCenterPosition().y);
}

void GameState::reset()
{
    resetScore();
    resetHealth();
    resetBallPos();
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

Difficulty& GameState::getDifficulty()
{
    return m_difficulty;
}

Options &GameState::getOptions()
{
    return m_options;
}

Menu& GameState::getMenu()
{
    return m_menu;
}

WindowManager& GameState::getWindow()
{
    return m_window;
}

Resoloution &GameState::getResoloution()
{
    return m_resoloution;
}

Paddle& GameState::getPaddle()
{
    return m_paddle;
}

sf::Keyboard::Key GameState::getBallRelease() const
{
    return m_controlSettings.getMapping("Release Ball");
}

sf::Keyboard::Key GameState::getLeft() const
{
    return m_controlSettings.getMapping("Move Paddle Left");
}

sf::Keyboard::Key GameState::getRight() const
{
    return m_controlSettings.getMapping("Move Paddle Right");
}

// void GameState::setControls(const std::string &str, sf::Keyboard::Key key)
// {
//     m_controlSettings.updateMapping(str,key);
// }
