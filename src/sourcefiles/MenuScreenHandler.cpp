#include "MenuScreenHandler.hpp"

#include <iostream>

#define BAR_SIZE 1.5
#define BUTTON_OFFSET_BETWEEN_SIZE 10
#define BUTTON_OFFSET_X_SIZE 10

MenuScreenHandler::MenuScreenHandler(sf::RenderWindow &window)
: m_window(window)
{
    init();
}

void MenuScreenHandler::init()
{
    m_counter = 0;
    m_isSelected = false;
    m_font.loadFromFile("src/fonts/DIN.ttf");
    m_color = sf::Color{ 128,128,128 };
    refinedBoxes();
    createOptionsPageText();
    createDifficultyPageText();
    createVideoPageText();
    createVolumePageText();
    createControlSettingPageText();
    createHighScorePageText();
    m_currPage = "OptionsPage";
}

void MenuScreenHandler::creatHeadlineText(std::string page,std::string str, sf::Text& text, sf::Vector2f pos)
{
    text.setString(str);
    text.setFont(m_font);
    text.setScale(0.7,0.7);
    text.setCharacterSize(48);
    text.setFillColor(m_color);
    text.setOutlineThickness(2);
    text.setOutlineColor(m_color);
    text.setPosition(pos);
    m_optionsCurrPageVec.push_back(text);
    if (page == "OptionsPage") {
        m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
    } else if (page == "DifficultyPage") {
        m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
    } else if (page == "VideoPage") {
        m_optionsCurrPageVec.erase(m_optionsCurrPageVec.begin() + 1);
        m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
    } else if (page == "VolumePage") {
        m_optionsCurrPageVec.erase(m_optionsCurrPageVec.begin() + 1);
        m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
    } else if (page == "ControlSettingPage") {
        m_optionsCurrPageVec.erase(m_optionsCurrPageVec.begin() + 1);
        m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
    } else if (page == "HighScorePage") {
        m_optionsCurrPageVec.erase(m_optionsCurrPageVec.begin() + 1);
        m_optionsCurrPageVec.erase(m_optionsCurrPageVec.begin());
        m_headlineOptionsPageTextsVec.push_back(m_optionsCurrPageVec);
    }
}

void MenuScreenHandler::draw()
{
    // drewBorders();
    drewBarsLine();
    drewControlsPage();
    drewHeadline();
    drewHighScorePage();
    // drewOptions();   
}

void MenuScreenHandler::updateBox(std::string currPage)
{
    if (m_counter == 2) {
        m_counter = 0;
    }
    if (currPage == "OptionsPage") {
        if (m_counter == 0) {
            m_barCurrPageWidthBox.setSize(sf::Vector2f(250, m_barCurrPageWidthBox.getSize().y));
            m_barWidthBox.setSize(sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), 40)); 
            m_barWidthBox.setPosition(sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ));
            m_barWidthLine.setSize(sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), BAR_SIZE)); 
            m_barWidthLine.setPosition(sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, m_barWidthBox.getPosition().y + (m_barWidthBox.getSize().y/2 - m_barWidthLine.getSize().y/2)));
            ++m_counter;
        }
    } else if (currPage != "OptionsPage") {
        if (m_counter == 1) {
            m_barCurrPageWidthBox.setSize(sf::Vector2f(350, m_barCurrPageWidthBox.getSize().y));
            m_barWidthBox.setSize(sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), 40)); 
            m_barWidthBox.setPosition(sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ));
            m_barWidthLine.setSize(sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), BAR_SIZE)); 
            m_barWidthLine.setPosition(sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, m_barWidthBox.getPosition().y + (m_barWidthBox.getSize().y/2 - m_barWidthLine.getSize().y/2)));     
            ++m_counter;
        }
    }
}

void MenuScreenHandler::refinedBox(sf::RectangleShape& recShape, sf::Vector2f size, sf::Vector2f pos, sf::Color color)
{
    recShape.setSize(size);
    recShape.setPosition(pos);
    recShape.setFillColor(color);
}

void MenuScreenHandler::setCurrPage(std::string page)
{
    m_currPage = page;
}

void MenuScreenHandler::setIsSelected(bool val)
{
    m_isSelected = val;
}

