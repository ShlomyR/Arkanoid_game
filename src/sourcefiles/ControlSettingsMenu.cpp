#include "ControlSettingsMenu.hpp"
#include "MenuScreenHandler.hpp"
#include "ControlSettings.hpp"
#include "SoundManager.hpp"

bool ControlSettingsMenu::m_isMusicPlayed;

ControlSettingsMenu::ControlSettingsMenu(ControlSettings& controlSettings, sf::RenderWindow &window, MenuScreenHandler &menuScreenHandler)
: m_controlSettings(controlSettings)
, m_window(window)
, m_menuScreenHandler(menuScreenHandler)
{
    initializeGUI();
}

std::string removeLastCharacter(const std::string& input) {
    if (input.empty()) {
        return "";
    } else {
        return input.substr(0, input.length() - 2);
    }
}

void ControlSettingsMenu::makeText(sf::Text &text, sf::Font &font, std::string str, sf::Vector2i vec2i)
{
    text.setFont(font);
    text.setCharacterSize(48);
    text.setFillColor(sf::Color{128,128,128});
    text.setString(removeLastCharacter(str));
    text.setScale(0.5, 0.5);
    text.setPosition(vec2i.x,vec2i.y);
    updateControlText(removeLastCharacter(str));
    m_controlTexts.emplace_back(removeLastCharacter(str), &text);       
}

ControlSettings& ControlSettingsMenu::getControlSettings()
{
    return m_controlSettings;
}

void ControlSettingsMenu::initializeGUI()
{
    if (!m_font.loadFromFile("src/fonts/DIN.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
    }
    makeText(m_releaseActiveButton, m_font, "pp", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, 100));
    makeText(m_leftActiveButton, m_font, "pp", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, 200));
    makeText(m_rightActiveButton, m_font, "pp", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, 300));
    makeText(m_ballReleaseText, m_font, "Release Ball: ", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getReleaseButtonShape().getPosition().y + m_menuScreenHandler.getReleaseButtonShape().getSize().y/2 - 10));
    makeText(m_leftText, m_font, "Move Paddle Left: ", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getMoveLeftButtonShape().getPosition().y + m_menuScreenHandler.getMoveLeftButtonShape().getSize().y/2 - 10));
    makeText(m_rightText, m_font, "Move Paddle Right: ", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getMoveRightButtonShape().getPosition().y + m_menuScreenHandler.getMoveRightButtonShape().getSize().y/2 - 10));
}

void ControlSettingsMenu::draw()
{
    m_window.draw(m_ballReleaseText);
    m_window.draw(m_leftText);
    m_window.draw(m_rightText);
    m_window.draw(m_releaseActiveButton);
    m_window.draw(m_leftActiveButton);
    m_window.draw(m_rightActiveButton);
}

void ControlSettingsMenu::updateText(const sf::Vector2u &)
{
    m_releaseActiveButton.setPosition(m_menuScreenHandler.getReleaseButtonShape().getPosition().x +10,m_menuScreenHandler.getReleaseButtonShape().getPosition().y+10);
    m_leftActiveButton.setPosition(m_menuScreenHandler.getMoveLeftButtonShape().getPosition().x +10,m_menuScreenHandler.getMoveLeftButtonShape().getPosition().y+10);
    m_rightActiveButton.setPosition(m_menuScreenHandler.getMoveRightButtonShape().getPosition().x +10,m_menuScreenHandler.getMoveRightButtonShape().getPosition().y+10);
    m_ballReleaseText.setPosition(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getReleaseButtonShape().getPosition().y + m_menuScreenHandler.getReleaseButtonShape().getSize().y/2 - 10);
    m_leftText.setPosition(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getMoveLeftButtonShape().getPosition().y + m_menuScreenHandler.getMoveLeftButtonShape().getSize().y/2 - 10);
    m_rightText.setPosition(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getMoveRightButtonShape().getPosition().y + m_menuScreenHandler.getMoveRightButtonShape().getSize().y/2 - 10);
}

