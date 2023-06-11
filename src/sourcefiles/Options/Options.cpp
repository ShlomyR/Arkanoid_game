#include "Options.hpp"
#include "InstructionsOption.hpp"
#include "VideoOption.hpp"
#include "SoundOption.hpp"
#include "DifficultyOption.hpp"
#include "ControlsOption.hpp"
#include "GameState.hpp"

#include <memory>

Options::Options(WindowManager& windowManager,GameState &gameState)
    : m_windowManager(windowManager)
    , m_gameState(gameState)
    , m_isOptionsPageShown(false)
{
    addOptions(std::make_unique<SoundOption>(), std::make_unique<ControlsOption>(), std::make_unique<DifficultyOption>(), std::make_unique<InstructionsOption>(), std::make_unique<VideoOption>());
    for (int i = 0; i < getOptionSize(); ++i) {
        getOption(i)->makeButton(m_windowManager.getRenderWindow());
    }
}

void Options::drew()
{
    for (const auto& option : m_options) {
        option->draw(m_windowManager.getRenderWindow());
    }
}

int Options::handleInput(InputHandler& inputHandler,GameState &gameState)
{
    for (size_t i = 0; i < m_options.size(); ++i) {
        if (m_options[i]->handleInput(inputHandler,gameState)) {
            return i;
        }
    }
    return -1;
}

std::shared_ptr<MenuOption> &Options::getOption(int index)
{
    return m_options.at(index);
}

int Options::getOptionSize() const
{
    return m_options.size();
}

bool Options::getIsOptionsPageShown() const
{
    return m_isOptionsPageShown;
}

void Options::setIsOptionsPageShown(bool value)
{
    m_isOptionsPageShown = value;
}

void Options::setIsSelected()
{
    for (size_t i = 0; i < m_options.size(); ++i) {
        m_options[i]->setIsSelected(true);
    }
}

sf::Text* Options::getText(int i)
{
    return m_options[i]->getText();
}

std::vector<std::shared_ptr<MenuOption>> Options::getTexts()
{
    return m_options;
}

template <typename... Args>
void Options::addOptions(Args &&...args)
{
    (m_options.emplace_back(std::forward<Args>(args)), ...);
}