void MenuScreenHandler::updatePos(const sf::Vector2u &windowSize)
{
    refinedBox(m_menuBox, sf::Vector2f(windowSize.x - 40, windowSize.y - 40), sf::Vector2f(20 , 20), sf::Color::White);
    refinedBox(m_barCurrPageWidthBox, sf::Vector2f(250 , 40), sf::Vector2f(m_menuBox.getPosition().x + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ), sf::Color::Blue);
    refinedBox(m_barWidthBox, sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), 40), sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ), sf::Color{20,20,20,150});
    refinedBox(m_optionsBoxText, sf::Vector2f(m_menuBox.getSize().x / 2, m_menuBox.getSize().y / 1.3), sf::Vector2f((m_menuBox.getSize().x - m_menuBox.getSize().x ) + 40, m_barWidthBox.getPosition().y + 100), sf::Color::Green);
    refinedBox(m_barHightBox, sf::Vector2f( 40, m_menuBox.getSize().y - (m_barWidthBox.getPosition().y + m_barWidthBox.getSize().y)), sf::Vector2f(m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x + 20, m_barWidthBox.getPosition().y + m_barWidthBox.getSize().y + 20), sf::Color{20,20,20,150});
    refinedBox(m_guidBoxText, sf::Vector2f(m_menuBox.getSize().x / 2.3, m_menuBox.getSize().y / 1.3), sf::Vector2f(m_barHightBox.getPosition().x + m_barHightBox.getSize().x + 20, m_barWidthBox.getPosition().y + 100), sf::Color{20,20,20,150});
    refinedBox(m_barWidthLine, sf::Vector2f(m_barWidthBox.getSize().x, BAR_SIZE), sf::Vector2f(m_barWidthBox.getPosition().x, m_barWidthBox.getPosition().y + (m_barWidthBox.getSize().y/2 - m_barWidthLine.getSize().y/2)), sf::Color{255, 255, 249});
    refinedBox(m_barHightLine, sf::Vector2f(BAR_SIZE, m_barHightBox.getSize().y), sf::Vector2f(m_barHightBox.getPosition().x + (m_barHightBox.getSize().x/2 - m_barHightLine.getSize().x/2), m_barHightBox.getPosition().y), sf::Color{255, 255, 249});
    refinedBox(m_releaseButtonBox, sf::Vector2f(150, 70), sf::Vector2f((m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x)/2 + BUTTON_OFFSET_X_SIZE, m_optionsBoxText.getPosition().y + 70), sf::Color{20,20,20,150});
    refinedBox(m_moveLeftButtonBox, sf::Vector2f(150, 70), sf::Vector2f((m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x)/2 + BUTTON_OFFSET_X_SIZE, m_releaseButtonBox.getPosition().y + m_releaseButtonBox.getSize().y + BUTTON_OFFSET_BETWEEN_SIZE), sf::Color{20,20,20,150});
    refinedBox(m_moveRightButtonBox, sf::Vector2f(150, 70), sf::Vector2f((m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x)/2 + BUTTON_OFFSET_X_SIZE, m_moveLeftButtonBox.getPosition().y + m_moveLeftButtonBox.getSize().y + BUTTON_OFFSET_BETWEEN_SIZE), sf::Color{20,20,20,150});
    m_releaseButtonBox.setOutlineThickness(2);
    m_releaseButtonBox.setOutlineColor(sf::Color::White);
    m_moveLeftButtonBox.setOutlineThickness(2);
    m_moveLeftButtonBox.setOutlineColor(sf::Color::White);
    m_moveRightButtonBox.setOutlineThickness(2);
    m_moveRightButtonBox.setOutlineColor(sf::Color::White);
}

sf::RectangleShape MenuScreenHandler::getOptionsBoxShape()
{
    return m_optionsBoxText;
}

sf::RectangleShape MenuScreenHandler::getReleaseButtonShape()
{
    return m_releaseButtonBox;
}

sf::RectangleShape MenuScreenHandler::getMoveLeftButtonShape()
{
    return m_moveLeftButtonBox;
}

sf::RectangleShape MenuScreenHandler::getMoveRightButtonShape()
{
    return m_moveRightButtonBox;
}

