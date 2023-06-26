#include "LevelCommand.hpp"
#include "CreateLevel.hpp"
#include "WhileCommand.hpp"

#include <iostream>
#include <string>
#include <vector>

void LevelCommand::DoCommand(std::vector<std::string> const&line)
{
    std::string pos = line[1];
    std::string containerType = line[2];
    std::string str = line[3];
    CreateLevel cl;
    WhileCommand wc;
    cl.create(wc.getStringVal(pos), wc.getStringVal(containerType), wc.getStringVal(str));
    
}