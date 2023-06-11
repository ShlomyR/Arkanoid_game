#include "InputHandlerImpl.hpp"
#include "MouseButton.hpp"
#include "Difficulty.hpp"
#include "Video.hpp"
#include "GameState.hpp"
#include "Options.hpp"
#include "Menu.hpp"

#include <iostream>

MouseButton::MouseButton(sf::RenderWindow &window, Menu &menu, Options &options, Difficulty &difficulty, Video &video, GameState &gameState)
: m_window(window)
, m_menu(menu)
, m_options(options)
, m_difficulty(difficulty)
, m_video(video)
, m_gameState(gameState)
{}

void MouseButton::left(bool const& value)
{
    if (m_menu.getIsMenuPageShown()) {
        m_menu.setIsSelected();
        m_menu.setIsMenuPageShown(value);
    } else if (m_options.getIsOptionsPageShown()) {
        m_options.setIsSelected();
        m_options.setIsOptionsPageShown(value);
    } else if (m_difficulty.getIsDifficultyPageShown()) {
        m_difficulty.setIsSelected();
        m_difficulty.setIsDifficultyPageShown(value);
    } else if (m_video.getIsVideoPageShown()) {
        m_video.setIsSelected();
        m_video.setIsVideoPageShown(value);
    }
}
