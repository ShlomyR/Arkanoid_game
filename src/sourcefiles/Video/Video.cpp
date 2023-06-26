#include "Video.hpp"
#include "ResX1024.hpp"
#include "ResX800.hpp"
#include "FullScreen.hpp"
#include "GameState.hpp"

#include <memory>

Video::Video(WindowManager& windowManager)
    : m_windowManager(windowManager)
    , m_isVideoPageShown(false)
{
    addOptions(std::make_unique<FullScreen>(), std::make_unique<ResX800>(), std::make_unique<ResX1024>());
    for (size_t i = 0; i < m_options.size(); ++i) {
        m_options[i]->makeButton(m_windowManager.getRenderWindow());
    }
}

void Video::drew()
{
    for (const auto& option : m_options) {
        option->draw(m_windowManager.getRenderWindow());
    }
}

int Video::handleInput(InputHandler& inputHandler,GameState &gameState)
{
    for (size_t i = 0; i < m_options.size(); ++i) {
        if (m_options[i]->handleInput(inputHandler,gameState)) {
            return i;
        }
    }
    return -1;
}


std::shared_ptr<MenuOption> &Video::getOption(int index)
{
    return m_options.at(index);
}

const std::vector<std::shared_ptr<MenuOption>>& Video::getOptions() const
{
    return m_options;
}


int Video::getOptionSize() const
{
    return m_options.size();
}

bool Video::getIsVideoPageShown() const
{
    return m_isVideoPageShown;
}

void Video::setIsVideoPageShown(bool value)
{
    m_isVideoPageShown = value;
}

void Video::setIsSelected()
{
    for (size_t i = 0; i < m_options.size(); ++i) {
        m_options[i]->setIsSelected(true);
    }
}

sf::Text* Video::getText(int i)
{
    return m_options[i]->getText();
}

std::vector<std::shared_ptr<MenuOption>> Video::getTexts()
{
    return m_options;
}

template <typename... Args>
void Video::addOptions(Args &&...args)
{
    (m_options.emplace_back(std::forward<Args>(args)), ...);
}
