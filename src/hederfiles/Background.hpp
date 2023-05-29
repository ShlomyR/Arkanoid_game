#pragma once

#include <SFML/Graphics.hpp>

class Background
{
public:
    Background();

    void draw(sf::RenderWindow &);
    
private:
    void init();
    sf::Texture m_backgroundTexture;
    sf::Sprite m_backgroundSprite;
};
