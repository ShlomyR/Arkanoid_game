#pragma once

#include "InputHandler.hxx"
#include "WindowArrowsKey.hpp"
#include "MouseButton.hpp"


#include <unordered_map>
#include <functional>

class GameState;
class Menu;
class Hud;
class MouseButton;


class InputHandlerImpl : public InputHandler
{
public:
    InputHandlerImpl(sf::RenderWindow &, PaddleArrowsHandnling &, GameState &, Menu &, Hud &);

    void handleInput() override;
    sf::Vector2f &getMousePosition() override;
    bool isHandlerSelected() override;
    void setIsSelected(bool) override;
private:
    void initMap();
    void performKeyAction(sf::Event);
    void performMouseAction(sf::Event);
    std::string keyToString(sf::Keyboard::Key );
private:
    void checkEventUnderTenCharacter();
    void checkEventDeleteCharacter();
    void checkEventEnterName();
    void updateHighScoreInFile();
    bool m_isSelected;
    int count = 0;
    
    sf::Vector2f m_mousePosition;
    sf::Event m_event;
    std::unordered_map<sf::Keyboard::Key,std::function<void()>> m_keys_action_map;
    std::unordered_map<sf::Mouse::Button,std::function<void()>> m_mouse_action_map;

    sf::RenderWindow &m_window;
    PaddleArrowsHandnling &m_paddle_keys;
    GameState &m_gameState;
    Menu &m_menu;
    Hud &m_hud;
    WindowArrowsKey m_WindowArrowsKey;
    MouseButton m_mouse;

};