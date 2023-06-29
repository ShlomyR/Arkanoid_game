#include "WindowArrowsKey.hpp"
#include "GameState.hpp"

WindowArrowsKey::WindowArrowsKey(sf::RenderWindow &window, GameState &gameState)
: m_window(window)
, m_gameState(gameState)
{
    init();
}

void WindowArrowsKey::init()
{
    initVars();
    initMap();
    highlightFirstWordInPage();
}

void WindowArrowsKey::initVars()
{
    currPage = "MenuPage";
    m_currMenu = 0;
    m_currVideo = 0;
    m_currOptions = 0;
    m_currVolume = 0;
    m_currDifficulty = 0;

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
    m_maxIndexVolume = 2;
    m_volumeColors = {
        sf::Color::White,
        sf::Color{128, 128, 128}
    };
    m_maxIndexDifficulty = 3;
    m_difficultyColors = {
        sf::Color::White,
        sf::Color{128, 128, 128},
        sf::Color{128, 128, 128}
    };
}

void WindowArrowsKey::initMap()
{
    m_map.insert({"VideoPage",m_gameState.getVideo().getTexts()});
    m_map.insert({"MenuPage",m_gameState.getMenu().getTexts()});
    m_map.insert({"DifficultyPage",m_gameState.getDifficulty().getTexts()});
    m_map.insert({"OptionsPage",m_gameState.getOptions().getTexts()});
}

void WindowArrowsKey::highlightFirstWordInPage()
{
    m_currMenu = 0;
    m_currVideo = 0;
    m_currOptions = 0;
    m_currVolume = 0;
    m_currDifficulty = 0;
    handelUp(m_currMenu, m_maxIndexMenu, m_menuColors, "MenuPage");
    handelUp(m_currOptions, m_maxIndexOptions, m_optionsColors, "OptionsPage");
    handelUp(m_currVolume, m_maxIndexVolume, m_volumeColors, "VolumePage");
    handelUp(m_currDifficulty, m_maxIndexDifficulty, m_difficultyColors, "DifficultyPage");
    handelUp(m_currVideo, m_maxIndexVideo, m_videoColors, "ControlSettingPage");
}

void WindowArrowsKey::handelUp(int &currNum, int maxNum, std::vector<sf::Color>& colorVec, std::string pageName)
{
    if (currNum >= maxNum) {
            currNum = 0;
    } 
    if (pageName == "VideoPage") {
        for (size_t i = 0; i < colorVec.size(); ++i) {
            if (m_map.at(pageName).at(i)->getText()->getOutlineColor() == sf::Color{128,128,128}) {
                m_map.at(pageName).at(i)->getText()->setFillColor(colorVec[(currNum + i) % maxNum]);
                ++i;
            } else {
                m_map.at(pageName).at(i)->getText()->setFillColor(colorVec[1]); 
            }
        }
     
    } else if (pageName == "ControlSettingPage") {
        for (size_t i = 0; i < colorVec.size(); ++i) {
            m_gameState.getControlSettingsMenu().getVectorsTexts()[i]->setFillColor(colorVec[(currNum + i) % maxNum]);
        }
    } else if (pageName != "VolumePage") {
        for (size_t i = 0; i < colorVec.size(); ++i) {
            m_map.at(pageName).at(i)->getText()->setFillColor(colorVec[(currNum + i) % maxNum]);
        }
    } else {
        for (size_t i = 0; i < colorVec.size(); ++i) {
            m_gameState.getVolumeManager().getVectorsTexts()[0][i]->setFillColor(colorVec[(currNum + i) % maxNum]);
            m_gameState.getVolumeManager().getVectorsTexts()[1][0]->setFillColor(sf::Color{128,128,128});
            m_gameState.getVolumeManager().getVectorsTexts()[1][1]->setFillColor(sf::Color{128,128,128});
        }
    }
    ++currNum;
}

void WindowArrowsKey::handelRight(int &, int , std::vector<sf::Color>& colorVec)
{
    for (size_t i = 0; i < colorVec.size(); ++i) {
        if (m_gameState.getVolumeManager().getVectorsTexts()[0][0]->getFillColor() == sf::Color::White) {
            m_gameState.getVolumeManager().getVectorsTexts()[1][1]->setFillColor(sf::Color::White);
            m_gameState.getVolumeManager().getVectorsTexts()[1][0]->setFillColor(sf::Color{128,128,128});
        }
    }
}



void WindowArrowsKey::handelLeft(int &, int , std::vector<sf::Color>& colorVec)
{
    for (size_t i = 0; i < colorVec.size(); ++i) {
        if (m_gameState.getVolumeManager().getVectorsTexts()[0][0]->getFillColor() == sf::Color::White) {
            m_gameState.getVolumeManager().getVectorsTexts()[1][0]->setFillColor(sf::Color::White);
            m_gameState.getVolumeManager().getVectorsTexts()[1][1]->setFillColor(sf::Color{128,128,128});
        }
    }
}

