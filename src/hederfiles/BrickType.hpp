#pragma once

enum class BrickType {
    Indestructible,
    OneHit,
    TwoHits,
};

enum class BrickColor {
    RED,
    BLUE,
    YELLOW,
    GREEN,
    BLACK,
    WHITE,
    PURPLE,
    ORANGE,
    DEEP_ORANGE,
    PINK,
    GRAY,
    BLUE_SKY,
    BROWN,
};

struct BrickState
{
    BrickType brickType;
    BrickColor brickColor;
};

