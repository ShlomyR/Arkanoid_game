#include "ContainerHandler.hpp"
#include "BrickTextures.hpp"
#include "CreateLevel.hpp"
#include "BrickSetter.hpp"

#include <vector>
#include <string>


void CreateLevel::create(std::string pos, std::string const containerType, std::string const str)
{
    std::vector<int> numOfBricks;
    std::vector<std::string> colorOfBricks;
    std::vector<std::string> directionOfBricks;
    std::vector<BrickLevel> spriteBricks;

    ContainerHandler ch;
    auto level = ch.createLevel(str, containerType, numOfBricks, colorOfBricks, directionOfBricks);
    static BrickTextures brickTextures;
    brickTextures.createBrickSprites(spriteBricks, pos, level);
}