void WindowArrowsKey::handelDown(int &currNum, int maxNum, std::vector<sf::Color>& colorVec, std::string pageName)
{
    if (currNum <= 0) {
        currNum = maxNum;
    }

    if (pageName == "VideoPage") {
        for (size_t i = 0; i < colorVec.size(); ++i) {
            if (m_map.at(pageName).at(i)->getText()->getOutlineColor() == sf::Color{128,128,128}) {
                m_map.at(pageName).at(i)->getText()->setFillColor(colorVec[(currNum + i - 1) % maxNum]);
                ++i;
            } else {
                m_map.at(pageName).at(i)->getText()->setFillColor(colorVec[1]); 
            }
            
        }
    } else if (pageName == "DifficultyPage") {
        for (size_t i = 0; i < colorVec.size(); ++i) {
            m_map.at(pageName).at(i)->getText()->setFillColor(colorVec[(currNum + i - 1) % maxNum]);
        }
    } else if (pageName == "ControlSettingPage") {
        for (size_t i = 0; i < colorVec.size(); ++i) {
            m_gameState.getControlSettingsMenu().getVectorsTexts()[i]->setFillColor(colorVec[(currNum + i - 1) % maxNum]);
        }
    } else if (pageName != "VolumePage") {
        for (size_t i = 0; i < colorVec.size(); ++i) {
            m_map.at(pageName).at(i)->getText()->setFillColor(colorVec[(currNum - maxNum + i - 1) % maxNum]);
        }
    } else {
        for (size_t i = 0; i < colorVec.size(); ++i) {
            m_gameState.getVolumeManager().getVectorsTexts()[0][i]->setFillColor(colorVec[(currNum - maxNum + i - 1) % maxNum]);
            m_gameState.getVolumeManager().getVectorsTexts()[1][0]->setFillColor(sf::Color{128,128,128});
            m_gameState.getVolumeManager().getVectorsTexts()[1][1]->setFillColor(sf::Color{128,128,128});
        }
        
    }
    --currNum;
}

void WindowArrowsKey::up()
{
    if (m_gameState.getState() == State::MenuPage) {
        handelUp(m_currMenu, m_maxIndexMenu, m_menuColors, "MenuPage");
    } else if (m_gameState.getState() == State::VideoPage) {
        handelUp(m_currVideo, m_maxIndexVideo, m_videoColors, "VideoPage");
    } else if (m_gameState.getState() == State::VolumePage) {
        handelUp(m_currVolume, m_maxIndexVolume, m_volumeColors, "VolumePage");
    } else if (m_gameState.getState() == State::OptionsPage) {
        handelUp(m_currOptions, m_maxIndexOptions, m_optionsColors, "OptionsPage");
    } else if (m_gameState.getState() == State::DifficultyPage) {
        handelUp(m_currDifficulty, m_maxIndexDifficulty, m_difficultyColors, "DifficultyPage");
    } else if (m_gameState.getState() == State::ControlSettingPage) {
        handelUp(m_currDifficulty, m_maxIndexDifficulty, m_difficultyColors, "ControlSettingPage");
    }
}

void WindowArrowsKey::down()
{
    
    if (m_gameState.getState() == State::MenuPage) {
        handelDown(m_currMenu, m_maxIndexMenu, m_menuColors, "MenuPage");
    } else if (m_gameState.getState() == State::VideoPage) {
        handelDown(m_currVideo, m_maxIndexVideo, m_videoColors, "VideoPage");        
    } else if (m_gameState.getState() == State::VolumePage) {
        handelDown(m_currVolume, m_maxIndexVolume, m_volumeColors, "VolumePage");
    } else if (m_gameState.getState() == State::OptionsPage) {
        handelDown(m_currOptions, m_maxIndexOptions, m_optionsColors, "OptionsPage");
    } else if (m_gameState.getState() == State::DifficultyPage) {
        handelDown(m_currDifficulty, m_maxIndexDifficulty, m_difficultyColors, "DifficultyPage");
    } else if (m_gameState.getState() == State::ControlSettingPage) {
        handelDown(m_currDifficulty, m_maxIndexDifficulty, m_difficultyColors, "ControlSettingPage");
    }
}

void WindowArrowsKey::right()
{
    if (m_gameState.getState() == State::VolumePage) {
        handelRight(m_currVolume, m_maxIndexVolume, m_volumeColors);
    }
}

void WindowArrowsKey::left()
{
    if (m_gameState.getState() == State::VolumePage) {
        handelLeft(m_currVolume, m_maxIndexVolume, m_volumeColors);
    }
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
