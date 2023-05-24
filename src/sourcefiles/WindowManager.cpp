#include "../hederfiles/WindowManager.hpp"


WindowManager::WindowManager(const sf::Vector2u& windowSize, const std::string& windowTitle)
:   m_window(sf::VideoMode(windowSize.x, windowSize.y), windowTitle)
{
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::Vector2i windowPosition(desktopMode.width / 2 - windowSize.x / 2, desktopMode.height / 2 - windowSize.y / 2);
    m_window.setPosition(windowPosition);
    m_window.setFramerateLimit(60);

}

bool WindowManager::isOpen() const {
    return m_window.isOpen();
}

void WindowManager::clear() {
    m_window.clear();
}

void WindowManager::display() {
    m_window.display();
}

void WindowManager::pollEvent(sf::Event& event) {
    m_window.pollEvent(event);
}

void WindowManager::draw(const sf::Drawable& drawable) {
    m_window.draw(drawable);
}

void WindowManager::draw(const sf::Vertex* vertices, std::size_t vertexCount, sf::PrimitiveType type) {
    m_window.draw(vertices, vertexCount, type);
}

sf::RenderWindow &WindowManager::getRenderWindow()
{
    return m_window;
}

sf::Vector2u WindowManager::getSize() const
{
    return m_window.getSize();
}