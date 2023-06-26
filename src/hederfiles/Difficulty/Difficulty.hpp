#pragma once

#include "MenuOption.hxx"
#include "WindowManager.hpp"

class GameState;
class InputManager;
class MenuScreenHandler;

#include <memory>

class Difficulty
{
public:
    Difficulty(WindowManager&, MenuScreenHandler&);
    void drew();
    int handleInput(InputHandler& , GameState &);

    std::shared_ptr<MenuOption> & getOption(int );
    const std::vector<std::shared_ptr<MenuOption>>& getOptions() const;
    int getOptionSize() const;
    bool getIsDifficultyPageShown() const;
    void setIsDifficultyPageShown(bool);
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
    bool m_isDifficultyPageShown;
};
