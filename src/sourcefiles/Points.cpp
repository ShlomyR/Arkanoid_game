#include "../hederfiles/GameState.hpp"
#include "../hederfiles/Points.hpp"

Points::Points(GameState &gameState)
: m_gameState(gameState)
{
    
}

BrickColor &Points::getBrickColor()
{
    return CurrentBrickColor;
}

BrickType &Points::getBrickType()
{
    return CurrentBrickType;
}

void Points::setBrickColor(BrickColor brickColor)
{
    CurrentBrickColor = brickColor;
}

void Points::setBrickType(BrickType &brickType)
{
    CurrentBrickType = brickType;
}

void Points::assignedColorPointes(const std::string& color) 
{
    if (color == "Gray") {
        CurrentBrickColor = BrickColor::GRAY;
        m_gameState.setScore(50);
    } else if (color == "Red") {
        CurrentBrickColor = BrickColor::RED;
        m_gameState.setScore(90);
    } else if (color == "Blue") {
        CurrentBrickColor = BrickColor::BLUE;
        m_gameState.setScore(100);
    } else if (color == "Blue_sky") {
        CurrentBrickColor = BrickColor::BLUE_SKY;
        m_gameState.setScore(70);
    } else if (color == "Green") {
        CurrentBrickColor = BrickColor::GREEN;
        m_gameState.setScore(0);
    } else if (color == "Deep_orange") {
        CurrentBrickColor = BrickColor::DEEP_ORANGE;
        m_gameState.setScore(60);
    } else if (color == "Yellow") {
        CurrentBrickColor = BrickColor::YELLOW;
        m_gameState.setScore(80);
    } else if (color == "Orange") {
        CurrentBrickColor = BrickColor::ORANGE;
        m_gameState.setScore(120);
    } else if (color == "Pink") {
        CurrentBrickColor = BrickColor::PINK;
        m_gameState.setScore(110);
    } else if (color == "Brown") {
        CurrentBrickColor = BrickColor::BROWN;
        m_gameState.setScore(30);
    } else {
        throw std::runtime_error("This color dont exist");
    }
}
