#pragma once

#include "MenuOption.hxx"
#include "WindowManager.hpp"

class GameState;
class InputManager;

#include <memory>

class Options
{
public:
    Options(WindowManager& , GameState &);
    void drew();
    int handleInput(InputHandler& , GameState &);

    std::shared_ptr<MenuOption> & getOption(int );
    int getOptionSize() const;
    bool getIsOptionsPageShown() const;
    void setIsOptionsPageShown(bool);
    void setIsSelected();
    sf::Text* getText(int);
    std::vector<std::shared_ptr<MenuOption>> getTexts();

    template<typename... Args>
    void addOptions(Args&&... args);

private:
    WindowManager& m_windowManager;
    GameState &m_gameState;
    std::vector<std::shared_ptr<MenuOption>> m_options;
    bool m_isOptionsPageShown;
};