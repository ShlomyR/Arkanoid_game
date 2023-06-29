#include "ControlSettings.hpp"
#include <iostream>

ControlSettings::ControlSettings()
{
    defaultMappings();
}

void ControlSettings::updateMapping(const std::string& action, sf::Keyboard::Key key)
{
    m_controlMappings[action] = key;
}

sf::Keyboard::Key ControlSettings::getMapping(const std::string& action)
{
    return m_controlMappings[action];
}

void ControlSettings::updatePs4Mapping(const std::string& action, size_t key)
{
    m_controlMappingsPs4[action] = key;
}

size_t ControlSettings::getPs4Mapping(const std::string& action)
{
    return m_controlMappingsPs4[action];
}

void ControlSettings::defaultMappings()
{
    m_controlMappings["Move Paddle Left"] = sf::Keyboard::Left;
    m_controlMappings["Move Paddle Right"] = sf::Keyboard::Right;
    m_controlMappings["Release Ball"] = sf::Keyboard::Space;
    m_controlMappingsPs4["Move Paddle Left"] = 4;
    m_controlMappingsPs4["Move Paddle Right"] = 5;
    m_controlMappingsPs4["Release Ball"] = 2;
}
