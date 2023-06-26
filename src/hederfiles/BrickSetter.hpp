#pragma once

#include "BrickType.hpp"

class BrickSetter
{
public:
    static BrickSetter *getInstance();
    void setBricks(std::vector<BrickLevel>&);
    std::vector<std::vector<BrickLevel>> getBricks();
    void deleteAllBricks();
private:
    BrickSetter() = default;
private:
    std::vector<std::vector<BrickLevel>> m_bricks;
};
