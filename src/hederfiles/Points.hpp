#pragma once

#include "BrickType.hpp"
class GameState;

#include <SFML/Audio.hpp>

class Points
{
public:
    Points(GameState &);
    ~Points() = default;
    // geter
    BrickColor &getBrickColor();
    BrickType &getBrickType();
    // seter
    void setBrickColor(BrickColor );
    void setBrickType(BrickType &);

    void assignedColorPointes(const std::string &);

private:
    GameState &m_gameState;
    BrickColor CurrentBrickColor = BrickColor::BLACK;
    BrickType CurrentBrickType = BrickType::Indestructible;
};
