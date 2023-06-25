// #pragma once

// #include "MenuScreenHandler.hpp"
// #include "ControlSettings.hpp"
// #include "SoundManager.hpp"
// #include "ControlTypeHandler.hxx"

// #include <SFML/Graphics.hpp>
// #include <iostream>
// #include <map>
// #include <variant>
// #include <vector>

// class KeyboardControlHandler : public ControlTypeHandler 
// {
// public:
//     KeyboardControlHandler() {}
//     void handleInput(sf::Event event, sf::Vector2f& mousePosition);
//     void update(const sf::Vector2u& windowSize);
//     void draw();

// private:
//     // ControlSettings& m_controlSettings;
//     // sf::RenderWindow& m_window;
//     // MenuScreenHandler& m_menuScreenHandler;
//     sf::Font m_font;
//     sf::Text m_ballReleaseText;
//     sf::Text m_leftText;
//     sf::Text m_rightText;
//     sf::Text m_releaseActiveButton;
//     sf::Text m_leftActiveButton;
//     sf::Text m_rightActiveButton;
//     std::vector<std::pair<std::string, sf::Text*>> m_controlTexts;
//     std::string m_selectedControl;
//     bool m_isMusicPlayed;

//     std::string removeLastCharacter(const std::string& input);
//     void makeText(sf::Text& text, sf::Font& font, std::string str, sf::Vector2i vec2i);
//     void initializeGUI();
//     void updateText(const sf::Vector2u& windowSize);
//     void handleMouseMovedInput(sf::Vector2f& mousePosition);
//     void handleKeyPressedInput(const sf::Event& event, sf::Vector2f& mousePosition);
//     void updateControlText(const std::string& control);
//     std::string keyToString(sf::Keyboard::Key key);
// };
