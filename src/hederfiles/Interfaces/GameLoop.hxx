#pragma once


class GameLoop
{
public:
    virtual ~GameLoop() = default;
    virtual void run() = 0;
};
