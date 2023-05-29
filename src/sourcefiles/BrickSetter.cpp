#include "BrickSetter.hpp"

BrickSetter *BrickSetter::getInstance()
{
    static BrickSetter instance;
    return &instance;
}

void BrickSetter::setBricks(std::vector<BrickLevel>& bricks)
{
    m_bricks.push_back(bricks);
}

std::vector<std::vector<BrickLevel>> BrickSetter::getBricks()
{
    return m_bricks;
}
