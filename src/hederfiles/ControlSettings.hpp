#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <variant>

class ControlSettings
{
public:
    ControlSettings();

    void updateMapping(const std::string& action, sf::Keyboard::Key key);
    sf::Keyboard::Key getMapping(const std::string& action);
    sf::Joystick::Axis getPs4Mapping(const std::string&);
    void defaultMappings();

private:
    std::unordered_map<std::string, sf::Keyboard::Key> m_controlMappings;
    std::unordered_map<std::string, sf::Joystick::Axis> m_controlMappingsPs4;
    std::unordered_map<std::string, int> m_controlMappingsXbox;
};
