#pragma once

#include "MenuOption.hxx"


class InstructionsOption : public MenuOption
{
public:
    void draw(sf::RenderWindow& ) override;
    bool handleInput(InputHandler& , GameState &) override;
    void makeButton(sf::RenderWindow&) override;
    bool isSelected() const override;
    void setIsSelected(bool) override;
    sf::Text* getText() override;
    void setIsTranslucent(bool) override {}
    void setBoxBorder(sf::RectangleShape&) override;
    void updateColor(sf::Text&, sf::Color);
private:
    sf::Text m_instructionsText;
    bool m_isSelected = false;
    bool m_mouseCurser = false;
    static bool m_isMusicPlayed;
    sf::RectangleShape m_boxBorder;
};
