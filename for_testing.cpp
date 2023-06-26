// #include "MenuScreenHandler.hpp"
// #include "InputHandlerImpl.hpp"
// #include "SoundManager.hpp"

// #include <iostream>

// #define BAR_SIZE 1.5
// #define BUTTON_OFFSET_BETWEEN_SIZE 10
// #define BUTTON_OFFSET_X_SIZE 10

// bool MenuScreenHandler::m_isMusicPlayed;

// MenuScreenHandler::MenuScreenHandler(sf::RenderWindow &window, InputHandler& inputHandler)
// : m_window(window)
// , m_inputHandler(inputHandler)
// , m_volumeManager(m_window)
// {
//     init();
// }

// void MenuScreenHandler::init()
// {
//     m_counter = 0;
//     m_isMusicPlayed = false;
//     m_isSelected = false;
//     m_font.loadFromFile("src/fonts/DIN.ttf");
//     m_color = sf::Color{ 128,128,128 };
//     refinedBoxes();
//     createOptionsPageText();
//     createDifficultyPageText();
//     createVideoPageText();
//     createVolumePageText();
//     createControlSettingPageText();
//     m_currPage = "OptionsPage";
// }

// void MenuScreenHandler::creatText(std::string page,std::string str, sf::Text& text, sf::Vector2f pos)
// {
//     text.setString(str);
//     text.setFont(m_font);
//     text.setScale(0.5,0.5);
//     text.setCharacterSize(48);
//     text.setFillColor(m_color);
//     text.setOutlineThickness(2);
//     text.setOutlineColor(m_color);
//     text.setPosition(pos);
//     if (page == "OptionsPage") {
//         m_optionsPageTextsVec.push_back(text);
//     } else if (page == "DifficultyPage") {
//         m_difficultyPageTextsVec.push_back(text);
//     } else if (page == "VideoPage") {
//         m_videoPageTextsVec.push_back(text);
//     } else if (page == "VolumePage") {
//         m_volumePageTextsVec.push_back(text);
//     } else if (page == "ControlSettingPage") {
//         m_controlSettingPageTextsVec.push_back(text);
//     }
    
// }

// void MenuScreenHandler::creatHeadlineText(std::string page,std::string str, sf::Text& text, sf::Vector2f pos)
// {
//     text.setString(str);
//     text.setFont(m_font);
//     text.setScale(0.7,0.7);
//     text.setCharacterSize(48);
//     text.setFillColor(m_color);
//     text.setOutlineThickness(2);
//     text.setOutlineColor(m_color);
//     text.setPosition(pos);
//     m_optionsCurrPageVec.push_back(text);
//     if (page == "OptionsPage") {
//         m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
//     } else if (page == "DifficultyPage") {
//         m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
//     } else if (page == "VideoPage") {
//         m_optionsCurrPageVec.erase(m_optionsCurrPageVec.begin() + 1);
//         m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
//     } else if (page == "VolumePage") {
//         m_optionsCurrPageVec.erase(m_optionsCurrPageVec.begin() + 1);
//         m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
//     } else if (page == "ControlSettingPage") {
//         m_optionsCurrPageVec.erase(m_optionsCurrPageVec.begin() + 1);
//         m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
//     }
// }

// void MenuScreenHandler::isButtonHovers(GameState &gameState)
// {
//     bool anyButtonHovered = false;
    
//     for (size_t i = 0; i < m_optionsBoxDisplayTextsMap[m_currPage].size(); i++) {
//         if (mouseHoverButton(m_optionsBoxDisplayTextsMap[m_currPage].at(i))) {
//             anyButtonHovered = true;
//             if (m_isSelected) {
//                 m_isSelected = false;
//                 buttonSelected(gameState, i);
//             }
//         }
//     }
//     if (!anyButtonHovered) {
//         m_isMusicPlayed = false;
//         m_isSelected = false;
//     }   
// }

