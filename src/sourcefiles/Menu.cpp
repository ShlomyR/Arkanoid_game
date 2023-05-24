#include "../hederfiles/Menu.hpp"
#include "../hederfiles/PlayOption.hpp"
#include "../hederfiles/HighScoreOption.hpp"
#include "../hederfiles/ExitOption.hpp"
#include "../hederfiles/GameState.hpp"

#include <memory>

Menu::Menu(WindowManager& windowManager,GameState &gameState)
    : m_windowManager(windowManager)
    , m_gameState(gameState)
    , m_isMenuShown(false)
{
    addOptions(std::make_unique<PlayOption>(),std::make_unique<HighScoreOption>(),std::make_unique<ExitOption>());
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

int Menu::getOptionSize() const
{
    return m_options.size();
}

bool Menu::getIsMenuShown() const
{
    return m_isMenuShown;
}

void Menu::setIsMenuShown(bool value)
{
    m_isMenuShown = value;
    for (size_t i = 0; i < m_options.size(); ++i) {
        m_options[i]->setIsSelected(true);
    }
    
}

sf::Text Menu::getText()
{
    sf::Text tmpText;
    for (size_t i = 0; i < m_options.size(); ++i) {
        tmpText = m_options[i]->getText();
    }
    return tmpText;
}

template <typename... Args>
void Menu::addOptions(Args &&...args)
{
    (m_options.emplace_back(std::forward<Args>(args)), ...);
}
