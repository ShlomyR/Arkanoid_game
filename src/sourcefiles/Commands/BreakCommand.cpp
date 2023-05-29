#include "MapException.hpp"
#include "BreakCommand.hpp"
#include "SymbolVar.hpp"
#include "Parse.hpp"

#include <iostream>
#include <string>
#include <vector>

void BreakCommand::DoCommand(std::vector<std::string> const&line)
{
    breakFunc(line);
}

void BreakCommand::breakFunc(std::vector<std::string> const&)
{
    auto &varStringMap = SymbolVar::getInstance()->getMapStr();
    try {
        if ( varStringMap.count("breakLoop")) {
            varStringMap.at("breakLoop") = "true";
        } else {
            throw MapException("Error: " + std::string("breakLoop") + " not found in map_strDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
        }
    } catch (const MapException& me) {
        std::cout << me.what() << " at line " << me.where() << "\n";
    }
}