// void MenuScreenHandler::buttonSelected(GameState &gameState, int i)
// {
//     if (m_optionsBoxDisplayTextsMap[m_currPage].at(i).getString() == "Sound") {
//         m_currPage = "VolumePage";
//         gameState.setState(getState(m_currPage));
//     } else if (m_optionsBoxDisplayTextsMap[m_currPage].at(i).getString() == "Controls") {
//         m_currPage = "ControlSettingPage";
//         gameState.setState(getState(m_currPage));
//     } else if (m_optionsBoxDisplayTextsMap[m_currPage].at(i).getString() == "Difficulty") {
//         m_currPage = "DifficultyPage";
//         gameState.setState(getState(m_currPage));
//     } else if (m_optionsBoxDisplayTextsMap[m_currPage].at(i).getString() == "Video") {
//         m_currPage = "VideoPage";
//         gameState.setState(getState(m_currPage));
//     } else if (m_currPage == "VolumePage") {
//         updateMousePrestVolumePage(m_inputHandler.getMousePosition());
//     } else if (m_currPage == "VideoPage") {
//         updateMousePrestVideoPage(m_inputHandler.getMousePosition());
//     }
// }

// bool isStringInRange(const sf::String& str)
// {
//     try {
//         // Convert sf::String to int
//         int value = std::stoi(str.toAnsiString());

//         // Check if value is between 0 and 100
//         if (value >= 0 && value <= 100) {
//             return true;
//         } else {
//             return false;
//         }
//     } catch (const std::exception& e) {
//         // std::cerr << "Error: " << e.what() << std::endl;
//         return false;
//     }
// }



// void MenuScreenHandler::draw(std::string )
// {
//     // drewBorders();
//     drewBarsLine();
//     // drewControlsPage();
//     drewHeadline();
//     // drewOptions();   
// }

// void MenuScreenHandler::updateBox(std::string currPage)
// {
//     if (m_counter == 2) {
//         m_counter = 0;
//     }
//     if (currPage == "OptionsPage") {
//         if (m_counter == 0) {
//             m_barCurrPageWidthBox.setSize(sf::Vector2f(250, m_barCurrPageWidthBox.getSize().y));
//             m_barWidthBox.setSize(sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), 40)); 
//             m_barWidthBox.setPosition(sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ));
//             m_barWidthLine.setSize(sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), BAR_SIZE)); 
//             m_barWidthLine.setPosition(sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, m_barWidthBox.getPosition().y + (m_barWidthBox.getSize().y/2 - m_barWidthLine.getSize().y/2)));
//             ++m_counter;
//         }
//     } else if (currPage != "OptionsPage") {
//         if (m_counter == 1) {
//             m_barCurrPageWidthBox.setSize(sf::Vector2f(350, m_barCurrPageWidthBox.getSize().y));
//             m_barWidthBox.setSize(sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), 40)); 
//             m_barWidthBox.setPosition(sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ));
//             m_barWidthLine.setSize(sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), BAR_SIZE)); 
//             m_barWidthLine.setPosition(sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, m_barWidthBox.getPosition().y + (m_barWidthBox.getSize().y/2 - m_barWidthLine.getSize().y/2)));     
//             ++m_counter;
//         }
//     }
// }

// void MenuScreenHandler::refinedBox(sf::RectangleShape& recShape, sf::Vector2f size, sf::Vector2f pos, sf::Color color)
// {
//     recShape.setSize(size);
//     recShape.setPosition(pos);
//     recShape.setFillColor(color);
// }

// int MenuScreenHandler::getCounter()
// {
//     return m_counter;
// }

// void MenuScreenHandler::setCurrPage(std::string page)
// {
//     m_currPage = page;
// }

// void MenuScreenHandler::setIsSelected(bool val)
// {
//     m_isSelected = val;
// }

