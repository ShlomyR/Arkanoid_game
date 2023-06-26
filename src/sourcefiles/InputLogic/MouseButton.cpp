#include "MenuScreenHandler.hpp"
#include "InputHandlerImpl.hpp"
#include "MouseButton.hpp"
#include "Difficulty.hpp"
#include "Video.hpp"
#include "Options.hpp"
#include "Menu.hpp"

#include <iostream>

MouseButton::MouseButton(Menu &menu, Options &options, Difficulty &difficulty, Video &video, MenuScreenHandler &menuScreenHandler)
: m_menu(menu)
, m_options(options)
, m_difficulty(difficulty)
, m_video(video)
, m_menuScreenHandler(menuScreenHandler)
{}

void MouseButton::left(bool const& value)
{
    if (m_menu.getIsMenuPageShown()) {
        m_menu.setIsSelected();
        m_menu.setIsMenuPageShown(value);
    } else if (m_options.getIsOptionsPageShown()) {
        m_menuScreenHandler.setIsSelected(true);
        m_options.setIsSelected();
        m_options.setIsOptionsPageShown(value);
    } else if (m_difficulty.getIsDifficultyPageShown()) {
        m_menuScreenHandler.setIsSelected(true);
        m_difficulty.setIsSelected();
        m_difficulty.setIsDifficultyPageShown(value);
    } else if (m_video.getIsVideoPageShown()) {
        m_menuScreenHandler.setIsSelected(true);
        m_video.setIsSelected();
        m_video.setIsVideoPageShown(value);
    }
}
