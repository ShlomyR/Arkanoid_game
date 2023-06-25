#include "InputHandlerImpl.hpp"
#include "GameState.hpp"
#include "Options.hpp"
#include "Menu.hpp"
#include "Hud.hpp"
#include "Difficulty.hpp"
#include "Video.hpp"
#include "SoundManager.hpp"
#include "VolumeManager.hpp"
#include "MenuScreenHandler.hpp"

#include <iostream>
#include <thread>
#include <fstream>

#ifdef _WIN32
    #define NEWLINE_CHAR '\r'  // Windows uses '\r\n'
#elif defined(__APPLE__)
    #define NEWLINE_CHAR '\n'  // macOS uses '\n'
#elif defined(__linux__)
    #define NEWLINE_CHAR '\r'  // Linux uses '\n'
#else
    #error Unsupported operating system
#endif

void deleteKeysExceptEscape(std::unordered_map<sf::Keyboard::Key, std::function<void ()>>& keyMap) {
    auto it = keyMap.begin();
    while (it != keyMap.end()) {
        if (it->first != sf::Keyboard::Escape) {
            it = keyMap.erase(it);
        } else {
            ++it;
        }
    }
}

bool InputHandlerImpl::m_isMusicPlayed;

void InputHandlerImpl::printVector(std::unordered_map<sf::Keyboard::Key, std::function<void ()>>& keyMap) {
    auto it = keyMap.begin();
    while (it != keyMap.end()) {
        std::cout << "key: " << keyToString(it->first) << "\n";
        ++it;
    }
}

void InputHandlerImpl::func()
{
    sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
    float joystickAxisX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
    float joystickAxisY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    float mouseSpeed = 0.5f;

    // Calculate the mouse movement delta based on joystick input and mouse speed
    sf::Vector2i mouseDelta(
        static_cast<int>(joystickAxisX * mouseSpeed),
        static_cast<int>(joystickAxisY * mouseSpeed)
    );

    // Update the new mouse position based on the delta
    mousePosition += mouseDelta;

    // Clamp the mouse position within the window bounds
    mousePosition.x = std::max(0, std::min(mousePosition.x, static_cast<int>(m_window.getSize().x)));
    mousePosition.y = std::max(0, std::min(mousePosition.y, static_cast<int>(m_window.getSize().y)));

    // Set the new mouse position
    sf::Mouse::setPosition(mousePosition);
}


InputHandlerImpl::InputHandlerImpl(sf::RenderWindow &window
    , PaddleArrowsHandnling &paddle_keys
    , GameState &gameState
    , Menu &menu
    , Options &options
    , Difficulty &difficulty
    , Video &video
    , Hud &hud
    , ControlSettingsMenu &controlSettingsMenu
    , VolumeManager &volume
    , MenuScreenHandler &menuScreenHandler
)
: m_window(window)
, m_paddle_keys(paddle_keys)
, m_gameState(gameState)
, m_menu(menu)
, m_options(options)
, m_difficulty(difficulty)
, m_video(video)
, m_hud(hud)
, m_controlSettingsMenu(controlSettingsMenu)
, m_volume(volume)
, m_WindowArrowsKey(m_window,m_gameState)
, m_menuScreenHandler(menuScreenHandler)
, m_mouse(m_menu,options,m_difficulty,m_video, m_menuScreenHandler)
{
    initMap();
    m_isSelected = false;
    m_gameState.setHighScore(m_hud.getHighScoreManager().getData(0).score);
}

void InputHandlerImpl::handleInput()
{
    while (m_window.pollEvent(m_event)) {
        switch (m_event.type) {
            case sf::Event::Closed:
                m_window.close();
                break;
            case sf::Event::KeyPressed:
                performKeyAction(m_event);
                updateKeyPressedControlSettingPage();
                break;
            case sf::Event::JoystickMoved:
                performPs4AxisAction(m_event);
                break;
            case sf::Event::JoystickButtonPressed:
                performPs4Action(m_event);
                if (m_gameState.getState() == State::VolumePage) {
                    m_volume.updateMousePrest(m_mousePosition);
                }
                break;
            case sf::Event::MouseButtonPressed:
                performMouseAction(m_event);
                if (m_gameState.getState() == State::VolumePage) {
                    m_volume.updateMousePrest(m_mousePosition);
                }

                break;
            case sf::Event::MouseMoved:
                m_window.setMouseCursorVisible(true);
                m_mousePosition = m_window.mapPixelToCoords(sf::Vector2i(m_event.mouseMove.x, m_event.mouseMove.y));
                updateMouseMovedControlSettingPage();
                break;
            case sf::Event::TextEntered:
                if (m_gameState.getState() == State::UpdateHighScorePage) {
                    checkEventUnderTenCharacter();
                    checkEventDeleteCharacter();
                    checkEventEnterName();
                }
                break;
            default:
                break;
        }
    }
}

