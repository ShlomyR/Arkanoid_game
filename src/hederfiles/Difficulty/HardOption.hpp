#pragma once

#include "MenuOption.hxx"


class HardOption : public MenuOption
{
public:
    void draw(sf::RenderWindow& ) override;
    bool handleInput(InputHandler& , GameState &) override;
    void makeButton(sf::RenderWindow&) override;
    bool isSelected() const override;
    void setIsSelected(bool) override;
    sf::Text* getText() override;
    void setIsTranslucent(bool value) override;
    void setBoxBorder(sf::RectangleShape&) override;
    void updateColor(sf::Text&, sf::Color);
private:
    sf::Text m_hardText;
    bool m_isSelected = false;
    bool m_mouseCurser = false;
    static bool m_isMusicPlayed;
    bool m_isTranslucent = true;
    sf::Color m_color;
    sf::RectangleShape m_boxBorder;
};