// void MenuScreenHandler::refinedBoxes()
// {
//     refinedBox(m_menuBox, sf::Vector2f(m_window.getSize().x - 40, m_window.getSize().y - 40), sf::Vector2f(20 , 20), sf::Color::White);
//     refinedBox(m_barCurrPageWidthBox, sf::Vector2f(250 , 40), sf::Vector2f(m_menuBox.getPosition().x + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ), sf::Color::Blue);
//     refinedBox(m_barWidthBox, sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), 40), sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ), sf::Color{20,20,20,150});
//     refinedBox(m_optionsBoxText, sf::Vector2f(m_menuBox.getSize().x / 2, m_menuBox.getSize().y / 1.3), sf::Vector2f((m_menuBox.getSize().x - m_menuBox.getSize().x ) + 40, m_barWidthBox.getPosition().y + 100), sf::Color::Green);
//     refinedBox(m_barHightBox, sf::Vector2f( 40, m_menuBox.getSize().y - (m_barWidthBox.getPosition().y + m_barWidthBox.getSize().y)), sf::Vector2f(m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x + 20, m_barWidthBox.getPosition().y + m_barWidthBox.getSize().y + 20), sf::Color{20,20,20,150});
//     refinedBox(m_guidBoxText, sf::Vector2f(m_menuBox.getSize().x / 2.3, m_menuBox.getSize().y / 1.3), sf::Vector2f(m_barHightBox.getPosition().x + m_barHightBox.getSize().x + 20, m_barWidthBox.getPosition().y + 100), sf::Color{20,20,20,150});
//     refinedBox(m_barWidthLine, sf::Vector2f(m_barWidthBox.getSize().x, BAR_SIZE), sf::Vector2f(m_barWidthBox.getPosition().x, m_barWidthBox.getPosition().y + (m_barWidthBox.getSize().y/2 - m_barWidthLine.getSize().y/2)), sf::Color{255, 255, 249});
//     refinedBox(m_barHightLine, sf::Vector2f(BAR_SIZE, m_barHightBox.getSize().y), sf::Vector2f(m_barHightBox.getPosition().x + (m_barHightBox.getSize().x/2 - m_barHightLine.getSize().x/2), m_barHightBox.getPosition().y), sf::Color{255, 255, 249});
//     refinedBox(m_releaseButtonBox, sf::Vector2f(100, 70), sf::Vector2f((m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x)/2 + BUTTON_OFFSET_X_SIZE, m_optionsBoxText.getPosition().y + 70), sf::Color{20,20,20,150});
//     refinedBox(m_moveLeftButtonBox, sf::Vector2f(100, 70), sf::Vector2f((m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x)/2 + BUTTON_OFFSET_X_SIZE, m_releaseButtonBox.getPosition().y + m_releaseButtonBox.getSize().y + BUTTON_OFFSET_BETWEEN_SIZE), sf::Color{20,20,20,150});
//     refinedBox(m_moveRightButtonBox, sf::Vector2f(100, 70), sf::Vector2f((m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x)/2 + BUTTON_OFFSET_X_SIZE, m_moveLeftButtonBox.getPosition().y + m_moveLeftButtonBox.getSize().y + BUTTON_OFFSET_BETWEEN_SIZE), sf::Color{20,20,20,150});
//     m_releaseButtonBox.setOutlineThickness(2);
//     m_releaseButtonBox.setOutlineColor(sf::Color::White);
//     m_moveLeftButtonBox.setOutlineThickness(2);
//     m_moveLeftButtonBox.setOutlineColor(sf::Color::White);
//     m_moveRightButtonBox.setOutlineThickness(2);
//     m_moveRightButtonBox.setOutlineColor(sf::Color::White);
// }

// void MenuScreenHandler::createOptionsPageText()
// {
//     // creatText("OptionsPage", "Sound", m_optionSoundText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 100));
//     // creatText("OptionsPage", "Controls", m_optionControlsText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 150));
//     // creatText("OptionsPage", "Difficulty", m_optionDifficultyText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 200));
//     // creatText("OptionsPage", "Instructions", m_optionInstructionsText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 250));
//     // creatText("OptionsPage", "Video", m_optionVideoText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 300));
//     // m_optionsBoxDisplayTextsMap.insert({"OptionsPage", m_optionsPageTextsVec});
//     creatHeadlineText("OptionsPage", "OPTIONS", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
//     m_headlineBarWidthDisplayTextsMap.insert({"OptionsPage", m_headlineOptionsPageTextsVec[0]});
// }

// void MenuScreenHandler::createDifficultyPageText()
// {
//     // creatText("DifficultyPage", "Easy", m_difficultyEasyText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 100));
//     // creatText("DifficultyPage", "Medium", m_difficultyMediumText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 150));
//     // creatText("DifficultyPage", "Hard", m_difficultyHardText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 200));
//     // m_optionsBoxDisplayTextsMap.insert({"DifficultyPage", m_difficultyPageTextsVec});
//     creatHeadlineText("DifficultyPage", "DIFFICULTY", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
//     m_headlineOptionsPageTextsVec[1].at(1).setPosition(sf::Vector2f(200,m_headlineOptionsPageTextsVec[1].at(1).getPosition().y));
//     m_headlineBarWidthDisplayTextsMap.insert({"DifficultyPage", m_headlineOptionsPageTextsVec[1]});
// }

