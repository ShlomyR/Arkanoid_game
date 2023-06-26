#include "WhileCommand.hpp"
#include "MapException.hpp"
#include "SymbolVar.hpp"
#include "WhileLoop.hpp"
#include "Parse.hpp"

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

void WhileCommand::DoCommand(std::vector<std::string> const&line)
{
    WhileLoop::whileLoop(line);
}

double WhileCommand::getVal(std::vector<std::string> const& line)
{
    return getValueFromMap(SymbolVar::getInstance()->getMapDouble(), SymbolVar::getInstance()->getMapStr().at(line[1]), "map_doubleDB");
}

double WhileCommand::getVal(std::string const& word)
{
    return getValueFromMap(SymbolVar::getInstance()->getMapDouble(), word, "map_doubleDB");
}

std::string WhileCommand::getStringVal(std::vector<std::string> const& line)
{
    return getValueFromMap(SymbolVar::getInstance()->getMapStr(), line[3], "map_strDB");
}

std::string WhileCommand::getStringVal(std::string const& word)
{
    return getValueFromMap(SymbolVar::getInstance()->getMapStr(), word, "map_strDB");
}

template <typename T>
T WhileCommand::getValueFromMap(const std::unordered_map<std::string, T>& map, const std::string& key, const std::string& mapName)
{
    T defaultValue;

    try {
        if (map.count(key)) {
            return map.at(key);
        } else {
            throw MapException("Error: " + key + " not found in " + mapName + ".", std::string(__FILE__) + ":" + std::to_string(__LINE__));
        }
    } catch (const MapException& me) {
        std::cout << me.what() << " at line " << me.where() << "\n";

        // Set defaultValue based on the type T
        if constexpr (std::is_same<T, std::string>::value) {
            defaultValue = "";
        } else if constexpr (std::is_arithmetic<T>::value) {
            defaultValue = T();
        } else {
            // Handle unsupported type T
            defaultValue = T(); // You can modify this line to set an appropriate default value
        }

        return defaultValue;
    }

    return defaultValue;
}