sf::Vector2f &InputHandlerImpl::getMousePosition()
{
    return m_mousePosition;
}

bool InputHandlerImpl::isHandlerSelected()
{
    return m_isSelected;
}

void InputHandlerImpl::setIsSelected(bool value)
{
    m_isSelected = value;
}

void InputHandlerImpl::initMap()
{
    // keys map
    m_keys_action_map[sf::Keyboard::Escape] = [this]() { m_WindowArrowsKey.escape(); };
    m_keys_action_map[m_controlSettingsMenu.getControlSettings().getMapping("Move Paddle Left")] = [this]() { m_paddle_keys.left(); };
    m_keys_action_map[m_controlSettingsMenu.getControlSettings().getMapping("Move Paddle Right")] = [this]() { m_paddle_keys.right(); };
    m_keys_action_map[m_controlSettingsMenu.getControlSettings().getMapping("Release Ball")] = [this]() { m_paddle_keys.space(); };

    m_keys_action_map[sf::Keyboard::Up] = [this]() { m_WindowArrowsKey.up(); };
    m_keys_action_map[sf::Keyboard::Down] = [this]() { m_WindowArrowsKey.down(); };
    m_keys_action_map[sf::Keyboard::Return] = [this]() { m_mouse.left(false); };
    // Testing
    // m_keys_action_map[sf::Keyboard::Q] = [this]() { m_gameState.setState(State::MenuPage); };
    // m_keys_action_map[sf::Keyboard::A] = [this]() { m_gameState.setState(State::PlayPage); };
    // m_keys_action_map[sf::Keyboard::Z] = [this]() { m_gameState.setState(State::HighScorePage); };
    // m_keys_action_map[sf::Keyboard::W] = [this]() { m_gameState.setState(State::UpdateHighScorePage); };
    // mouse map
    m_mouse_action_map[sf::Mouse::Left] = [this]() { m_mouse.left(false); };
    m_ps4_action_map[0] = [this]() { m_mouse.left(false); };
    m_ps4_action_map[1] = [this]() {  m_WindowArrowsKey.escape(); };
    // m_ps4_action_map[2] = [this]() {  m_paddle_keys.space(); };

    m_ps4_axis_map[sf::Joystick::Y] = [this]() { 
        if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) == 100) {
            m_WindowArrowsKey.down(); 
        } else if (sf::Joystick::getAxisPosition(0, sf::Joystick::Y) == -100) {
            m_WindowArrowsKey.up(); 
        }
    };
    m_ps4_axis_map[m_controlSettingsMenu.getControlSettings().getPs4Mapping("Move Paddle Left")] = [this]() { 
        m_paddle_keys.left();
    };
    m_ps4_axis_map[m_controlSettingsMenu.getControlSettings().getPs4Mapping("Move Paddle Right")] = [this]() { 
        m_paddle_keys.right();
    };
    m_ps4_axis_map[m_controlSettingsMenu.getControlSettings().getPs4Mapping("Release Ball")] = [this]() { 
        m_paddle_keys.space(); 
    };
    m_ps4_axis_map[sf::Joystick::PovY] = [this]() { 
        if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) == 100) {
            m_WindowArrowsKey.down(); 
        } else if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) == -100) {
            m_WindowArrowsKey.up(); 
        }
    };
}

void InputHandlerImpl::updateKeyMap()
{
    m_keys_action_map[m_controlSettingsMenu.getControlSettings().getMapping("Move Paddle Left")] = [this]() { m_paddle_keys.left(); };
    m_keys_action_map[m_controlSettingsMenu.getControlSettings().getMapping("Move Paddle Right")] = [this]() { m_paddle_keys.right(); };
    m_keys_action_map[m_controlSettingsMenu.getControlSettings().getMapping("Release Ball")] = [this]() { m_paddle_keys.space(); };
    printVector(m_keys_action_map);
}

void InputHandlerImpl::updateMouseMovedControlSettingPage()
{
    if (m_gameState.getState() == State::ControlSettingPage) {
        m_controlSettingsMenu.handleMouseMovedInput(m_mousePosition);
    }
    if (m_gameState.getState() == State::VolumePage) {
        m_volume.updateMouseMoved(m_mousePosition);
    }
}