void ControlSettingsMenu::handleMouseMovedInput(sf::Vector2f& mousePosition)
{
    bool isMouseHovering = false;
    for (auto& controlText : m_controlTexts) {
        if (controlText.second->getGlobalBounds().contains(mousePosition)) {
            isMouseHovering = true;
            controlText.second->setOutlineColor(sf::Color::White);
            controlText.second->setFillColor(sf::Color::White);
            controlText.second->setOutlineThickness(2);
        } else {
            controlText.second->setOutlineColor(sf::Color{128,128,128});
            controlText.second->setOutlineThickness(0);
            controlText.second->setFillColor(sf::Color{128,128,128});
        }
    }

    if (isMouseHovering && !m_isMusicPlayed) {
        SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
        m_isMusicPlayed = true;
    } else if (!isMouseHovering) {
        m_isMusicPlayed = false;
    }
}

void ControlSettingsMenu::handleKeyPressedInput(const sf::Event& event, sf::Vector2f& mousePosition)
{
    for (auto& controlText : m_controlTexts) {
        if (controlText.second->getGlobalBounds().contains(mousePosition)) {
            sf::Keyboard::Key pressedKey = event.key.code;
            bool keyExists = false;
            for (auto& existingText : m_controlTexts) {
                if (existingText.first != controlText.first && m_controlSettings.getMapping(existingText.first) == pressedKey) {
                    m_controlSettings.updateMapping(existingText.first, sf::Keyboard::Unknown);
                    updateControlText(existingText.first);
                    keyExists = true;
                    break;
                }
            }
            m_controlSettings.updateMapping(controlText.first, pressedKey);
            updateControlText(controlText.first);

            if (keyExists) {
                SoundManager::getInstance()->playSound("src/sounds/replace_key_sound.wav");
            } else {
                SoundManager::getInstance()->playSound("src/sounds/assign_key_sound.wav");
            }
        }
    }
}

void ControlSettingsMenu::updateControlText(const std::string& control) {
    sf::Text* text = nullptr;

    if (control == "Release Ball") {
        text = &m_ballReleaseText;
        m_releaseActiveButton.setPosition(m_menuScreenHandler.getReleaseButtonShape().getPosition().x +10,m_menuScreenHandler.getReleaseButtonShape().getPosition().y+10);
    } else if (control == "Move Paddle Left") {
        text = &m_leftText;
        m_leftActiveButton.setPosition(m_menuScreenHandler.getMoveLeftButtonShape().getPosition().x +10,m_menuScreenHandler.getMoveLeftButtonShape().getPosition().y+10);
    } else if (control == "Move Paddle Right") {
        text = &m_rightText;
        m_rightActiveButton.setPosition(m_menuScreenHandler.getMoveRightButtonShape().getPosition().x +10,m_menuScreenHandler.getMoveRightButtonShape().getPosition().y+10);
    }

    if (text) {
        sf::Keyboard::Key key = m_controlSettings.getMapping(control);
        std::string keyString = keyToString(key);
        if (control == "Release Ball") {
           m_releaseActiveButton.setString(keyString);
        } else if (control == "Move Paddle Left") {
            m_leftActiveButton.setString(keyString);
        } else if (control == "Move Paddle Right") {
            m_rightActiveButton.setString(keyString);
        }

        if (control == m_selectedControl) {
            keyString = "Press any key...";
        }

        text->setString(control + ": ");
    }
}

