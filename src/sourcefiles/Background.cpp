#include "Background.hpp"


Background::Background()
{
    init();
}

void Background::draw(sf::RenderWindow &window)
{
    window.draw(m_backgroundSprite);
}

void Background::init()
{
    if (!m_backgroundTexture.loadFromFile("src/images/Space.jpg")) {
        throw std::runtime_error("The image fails to load: src/images/wallpapersden.com_colorful-space_800x600.jpg");
    }
    sf::Sprite backgroundSprite(m_backgroundTexture);
    m_backgroundSprite = backgroundSprite;
}