// void MenuScreenHandler::createVideoPageText()
// {
//     // creatText("VideoPage", "FullScreen", m_videoFullScreenText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 100));
//     // creatText("VideoPage", "800 X 600", m_video800X600Text, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 150));
//     // creatText("VideoPage", "1024 x 768", m_video1024x768Text, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 200));
//     // m_optionsBoxDisplayTextsMap.insert({"VideoPage", m_videoPageTextsVec});
//     creatHeadlineText("VideoPage", "VIDEO", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
//     m_headlineOptionsPageTextsVec[2].at(1).setPosition(sf::Vector2f(250,m_headlineOptionsPageTextsVec[2].at(1).getPosition().y));
//     m_headlineBarWidthDisplayTextsMap.insert({"VideoPage", m_headlineOptionsPageTextsVec[2]});
// }

// void MenuScreenHandler::createVolumePageText()
// {
//     // creatText("VolumePage", "Master Volume", m_masterVolumeText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 100));
//     // creatText("VolumePage", "Mute Volume", m_muteVolumeText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_optionsBoxText.getPosition().y + 150));
//     // creatText("VolumePage", "<", m_decreaseVolumeText, sf::Vector2f(m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x - 150, m_optionsBoxText.getPosition().y + 100));
//     // creatText("VolumePage", "100", m_currVolumeText, sf::Vector2f(m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x - 100, m_optionsBoxText.getPosition().y + 100));
//     // creatText("VolumePage", "%", m_percentageText, sf::Vector2f(m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x - 50, m_optionsBoxText.getPosition().y + 100));
//     // creatText("VolumePage", ">", m_increaseVolumeText, sf::Vector2f(m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x, m_optionsBoxText.getPosition().y + 100));
//     // m_optionsBoxDisplayTextsMap.insert({"VolumePage", m_volumePageTextsVec});
//     creatHeadlineText("VolumePage", "VOLUME", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
//     m_headlineOptionsPageTextsVec[3].at(1).setPosition(sf::Vector2f(210,m_headlineOptionsPageTextsVec[3].at(1).getPosition().y));
//     m_headlineBarWidthDisplayTextsMap.insert({"VolumePage", m_headlineOptionsPageTextsVec[3]});
// }

// void MenuScreenHandler::createControlSettingPageText()
// {
//     // creatText("ControlSettingPage", "Release Ball: ", m_masterVolumeText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_releaseButtonBox.getPosition().y + m_releaseButtonBox.getSize().y/2 - 10));
//     // creatText("ControlSettingPage", "Move Paddle Left: ", m_decreaseVolumeText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_moveLeftButtonBox.getPosition().y + m_moveLeftButtonBox.getSize().y/2 - 10));
//     // creatText("ControlSettingPage", "Move Paddle Right: ", m_currVolumeText, sf::Vector2f(m_optionsBoxText.getPosition().x + 40, m_moveRightButtonBox.getPosition().y + m_moveRightButtonBox.getSize().y/2 - 10));

//     // m_optionsBoxDisplayTextsMap.insert({"ControlSettingPage", m_controlSettingPageTextsVec});
//     creatHeadlineText("ControlSettingPage", "CONTROLS", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
//     m_headlineOptionsPageTextsVec[4].at(1).setPosition(sf::Vector2f(200,m_headlineOptionsPageTextsVec[4].at(1).getPosition().y));
//     m_headlineBarWidthDisplayTextsMap.insert({"ControlSettingPage", m_headlineOptionsPageTextsVec[4]});
// }

// bool MenuScreenHandler::mouseHoverButton(sf::Text &text)
// {
//     bool mouseHover = text.getGlobalBounds().contains(m_inputHandler.getMousePosition());
    
//     if (mouseHover && !m_isMouseHovering) {
//         if (!m_isMusicPlayed)
//         {
//             text.setFillColor(sf::Color::White);
//             SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
//             m_isMouseHovering = true;
//             m_isMusicPlayed = true;
//         }
//     } else if (!mouseHover) {
//         text.setFillColor(m_color);
//         m_isMouseHovering = false;
//     }
//     return mouseHover;
// }

// State MenuScreenHandler::getState(std::string page)
// {
//     State state;
//     if (page == "DifficultyPage") {
//         state = State::DifficultyPage;
//     } else if (page == "VideoPage") {
//         state = State::VideoPage;
//     } else if (page == "VolumePage") {
//         state = State::VolumePage;
//     } else if (page == "ControlSettingPage") {
//         state = State::ControlSettingPage;
//     }
//     m_isSelected = false;
    
//     return state;
// }