std::string ControlSettingsMenu::keyToString(sf::Keyboard::Key key) {
    static const std::map<sf::Keyboard::Key, std::string> keyToStringMap = {
        { sf::Keyboard::Unknown, "Unknown" },
        { sf::Keyboard::A, "A" },
        { sf::Keyboard::B, "B" },
        { sf::Keyboard::C, "C" },
        { sf::Keyboard::D, "D" },
        { sf::Keyboard::E, "E" },
        { sf::Keyboard::F, "F" },
        { sf::Keyboard::G, "G" },
        { sf::Keyboard::H, "H" },
        { sf::Keyboard::I, "I" },
        { sf::Keyboard::J, "J" },
        { sf::Keyboard::K, "K" },
        { sf::Keyboard::L, "L" },
        { sf::Keyboard::M, "M" },
        { sf::Keyboard::N, "N" },
        { sf::Keyboard::O, "O" },
        { sf::Keyboard::P, "P" },
        { sf::Keyboard::Q, "Q" },
        { sf::Keyboard::R, "R" },
        { sf::Keyboard::S, "S" },
        { sf::Keyboard::T, "T" },
        { sf::Keyboard::U, "U" },
        { sf::Keyboard::V, "V" },
        { sf::Keyboard::W, "W" },
        { sf::Keyboard::X, "X" },
        { sf::Keyboard::Y, "Y" },
        { sf::Keyboard::Z, "Z" },
        { sf::Keyboard::Num0, "Num0" },
        { sf::Keyboard::Num1, "Num1" },
        { sf::Keyboard::Num2, "Num2" },
        { sf::Keyboard::Num3, "Num3" },
        { sf::Keyboard::Num4, "Num4" },
        { sf::Keyboard::Num5, "Num5" },
        { sf::Keyboard::Num6, "Num6" },
        { sf::Keyboard::Num7, "Num7" },
        { sf::Keyboard::Num8, "Num8" },
        { sf::Keyboard::Num9, "Num9" },
        { sf::Keyboard::Escape, "Escape" },
        { sf::Keyboard::LControl, "LControl" },
        { sf::Keyboard::LShift, "LShift" },
        { sf::Keyboard::LAlt, "LAlt" },
        { sf::Keyboard::LSystem, "LSystem" },
        { sf::Keyboard::RControl, "RControl" },
        { sf::Keyboard::RShift, "RShift" },
        { sf::Keyboard::RAlt, "RAlt" },
        { sf::Keyboard::RSystem, "RSystem" },
        { sf::Keyboard::Menu, "Menu" },
        { sf::Keyboard::LBracket, "LBracket" },
        { sf::Keyboard::RBracket, "RBracket" },
        { sf::Keyboard::SemiColon, "SemiColon" },
        { sf::Keyboard::Comma, "Comma" },
        { sf::Keyboard::Period, "Period" },
        { sf::Keyboard::Quote, "Quote" },
        { sf::Keyboard::Slash, "Slash" },
        { sf::Keyboard::BackSlash, "BackSlash" },
        { sf::Keyboard::Tilde, "Tilde" },
        { sf::Keyboard::Equal, "Equal" },
        { sf::Keyboard::Dash, "Dash" },
        { sf::Keyboard::Space, "Space" },
        { sf::Keyboard::Return, "Return" },
        { sf::Keyboard::BackSpace, "BackSpace" },
        { sf::Keyboard::Tab, "Tab" },
        { sf::Keyboard::PageUp, "PageUp" },
        { sf::Keyboard::PageDown, "PageDown" },
        { sf::Keyboard::End, "End" },
        { sf::Keyboard::Home, "Home" },
        { sf::Keyboard::Insert, "Insert" },
        { sf::Keyboard::Delete, "Delete" },
        { sf::Keyboard::Add, "Add" },
        { sf::Keyboard::Subtract, "Subtract" },
        { sf::Keyboard::Multiply, "Multiply" },
        { sf::Keyboard::Divide, "Divide" },
        { sf::Keyboard::Left, "Left" },
        { sf::Keyboard::Right, "Right" },
        { sf::Keyboard::Up, "Up" },
        { sf::Keyboard::Down, "Down" },
        { sf::Keyboard::Numpad0, "Numpad0" },
        { sf::Keyboard::Numpad1, "Numpad1" },
        { sf::Keyboard::Numpad2, "Numpad2" },
        { sf::Keyboard::Numpad3, "Numpad3" },
        { sf::Keyboard::Numpad4, "Numpad4" },
        { sf::Keyboard::Numpad5, "Numpad5" },
        { sf::Keyboard::Numpad6, "Numpad6" },
        { sf::Keyboard::Numpad7, "Numpad7" },
        { sf::Keyboard::Numpad8, "Numpad8" },
        { sf::Keyboard::Numpad9, "Numpad9" },
        { sf::Keyboard::F1, "F1" },
        { sf::Keyboard::F2, "F2" },
        { sf::Keyboard::F3, "F3" },
        { sf::Keyboard::F4, "F4" },
        { sf::Keyboard::F5, "F5" },
        { sf::Keyboard::F6, "F6" },
        { sf::Keyboard::F7, "F7" },
        { sf::Keyboard::F8, "F8" },
        { sf::Keyboard::F9, "F9" },
        { sf::Keyboard::F10, "F10" },
        { sf::Keyboard::F11, "F11" },
        { sf::Keyboard::F12, "F12" },
        { sf::Keyboard::F13, "F13" },
        { sf::Keyboard::F14, "F14" },
        { sf::Keyboard::F15, "F15" },
        { sf::Keyboard::Pause, "Pause" }
    };

    auto it = keyToStringMap.find(key);
    if (it != keyToStringMap.end()) {
        return it->second;
    } else {
        return "Unknown";
    }
}
