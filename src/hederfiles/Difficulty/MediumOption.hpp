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
    // void setColorOfOtherTextToTransparent();
private:
    sf::Text m_mediumText;
    bool m_isSelected = false;
    static bool m_isMusicPlayed;
    bool m_isTranslucent = true;
};
