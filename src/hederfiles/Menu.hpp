#pragma once

#include "MenuOption.hxx"
#include "WindowManager.hpp"

class GameState;
class InputManager;

#include <memory>

class Menu {
public:
    Menu(WindowManager& windowManager, GameState &gameState);
    void drew();
    int handleInput(InputHandler& inputHandler, GameState &gameState);

    std::shared_ptr<MenuOption> & getOption(int index);
    int getOptionSize() const;
    bool getIsMenuShown() const;
    void setIsMenuShown(bool);
    sf::Text getText();

    template<typename... Args>
    void addOptions(Args&&... args);

private:
    WindowManager& m_windowManager;
    GameState &m_gameState;
    std::vector<std::shared_ptr<MenuOption>> m_options;
    bool m_isMenuShown;
};
