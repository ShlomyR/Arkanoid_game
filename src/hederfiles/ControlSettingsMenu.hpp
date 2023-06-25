#pragma once

#include "ControlSettings.hpp"
// #include "GameState.hpp"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class MenuScreenHandler;

class ControlSettingsMenu
{
public:
    ControlSettingsMenu(ControlSettings&, sf::RenderWindow&, MenuScreenHandler &);
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
    sf::RenderWindow &m_window;
    MenuScreenHandler &m_menuScreenHandler;
    std::string m_selectedControl;
    std::vector<std::pair<std::string, sf::Text*>> m_controlTexts;

    bool static m_isMusicPlayed;

    sf::Font m_font;
    sf::Text m_titleText;
    sf::Text m_ballReleaseText;
    sf::Text m_leftText;
    sf::Text m_rightText;

    sf::Text m_releaseActiveButton;
    sf::Text m_leftActiveButton;
    sf::Text m_rightActiveButton;
};
