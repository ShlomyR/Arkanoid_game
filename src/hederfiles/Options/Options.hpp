#pragma once

#include "MenuOption.hxx"
#include "WindowManager.hpp"

class InputManager;
class MenuScreenHandler;

#include <memory>

class Options
{
public:
    Options(WindowManager&, MenuScreenHandler&);
    void drew();
    int handleInput(InputHandler& , GameState &);

    std::shared_ptr<MenuOption> & getOption(int );
    int getOptionSize() const;
    bool getIsOptionsPageShown() const;
    void setIsOptionsPageShown(bool);
    void setIsSelected();
    void initBorder();
    sf::Text* getText(int);
    std::vector<std::shared_ptr<MenuOption>> getTexts();
    MenuScreenHandler getMenuScreen();

    template<typename... Args>
    void addOptions(Args&&... args);

private:
    WindowManager& m_windowManager;
    MenuScreenHandler& m_menuScreenHandler;
    std::vector<std::shared_ptr<MenuOption>> m_options;
    bool m_isOptionsPageShown;
};