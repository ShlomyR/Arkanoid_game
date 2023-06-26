#include "Difficulty.hpp"
#include "EasyOption.hpp"
#include "MediumOption.hpp"
#include "HardOption.hpp"
#include "GameState.hpp"
#include "MenuScreenHandler.hpp"

#include <memory>

Difficulty::Difficulty(WindowManager& windowManager, MenuScreenHandler& menuScreenHandler)
    : m_windowManager(windowManager)
    , m_menuScreenHandler(menuScreenHandler)
    , m_isDifficultyPageShown(false)
{
    addOptions(std::make_unique<EasyOption>(), std::make_unique<MediumOption>(), std::make_unique<HardOption>());
    initBorder();
    for (size_t i = 0; i < m_options.size(); ++i) {
        m_options[i]->makeButton(m_windowManager.getRenderWindow());
    }
}

void Difficulty::drew()
{
    for (const auto& option : m_options) {
        option->draw(m_windowManager.getRenderWindow());
    }
}

int Difficulty::handleInput(InputHandler& inputHandler,GameState &gameState)
{
    for (size_t i = 0; i < m_options.size(); ++i) {
        if (m_options[i]->handleInput(inputHandler,gameState)) {
            return i;
        }
    }
    return -1;
}


std::shared_ptr<MenuOption> &Difficulty::getOption(int index)
{
    return m_options.at(index);
}

const std::vector<std::shared_ptr<MenuOption>>& Difficulty::getOptions() const
{
    return m_options;
}


int Difficulty::getOptionSize() const
{
    return m_options.size();
}

bool Difficulty::getIsDifficultyPageShown() const
{
    return m_isDifficultyPageShown;
}

void Difficulty::setIsDifficultyPageShown(bool value)
{
    m_isDifficultyPageShown = value;
}

void Difficulty::setIsSelected()
{
    for (size_t i = 0; i < m_options.size(); ++i) {
        m_options[i]->setIsSelected(true);
    }
}

void Difficulty::initBorder()
{
    auto tmpBox = m_menuScreenHandler.getOptionsBoxShape();
    for (size_t i = 0; i < m_options.size(); ++i) {
        m_options[i]->setBoxBorder(tmpBox);
    }
}

sf::Text* Difficulty::getText(int i)
{
    return m_options[i]->getText();
}

std::vector<std::shared_ptr<MenuOption>> Difficulty::getTexts()
{
    return m_options;
}

MenuScreenHandler Difficulty::getMenuScreen()
{
   return m_menuScreenHandler;
}

template <typename... Args>
void Difficulty::addOptions(Args &&...args)
{
    (m_options.emplace_back(std::forward<Args>(args)), ...);
}
