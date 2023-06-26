#pragma once

#include "MenuOption.hxx"

class PlayOption : public MenuOption
{
public:
    void draw(sf::RenderWindow& ) override;
    void makeButton(sf::RenderWindow&) override;
    bool handleInput(InputHandler& , GameState &) override;
    bool isSelected() const override;
    void setIsSelected(bool) override;
    sf::Text* getText() override;
    void setIsTranslucent(bool) override;
    void setBoxBorder(sf::RectangleShape&) override;
    void updateColor(sf::Text&, sf::Color);
private:
    sf::Text m_playText;
    bool m_isSelected = false;
    bool m_isTranslucent;
    bool m_mouseCurser = false;
    static bool m_isMusicPlayed;
    sf::RectangleShape m_boxBorder;
    int m_counter = 0;

};
