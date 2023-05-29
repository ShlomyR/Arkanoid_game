#pragma once

#include "BrickType.hpp"
class GameState;

#include <SFML/Audio.hpp>

class Points
{
public:
    Points(GameState &);
    ~Points() = default;
    BrickColor &getBrickColor();
    BrickType &getBrickType();
    void setBrickColor(BrickColor );
    void setBrickType(BrickType &);
    void assignedColorPointes(const std::string &);
private:
    GameState &m_gameState;
    BrickColor CurrentBrickColor = BrickColor::GREEN;
    BrickType CurrentBrickType = BrickType::Indestructible;
};