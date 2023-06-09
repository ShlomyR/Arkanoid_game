#include "Menu.hpp"
#include "PlayOption.hpp"
#include "OptionsOption.hpp"
#include "HighScoreOption.hpp"
#include "ExitOption.hpp"
#include "GameState.hpp"
#include "MenuScreenHandler.hpp"

#include <memory>

Menu::Menu(WindowManager& windowManager,MenuScreenHandler& menuScreenHandler)
    : m_windowManager(windowManager)
    , m_menuScreenHandler(menuScreenHandler)
    , m_isMenuShown(true)
{    
    addOptions(std::make_unique<PlayOption>(), std::make_unique<HighScoreOption>(), std::make_unique<OptionsOption>(), std::make_unique<ExitOption>());
    initBorder();
    for (int i = 0; i < getOptionSize(); ++i) {
        getOption(i)->makeButton(m_windowManager.getRenderWindow());
    }
}

void Menu::drew()
{
    for (const auto& option : m_options) {
        option->draw(m_windowManager.getRenderWindow());
    }
}

int Menu::handleInput(InputHandler& inputHandler,GameState &gameState)
{
    for (size_t i = 0; i < m_options.size(); ++i) {
        if (m_options[i]->handleInput(inputHandler,gameState)) {
            return i;
        }
    }
    return -1;
}

std::shared_ptr<MenuOption> &Menu::getOption(int index)
{
    return m_options.at(index);
}

const std::vector<std::shared_ptr<MenuOption>>& Menu::getOptions() const
{
    return m_options;
}

int Menu::getOptionSize() const
{
    return m_options.size();
}

bool Menu::getIsMenuPageShown() const
{
    return m_isMenuShown;
}

void Menu::setIsMenuPageShown(bool value)
{
    m_isMenuShown = value;
}

void Menu::setIsSelected()
{
    for (size_t i = 0; i < m_options.size(); ++i) {
        m_options[i]->setIsSelected(true);
    }
}

void Menu::initBorder()
{
    auto tmpBox = m_menuScreenHandler.getOptionsBoxShape();
    for (size_t i = 0; i < m_options.size(); ++i) {
        m_options[i]->setBoxBorder(tmpBox);
    }
}

sf::Text* Menu::getText(int i)
{
    return m_options[i]->getText();
}

std::vector<std::shared_ptr<MenuOption>> Menu::getTexts()
{
    return m_options;
}

MenuScreenHandler Menu::getMenuScreen()
{
    return m_menuScreenHandler;
}

template <typename... Args>
void Menu::addOptions(Args &&...args)
{
    (m_options.emplace_back(std::forward<Args>(args)), ...);
}
