#pragma once

#include "MenuOption.hxx"


class MediumOption : public MenuOption
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
    // void setColorOfOtherTextToTransparent();
private:
    sf::Text m_mediumText;
    bool m_isSelected = false;
    bool m_mouseCurser = false;
    static bool m_isMusicPlayed;
    bool m_isTranslucent = true;
    sf::Color m_color;
    sf::RectangleShape m_boxBorder;
};