// void MenuScreenHandler::drewBarsLine()
// {
//     m_window.draw(m_barWidthLine);
//     m_window.draw(m_barHightLine);
// }

// void MenuScreenHandler::drewControlsPage()
// {
//     if (m_currPage == "ControlSettingPage") {
//         m_window.draw(m_releaseButtonBox);
//         m_window.draw(m_moveLeftButtonBox);
//         m_window.draw(m_moveRightButtonBox);
//     }
// }

// void MenuScreenHandler::drewHeadline()
// {
//     for (size_t i = 0; i < m_headlineBarWidthDisplayTextsMap[m_currPage].size(); i++) {
//         if (m_headlineBarWidthDisplayTextsMap[m_currPage].size() == 1) {
//             m_headlineBarWidthDisplayTextsMap[m_currPage].at(0).setFillColor(sf::Color::White);
//         } else {
//             m_headlineBarWidthDisplayTextsMap[m_currPage].at(1).setFillColor(sf::Color::White);
//         }
//         m_window.draw(m_headlineBarWidthDisplayTextsMap[m_currPage].at(i));
//     }
// }

// void MenuScreenHandler::drewOptions()
// {
//     for (size_t i = 0; i < m_optionsBoxDisplayTextsMap[m_currPage].size(); i++) {
//         if (!isStringInRange(m_optionsBoxDisplayTextsMap[m_currPage].at(i).getString())) {
//             m_window.draw(m_optionsBoxDisplayTextsMap[m_currPage].at(i));
//         } else {
//             m_optionsBoxDisplayTextsMap[m_currPage].at(i).setString(std::to_string(m_volumeManager.getVolume()));
//             m_window.draw(m_optionsBoxDisplayTextsMap[m_currPage].at(i));
//         }
        
//     } 
// }

// void MenuScreenHandler::drewBorders()
// {
//     m_window.draw(m_menuBox);
//     m_window.draw(m_barWidthBox);
//     m_window.draw(m_barCurrPageWidthBox);
//     m_window.draw(m_optionsBoxText);
//     m_window.draw(m_barHightBox);
//     m_window.draw(m_guidBoxText);
// }

// void MenuScreenHandler::updateMousePrestVolumePage(sf::Vector2f& mousePosition)
// {
//     for (auto& textVec : m_optionsBoxDisplayTextsMap) {
//         for (auto& text : textVec.second) {
//             if (text.getGlobalBounds().contains(mousePosition)) {
//                 if (text.getString() == "<") {
//                     m_volumeManager.decreaseVolume(10);
//                     m_currVolumeText.setString(std::to_string(m_volumeManager.getVolume()));
//                 } else if (text.getString() == ">") {
//                     m_volumeManager.increaseVolume(10);
//                     m_currVolumeText.setString(std::to_string(m_volumeManager.getVolume()));
//                 } else if (text.getString() == "Mute Volume") {
//                     if (m_volumeManager.getVolume() != 0) {
//                         m_volumeManager.setVolume(0);
//                         m_currVolumeText.setString(std::to_string(m_volumeManager.getVolume()));
//                     } else {
//                         m_volumeManager.setVolume(100);
//                         m_currVolumeText.setString(std::to_string(m_volumeManager.getVolume()));
//                     }
                    
//                 }
//             }
//         }
//     }
// }

// void MenuScreenHandler::updateMousePrestVideoPage(sf::Vector2f& mousePosition)
// {
//     for (auto& textVec : m_optionsBoxDisplayTextsMap) {
//         for (auto& text : textVec.second) {
//             if (text.getGlobalBounds().contains(mousePosition)) {
//                 if (text.getString() == "FullScreen") {
//                     m_volumeManager.decreaseVolume(10);
//                     m_currVolumeText.setString(std::to_string(m_volumeManager.getVolume()));
//                 } else if (text.getString() == ">") {
//                     m_volumeManager.increaseVolume(10);
//                     m_currVolumeText.setString(std::to_string(m_volumeManager.getVolume()));
//                 } else if (text.getString() == "Mute Volume") {
//                     if (m_volumeManager.getVolume() != 0) {
//                         m_volumeManager.setVolume(0);
//                         m_currVolumeText.setString(std::to_string(m_volumeManager.getVolume()));
//                     } else {
//                         m_volumeManager.setVolume(100);
//                         m_currVolumeText.setString(std::to_string(m_volumeManager.getVolume()));
//                     }
                    
//                 }
//             }
//         }
//     }
// }