void InputHandlerImpl::updateKeyPressedControlSettingPage()
{
    if (m_gameState.getState() == State::ControlSettingPage) {
        deleteKeysExceptEscape(m_keys_action_map);
        m_controlSettingsMenu.handleKeyPressedInput(m_event,m_mousePosition);
        updateKeyMap();
    }
}

void InputHandlerImpl::performKeyAction(sf::Event event) {
    auto it = m_keys_action_map.find(event.key.code);
    if (it != m_keys_action_map.end()) {
        it->second();
    }
    //  else {
    //     std::cout << "Sorry bro, the key you pressed doesn't exist: " << keyToString(m_event.key.code) << "\n";
    // }
}

void InputHandlerImpl::performMouseAction(sf::Event event)
{
    auto it = m_mouse_action_map.find(event.mouseButton.button);
    if (it != m_mouse_action_map.end()) {
        it->second();
        if (m_menu.getIsMenuPageShown()) {
            std::cout << "m_menu.getIsMenuPageShown(): " <<  m_menu.getIsMenuPageShown() << "\n";
        } else if (m_options.getIsOptionsPageShown()) {
            std::cout << "m_menu.getIsOptionsPageShown(): " <<  m_options.getIsOptionsPageShown() << "\n";
        } else if (m_difficulty.getIsDifficultyPageShown()) {
            std::cout << "m_menu.getIsDifficultyPageShown(): " <<  m_difficulty.getIsDifficultyPageShown() << "\n";
        }
        
    } else {
        std::cout << "Sorry bro, the mouse button you pressed doesn't exist." << "\n";
    }
}

void InputHandlerImpl::performPs4Action(sf::Event event)
{
    auto it = m_ps4_action_map.find(event.joystickButton.button);
    if (it != m_ps4_action_map.end()) {
        it->second();
    } else {
        // std::cout << "Sorry bro, the ps4 button you pressed doesn't exist." << "\n";
    }
}

void InputHandlerImpl::performPs4AxisAction(sf::Event event)
{
    auto it = m_ps4_axis_map.find(event.joystickMove.axis);
    if (it != m_ps4_axis_map.end()) {
        it->second();
    } else {
        // std::cout << "Sorry bro, the ps4 axis you pressed doesn't exist." << "\n";
    }
}

std::string InputHandlerImpl::keyToString(sf::Keyboard::Key key)
{
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

void InputHandlerImpl::checkEventUnderTenCharacter()
{
    if (m_event.text.unicode < 128 && m_event.text.unicode != '\b' && m_event.text.unicode != NEWLINE_CHAR) {
        if (m_hud.getName().length() < 10) {
            m_hud.getName() += static_cast<char>(m_event.text.unicode);
            m_hud.getInputText().setString(m_hud.getName());
        }
    }
}

void InputHandlerImpl::checkEventDeleteCharacter()
{
    if (m_event.text.unicode == '\b') {
        if (m_hud.getName().length() > 0) {
            m_hud.getName().pop_back();
            m_hud.getInputText().setString(m_hud.getName());
        }
    }
}

void InputHandlerImpl::updateHighScoreInFile()
{
    int score = m_gameState.getScore();
    int index = -1;
    for(int i=0;i<10;i++){
        if(m_hud.getHighScoreManager().getData(i).score < score){
            if(index == -1) index = i;
            else if(score > m_hud.getHighScoreManager().getData(i).score) index = i;
        }
    }
    
    if(index != -1){
        m_hud.getHighScoreManager().getData(index).score = score;
        m_hud.getHighScoreManager().getData(index).name = m_hud.getName();
    }

    for(int i = 0; i < 9; i++) {
        for(int j = i+1; j < 10; j++) {
            if(m_hud.getHighScoreManager().getData(i).score < m_hud.getHighScoreManager().getData(j).score) {
                std::swap(m_hud.getHighScoreManager().getData(i), m_hud.getHighScoreManager().getData(j));
            }
        }
    }

    std::ofstream file_out("src/scores/top10.dat");
    for (int i = 0; i < 10; i++) {
        file_out << m_hud.getHighScoreManager().getData(i).name << " " << m_hud.getHighScoreManager().getData(i).score << "\n";
    }
    file_out.close();

    m_hud.getName() = " ";
}

void InputHandlerImpl::checkEventEnterName()
{
    if (m_event.text.unicode == NEWLINE_CHAR) {
        std::cout << "Nice!!!" << "\n";
        updateHighScoreInFile();
        m_gameState.setState(State::HighScorePage);
    }
}
