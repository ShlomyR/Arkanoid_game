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

void ControlSettings::defaultMappings()
{
    m_controlMappings["Right"] = sf::Keyboard::Right;
    m_controlMappings["Left"] = sf::Keyboard::Left;
    m_controlMappings["Space"] = sf::Keyboard::Space;
}