void MenuScreenHandler::refinedBoxes()
{
    refinedBox(m_menuBox, sf::Vector2f(m_window.getSize().x - 40, m_window.getSize().y - 40), sf::Vector2f(20 , 20), sf::Color::White);
    refinedBox(m_barCurrPageWidthBox, sf::Vector2f(250 , 40), sf::Vector2f(m_menuBox.getPosition().x + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ), sf::Color::Blue);
    refinedBox(m_barWidthBox, sf::Vector2f(m_menuBox.getSize().x - (m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x), 40), sf::Vector2f((m_barCurrPageWidthBox.getSize().x + m_barCurrPageWidthBox.getPosition().x) + 20, (m_menuBox.getSize().y - m_menuBox.getSize().y) + 120 ), sf::Color{20,20,20,150});
    refinedBox(m_optionsBoxText, sf::Vector2f(m_menuBox.getSize().x / 2, m_menuBox.getSize().y / 1.3), sf::Vector2f((m_menuBox.getSize().x - m_menuBox.getSize().x ) + 40, m_barWidthBox.getPosition().y + 100), sf::Color::Green);
    refinedBox(m_barHightBox, sf::Vector2f( 40, m_menuBox.getSize().y - (m_barWidthBox.getPosition().y + m_barWidthBox.getSize().y)), sf::Vector2f(m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x + 20, m_barWidthBox.getPosition().y + m_barWidthBox.getSize().y + 20), sf::Color{20,20,20,150});
    refinedBox(m_guidBoxText, sf::Vector2f(m_menuBox.getSize().x / 2.3, m_menuBox.getSize().y / 1.3), sf::Vector2f(m_barHightBox.getPosition().x + m_barHightBox.getSize().x + 20, m_barWidthBox.getPosition().y + 100), sf::Color{20,20,20,150});
    refinedBox(m_barWidthLine, sf::Vector2f(m_barWidthBox.getSize().x, BAR_SIZE), sf::Vector2f(m_barWidthBox.getPosition().x, m_barWidthBox.getPosition().y + (m_barWidthBox.getSize().y/2 - m_barWidthLine.getSize().y/2)), sf::Color{255, 255, 249});
    refinedBox(m_barHightLine, sf::Vector2f(BAR_SIZE, m_barHightBox.getSize().y), sf::Vector2f(m_barHightBox.getPosition().x + (m_barHightBox.getSize().x/2 - m_barHightLine.getSize().x/2), m_barHightBox.getPosition().y), sf::Color{255, 255, 249});
    refinedBox(m_releaseButtonBox, sf::Vector2f(150, 70), sf::Vector2f((m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x)/2 + BUTTON_OFFSET_X_SIZE, m_optionsBoxText.getPosition().y + 70), sf::Color{20,20,20,150});
    refinedBox(m_moveLeftButtonBox, sf::Vector2f(150, 70), sf::Vector2f((m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x)/2 + BUTTON_OFFSET_X_SIZE, m_releaseButtonBox.getPosition().y + m_releaseButtonBox.getSize().y + BUTTON_OFFSET_BETWEEN_SIZE), sf::Color{20,20,20,150});
    refinedBox(m_moveRightButtonBox, sf::Vector2f(150, 70), sf::Vector2f((m_optionsBoxText.getPosition().x + m_optionsBoxText.getSize().x)/2 + BUTTON_OFFSET_X_SIZE, m_moveLeftButtonBox.getPosition().y + m_moveLeftButtonBox.getSize().y + BUTTON_OFFSET_BETWEEN_SIZE), sf::Color{20,20,20,150});
    m_releaseButtonBox.setOutlineThickness(2);
    m_releaseButtonBox.setOutlineColor(sf::Color::White);
    m_moveLeftButtonBox.setOutlineThickness(2);
    m_moveLeftButtonBox.setOutlineColor(sf::Color::White);
    m_moveRightButtonBox.setOutlineThickness(2);
    m_moveRightButtonBox.setOutlineColor(sf::Color::White);
}

