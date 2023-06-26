#pragma once

#include "ControlSettings.hpp"
// #include "GameState.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class ControlSettingsMenu
{
public:
    ControlSettingsMenu(ControlSettings&, sf::RenderWindow&);
    void handleKeyPressedInput(const sf::Event&, sf::Vector2f&);
    void handleMouseMovedInput(sf::Vector2f& );
    ControlSettings& getControlSettings();
    void draw();
    void updateText(const sf::Vector2u&);
private:
    void initializeGUI();
    void updateControlText(const std::string&);
    std::string keyToString(sf::Keyboard::Key);
    void makeText(sf::Text &, sf::Font &, std::string, sf::Vector2i);
private:
    ControlSettings& m_controlSettings;
    std::string m_selectedControl;
    std::vector<std::pair<std::string, sf::Text*>> m_controlTexts;
    sf::RenderWindow &m_window;
    bool static m_isMusicPlayed;

    sf::Font m_font;
    sf::Text m_titleText;
    sf::Text m_ballReleaseText;
    sf::Text m_leftText;
    sf::Text m_rightText;
};
