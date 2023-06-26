#pragma once

#include "MenuOption.hxx"
#include "WindowManager.hpp"

class InputManager;
class MenuScreenHandler;

#include <memory>

class Video
{
public:
    Video(WindowManager&, MenuScreenHandler&);
    void drew();
    int handleInput(InputHandler& , GameState &);

    std::shared_ptr<MenuOption> & getOption(int );
    const std::vector<std::shared_ptr<MenuOption>>& getOptions() const;
    int getOptionSize() const;
    bool getIsVideoPageShown() const;
    void setIsVideoPageShown(bool);
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
    bool m_isVideoPageShown;
};
