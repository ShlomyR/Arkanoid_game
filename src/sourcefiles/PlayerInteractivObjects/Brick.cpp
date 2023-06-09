#include "Brick.hpp"
#include "BrickSetter.hpp"
#include "GameState.hpp"
#include "SoundManager.hpp"

#include <thread>
#include <unistd.h>

Brick::Brick(const sf::Vector2f &size, const sf::Vector2f &position, const sf::Color &color,GameState &gameState)
: m_shape(std::make_unique<sf::RectangleShape>(size))
, m_gameState(gameState)
, m_currentLevel(m_gameState.getLevel())
{
    m_shape->setFillColor(sf::Color::Green);
    m_shape->setOutlineColor(color);
    m_shape->setOutlineThickness(1.f);
    setPosition(position.x, position.y);
}

void Brick::move(float x, float y)
{
    m_shape->move(x, y);
}

void Brick::setPosition(float x, float y)
{
    m_shape->setPosition(x, y);
}

void Brick::draw(sf::RenderWindow &window)
{
    // getCurrLevelBricks()[0][0][0].sprite.setPosition(sf::Vector2f(110.f,60.f));
    for (size_t i = 0; i < m_levels[m_currentLevel].size(); i++) {
        window.draw(m_levels[m_currentLevel][i].sprite);
    }
}

sf::Vector2f Brick::getPosition() const
{
    return m_shape->getPosition();
}

float Brick::getRadius() const
{
    return 0.f;
}

std::vector<std::vector<BrickLevel>> Brick::getVecBricks()
{
    return m_levels;
}

std::unique_ptr<sf::RectangleShape> &Brick::getShape()
{
    return m_shape;
}


void Brick::init()
{
    m_levels = BrickSetter::getInstance()->getBricks();
}

void Brick::initializeLevels()
{
    init();
    m_currentLevel = 0;
}

void Brick::initVec()
{
    m_gameState.getResoloution().setVec(BrickSetter::getInstance()->getBricks());   
}

void Brick::deleteBrick(int i)
{
    SoundManager::getInstance()->playSound("src/sounds/pop2.ogg");
    this->m_levels[m_currentLevel].erase(m_levels[m_currentLevel].begin() + i);
}

BrickLevel Brick::getBrick(int i)
{
    return m_levels[m_currentLevel][i];   
}

std::vector<std::vector<BrickLevel>>* Brick::getCurrLevelBricks()
{
    return &m_levels;   
}

bool Brick::isEmpty()
{
    if (m_bricks.empty()) {
        return true;
    } else {
        return false;
    }
}

BrickColor Brick::getColor() const
{
    return m_color;
}

int const &Brick::getCurrLevel()
{
    return m_currentLevel;
}

void Brick::setCurrLevel(int val)
{
    m_currentLevel = val;
}

void Brick::deleteAllBricks()
{
    m_levels.clear();
}
