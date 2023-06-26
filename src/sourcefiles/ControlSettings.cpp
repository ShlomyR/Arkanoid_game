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

sf::Joystick::Axis ControlSettings::getPs4Mapping(const std::string& action)
{
    return m_controlMappingsPs4[action];
}

void ControlSettings::defaultMappings()
{
    m_controlMappings["Move Paddle Left"] = sf::Keyboard::Left;
    m_controlMappings["Move Paddle Right"] = sf::Keyboard::Right;
    m_controlMappings["Release Ball"] = sf::Keyboard::Space;
    m_controlMappingsPs4["Move Paddle Left"] = sf::Joystick::U;
    m_controlMappingsPs4["Move Paddle Right"] = sf::Joystick::V;
    m_controlMappingsPs4["Release Ball"] = sf::Joystick::R;
    // m_controlMappingsPs4["Release Ball"] = 0;
}