void MenuScreenHandler::createOptionsPageText()
{
    creatHeadlineText("OptionsPage", "OPTIONS", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
    m_headlineBarWidthDisplayTextsMap.insert({"OptionsPage", m_headlineOptionsPageTextsVec[0]});
}

void MenuScreenHandler::createDifficultyPageText()
{
    creatHeadlineText("DifficultyPage", "DIFFICULTY", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
    m_headlineOptionsPageTextsVec[1].at(1).setPosition(sf::Vector2f(200,m_headlineOptionsPageTextsVec[1].at(1).getPosition().y));
    m_headlineBarWidthDisplayTextsMap.insert({"DifficultyPage", m_headlineOptionsPageTextsVec[1]});
}

void MenuScreenHandler::createVideoPageText()
{
    creatHeadlineText("VideoPage", "VIDEO", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
    m_headlineOptionsPageTextsVec[2].at(1).setPosition(sf::Vector2f(250,m_headlineOptionsPageTextsVec[2].at(1).getPosition().y));
    m_headlineBarWidthDisplayTextsMap.insert({"VideoPage", m_headlineOptionsPageTextsVec[2]});
}

void MenuScreenHandler::createVolumePageText()
{
    creatHeadlineText("VolumePage", "VOLUME", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
    m_headlineOptionsPageTextsVec[3].at(1).setPosition(sf::Vector2f(210,m_headlineOptionsPageTextsVec[3].at(1).getPosition().y));
    m_headlineBarWidthDisplayTextsMap.insert({"VolumePage", m_headlineOptionsPageTextsVec[3]});
}

void MenuScreenHandler::createControlSettingPageText()
{
    creatHeadlineText("ControlSettingPage", "CONTROLS", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
    m_headlineOptionsPageTextsVec[4].at(1).setPosition(sf::Vector2f(200,m_headlineOptionsPageTextsVec[4].at(1).getPosition().y));
    m_headlineBarWidthDisplayTextsMap.insert({"ControlSettingPage", m_headlineOptionsPageTextsVec[4]});
}

void MenuScreenHandler::createHighScorePageText()
{
    creatHeadlineText("HighScorePage", "HIGH SCORE", m_optionHeadlineText, sf::Vector2f(m_barCurrPageWidthBox.getPosition().x, m_barCurrPageWidthBox.getPosition().y));
    m_headlineBarWidthDisplayTextsMap.insert({"HighScorePage", m_headlineOptionsPageTextsVec[5]});
}

void MenuScreenHandler::drewBarsLine()
{
    m_window.draw(m_barWidthLine);
    m_window.draw(m_barHightLine);
}

void MenuScreenHandler::drewControlsPage()
{
    if (m_currPage == "ControlSettingPage") {
        m_window.draw(m_releaseButtonBox);
        m_window.draw(m_moveLeftButtonBox);
        m_window.draw(m_moveRightButtonBox);
    }
}

void MenuScreenHandler::drewHighScorePage()
{
    if (m_currPage == "HighScorePage") {
        // for (size_t i = 0; i < m_headlineBarWidthDisplayTextsMap[m_currPage].size(); i++) {
        //     if (m_headlineBarWidthDisplayTextsMap[m_currPage].size() == 1) {
        //         m_headlineBarWidthDisplayTextsMap[m_currPage].at(1).setFillColor(sf::Color::White);
        //     } else {
        //         m_headlineBarWidthDisplayTextsMap[m_currPage].at(0).setFillColor(sf::Color::White);
        //     }
            m_window.draw(m_headlineBarWidthDisplayTextsMap[m_currPage].at(0));
        // }
    }
}

void MenuScreenHandler::drewHeadline()
{
    for (size_t i = 0; i < m_headlineBarWidthDisplayTextsMap[m_currPage].size(); i++) {
        if (m_headlineBarWidthDisplayTextsMap[m_currPage].size() == 1) {
            m_headlineBarWidthDisplayTextsMap[m_currPage].at(0).setFillColor(sf::Color::White);
        } else {
            m_headlineBarWidthDisplayTextsMap[m_currPage].at(1).setFillColor(sf::Color::White);
        }
        m_window.draw(m_headlineBarWidthDisplayTextsMap[m_currPage].at(i));
    }
}

void MenuScreenHandler::drewBorders()
{
    m_window.draw(m_menuBox);
    m_window.draw(m_barWidthBox);
    m_window.draw(m_barCurrPageWidthBox);
    m_window.draw(m_optionsBoxText);
    m_window.draw(m_barHightBox);
    m_window.draw(m_guidBoxText);
}
