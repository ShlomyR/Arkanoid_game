#pragma once

#include <SFML/Graphics.hpp>

struct BrickLevel
{
    std::string color;
    sf::Sprite sprite;
}; 

enum class BrickType
{
    Indestructible,
    OneHit,
    TwoHits,
};

enum class BrickColor
{
    GRAY,
    RED,
    BLUE,
    BLUE_SKY,
    GREEN,
    DEEP_ORANGE,
    ORANGE,
    YELLOW,
    PINK,
    BROWN,
    GREEN_BRIGHT,
};

struct BrickState
{
    BrickType brickType;
    BrickColor brickColor;
};
