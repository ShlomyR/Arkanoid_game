#pragma once

#include <SFML/Graphics.hpp>

class WindowManager
{
public:
    WindowManager(const sf::Vector2u& windowSize, const std::string& windowTitle);
    bool isOpen() const;
    void clear();
    void display();
    void pollEvent(sf::Event& event);
    void draw(const sf::Drawable& drawable);
    void draw(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type);
    sf::RenderWindow &getRenderWindow();
    sf::Vector2u getSize() const;
private:
    sf::RenderWindow m_window;
};