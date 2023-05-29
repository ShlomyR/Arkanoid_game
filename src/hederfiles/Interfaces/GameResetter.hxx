#pragma once

class GameResetter
{
public:
    virtual ~GameResetter() = default;
    virtual void resetGameOver() = 0;
    virtual void reset() = 0;
};
