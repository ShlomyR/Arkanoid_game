#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>

class ControlSettings
{
public:
    ControlSettings();

    void updateMapping(const std::string& action, sf::Keyboard::Key key);
    sf::Keyboard::Key getMapping(const std::string& action);
    void defaultMappings();

private:
    std::unordered_map<std::string, sf::Keyboard::Key> m_controlMappings;
};
