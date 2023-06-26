#include "WindowArrowsKey.hpp"
#include "GameState.hpp"

WindowArrowsKey::WindowArrowsKey(sf::RenderWindow &window, GameState &gameState)
: m_window(window)
, m_gameState(gameState)
{
    currPage = "MenuPage";
    m_currMenu = 0;
    m_currVideo = 0;
    m_currOptions = 0;
    m_map.insert({"VideoPage",m_gameState.getVideo().getTexts()});
    m_map.insert({"MenuPage",m_gameState.getMenu().getTexts()});
    m_map.insert({"DifficultyPage",m_gameState.getDifficulty().getTexts()});
    m_map.insert({"OptionsPage",m_gameState.getOptions().getTexts()});
    // m_map.insert({"ControlSettingPage",m_gameState.getOptions().getTexts()});

    m_maxIndexMenu = 4;
    m_menuColors = {
        sf::Color::White,
        sf::Color{128, 128, 128},
        sf::Color{128, 128, 128},
        sf::Color{128, 128, 128}
    };
    m_maxIndexVideo = 3;
    m_videoColors = {
        sf::Color::White,
        sf::Color{128, 128, 128},
        sf::Color{128, 128, 128}
    };
    m_maxIndexOptions = 4;
    m_optionsColors = {
        sf::Color::White,
        sf::Color{128, 128, 128},
        sf::Color{128, 128, 128},
        sf::Color{128, 128, 128}
    };
    // m_map.insert({currPage,m_gameState.getMenu().getOption(2)});
    // m_map.insert({currPage,m_gameState.getMenu().getOption(3)});
}

void WindowArrowsKey::up()
{
    if (m_gameState.getState() == State::MenuPage) {
        if (m_currMenu >= m_maxIndexMenu) {
            m_currMenu = 0;
        }

        for (size_t i = 0; i < m_menuColors.size(); ++i) {
            m_map.at("MenuPage").at(i)->getText()->setFillColor(m_menuColors[(m_currMenu + i) % m_maxIndexMenu]);
        }

        ++m_currMenu;
    } else if (m_gameState.getState() == State::VideoPage) {
        if (m_currVideo >= m_maxIndexVideo) {
            m_currVideo = 0;
        }

        for (size_t i = 0; i < m_videoColors.size(); ++i) {
            m_map.at("VideoPage").at(i)->getText()->setFillColor(m_videoColors[(m_currVideo + i) % m_maxIndexVideo]);
        }

        ++m_currVideo;
    } else if (m_gameState.getState() == State::OptionsPage) {
        if (m_currOptions >= m_maxIndexOptions) {
            m_currOptions = 0;
        }

        for (size_t i = 0; i < m_optionsColors.size(); ++i) {
            m_map.at("OptionsPage").at(i)->getText()->setFillColor(m_optionsColors[(m_currOptions + i) % m_maxIndexOptions]);
        }

        ++m_currOptions;
    }
}

void WindowArrowsKey::down()
{
    
    if (m_gameState.getState() == State::MenuPage) {
        if (m_currMenu <= 0) {
            m_currMenu = m_maxIndexMenu;
        }    
        for (size_t i = 0; i < m_menuColors.size(); ++i) {
            m_map.at("MenuPage").at(i)->getText()->setFillColor(m_menuColors[(m_currMenu - m_maxIndexMenu + i - 1) % m_maxIndexMenu]);
        }

        --m_currMenu;

    } else if (m_gameState.getState() == State::VideoPage) {
        if (m_currVideo <= 0) {
            m_currVideo = m_maxIndexVideo;
        }

        for (size_t i = 0; i < m_videoColors.size(); ++i) {
            m_map.at("VideoPage").at(i)->getText()->setFillColor(m_videoColors[(m_currVideo - m_maxIndexVideo + i - 1) % m_maxIndexVideo]);
        }

        --m_currVideo;
        
    } else if (m_gameState.getState() == State::VolumePage) {
        m_map.at("VolumePage").at(1)->getText()->setFillColor(sf::Color::Blue);
    } else if (m_gameState.getState() == State::OptionsPage) {
        if (m_currOptions <= 0) {
            m_currOptions = m_maxIndexOptions;
        }
        for (size_t i = 0; i < m_optionsColors.size(); ++i) {
            m_map.at("OptionsPage").at(i)->getText()->setFillColor(m_optionsColors[(m_currOptions - m_maxIndexOptions + i -1) % m_maxIndexOptions]);
        }
        --m_currOptions;
    }
}

void WindowArrowsKey::enter()
{

}

void WindowArrowsKey::escape()
{
    if (m_gameState.getState() == State::DifficultyPage) {
        m_gameState.setState(State::OptionsPage);
    } else if (m_gameState.getState() == State::OptionsPage) {
        m_gameState.setState(State::MenuPage);
    } else if (m_gameState.getState() == State::MenuPage) {
        m_window.close();
    } else if (m_gameState.getState() == State::ControlSettingPage) {
        m_gameState.setState(State::OptionsPage);
    } else if (m_gameState.getState() == State::VolumePage) {
        m_gameState.setState(State::OptionsPage);
    } else if (m_gameState.getState() == State::VideoPage) {
        m_gameState.setState(State::OptionsPage);
    } else if (m_gameState.getState() != State::OptionsPage) {
        m_gameState.setState(State::MenuPage);
    }
}
