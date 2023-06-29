#pragma once

#include "InputHandler.hxx"
#include "WindowArrowsKey.hpp"
#include "MouseButton.hpp"
#include "ControlSettingsMenu.hpp"


#include <unordered_map>
#include <functional>

class GameState;
class Menu;
class Hud;
class MouseButton;
class Options;
class Difficulty;
class Video;
class VolumeManager;
class MenuScreenHandler;


class InputHandlerImpl : public InputHandler
{
public:
    InputHandlerImpl(sf::RenderWindow &
        , PaddleArrowsHandnling &
        , GameState &
        , Menu &
        , Options &
        , Difficulty &
        , Video &
        , Hud &
        , ControlSettingsMenu &
        , VolumeManager &
        , MenuScreenHandler &
    );

    void handleInput() override;
    sf::Vector2f &getMousePosition() override;
    bool isHandlerSelected() override;
    void setIsSelected(bool) override;
private:
    void initMap();
    void performKeyAction(sf::Event);
    void performMouseAction(sf::Event);
    void performPs4Action(sf::Event);
    void performPs4AxisAction(sf::Event);
    std::string keyToString(sf::Keyboard::Key );
    void printVector(std::unordered_map<sf::Keyboard::Key, std::function<void ()>>& );
    void printPs4Vector(std::unordered_map<size_t, std::function<void ()>>&);
private:
    void checkEventUnderTenCharacter();
    void checkEventDeleteCharacter();
    void checkEventEnterName();
    void updateHighScoreInFile();
    void updateKeyMap();
    void updateMouseMovedControlSettingPage();
    void updateKeyPressedControlSettingPage();
    void func();
    bool m_isSelected;
    static bool m_isMusicPlayed;
    
    sf::Vector2f m_mousePosition;
    sf::Event m_event;
    std::unordered_map<sf::Keyboard::Key,std::function<void()>> m_keys_action_map;
    std::unordered_map<sf::Mouse::Button,std::function<void()>> m_mouse_action_map;
    std::unordered_map<size_t,std::function<void()>> m_ps4_action_map;
    std::unordered_map<sf::Joystick::Axis,std::function<void()>> m_ps4_axis_map;
    std::vector<std::pair<std::string, sf::Text*>> m_controlTexts;

    sf::RenderWindow &m_window;
    PaddleArrowsHandnling &m_paddle_keys;
    GameState &m_gameState;
    Menu &m_menu;
    Options &m_options;
    Difficulty &m_difficulty;
    Video &m_video;
    Hud &m_hud;
    ControlSettingsMenu &m_controlSettingsMenu;
    VolumeManager &m_volume;
    WindowArrowsKey m_WindowArrowsKey;
    MenuScreenHandler &m_menuScreenHandler;
    MouseButton m_mouse;
};