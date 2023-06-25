#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <unordered_map>
#include "GameState.hpp"

class MenuScreenHandler
{
public:
    MenuScreenHandler(sf::RenderWindow&);
    void draw();
    void updateBox(std::string);
    void setCurrPage(std::string);
    void setIsSelected(bool);
    void updatePos(const sf::Vector2u &windowSize);

    sf::RectangleShape getOptionsBoxShape();
    sf::RectangleShape getReleaseButtonShape();
    sf::RectangleShape getMoveLeftButtonShape();
    sf::RectangleShape getMoveRightButtonShape();
private:
    void init();
    void creatHeadlineText(std::string, std::string, sf::Text&, sf::Vector2f);
    void refinedBox(sf::RectangleShape&, sf::Vector2f, sf::Vector2f,sf::Color);
    void refinedBoxes();
    void createOptionsPageText();
    void createHighScorePageText();
    void createDifficultyPageText();
    void createVideoPageText();
    void createVolumePageText();
    void createControlSettingPageText();
    void drewBarsLine();
    void drewControlsPage();
    void drewHighScorePage();
    void drewHeadline();
    void drewBorders();
private:
    std::vector<sf::Text> m_optionsCurrPageVec;
    std::vector<std::vector<sf::Text>> m_headlineOptionsPageTextsVec;
    std::unordered_map<std::string, std::vector<sf::Text>> m_optionsBoxDisplayTextsMap;
    std::unordered_map<std::string, std::vector<sf::Text>> m_headlineBarWidthDisplayTextsMap;

    sf::RectangleShape m_guidBoxText;
    sf::RectangleShape m_barWidthBox;
    sf::RectangleShape m_barWidthLine;
    sf::RectangleShape m_barHightLine;
    sf::RectangleShape m_barCurrPageWidthBox;
    sf::RectangleShape m_barHightBox;
    sf::RectangleShape m_menuBox;

    sf::Text m_optionHeadlineText;

    sf::RectangleShape m_optionsBoxText;
    sf::RectangleShape m_releaseButtonBox;
    sf::RectangleShape m_moveLeftButtonBox;
    sf::RectangleShape m_moveRightButtonBox;

    sf::Font m_font;
    sf::Color m_color;
    sf::RenderWindow &m_window;

    int m_counter;
    bool m_isSelected;
    std::string m_currPage;
};
