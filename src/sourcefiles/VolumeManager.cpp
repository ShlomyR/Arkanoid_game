#include "VolumeManager.hpp"
#include "SoundManager.hpp"

#include <iostream>

bool VolumeManager::m_isMusicPlayed;

VolumeManager::VolumeManager(sf::RenderWindow &window)
: m_volume(100)
, m_window(window)
{
    initializeGUI();
}

void VolumeManager::initializeGUI()
{
    if (!m_font.loadFromFile("src/fonts/kenVectoFuture2.ttf")) {
        std::cout << "Failed to load font!" << "\n";
    }

    makeText(m_pluseText, m_font, "Pluse", sf::Vector2i(m_window.getSize().x - 700, 10));
    makeText(m_minusText, m_font, "Minus", sf::Vector2i(m_window.getSize().x -700, 110));
    makeText(m_volumeText, m_font, "Volume: " + std::to_string(m_volume) + " %", sf::Vector2i(m_window.getSize().x - 700, 210));
    makeText(m_muteText, m_font, "Mute", sf::Vector2i(m_window.getSize().x - 210, 10));
}

void VolumeManager::draw()
{
    m_window.draw(m_pluseText);
    m_window.draw(m_minusText);
    m_window.draw(m_volumeText);
    m_window.draw(m_muteText);
}

void VolumeManager::updateMouseMoved(sf::Vector2f& mousePosition)
{
    bool isMouseHovering = false;
    for (auto& controlText : m_controlTexts) {
        if (controlText.second->getGlobalBounds().contains(mousePosition)) {
            isMouseHovering = true;
            controlText.second->setOutlineColor(sf::Color::Blue);
            controlText.second->setFillColor(sf::Color::Yellow);
            controlText.second->setOutlineThickness(2);
        } else {
            controlText.second->setOutlineColor(sf::Color::White);
            controlText.second->setOutlineThickness(0);
            controlText.second->setFillColor(sf::Color::White);
        }
    }

    if (isMouseHovering && !m_isMusicPlayed) {
        SoundManager::getInstance()->playSound("src/sounds/Menu_Selection_Click.wav");
        m_isMusicPlayed = true;
    } else if (!isMouseHovering) {
        m_isMusicPlayed = false;
    }
}

void VolumeManager::updateMousePrest(sf::Vector2f& mousePosition)
{
    // int currVolume = 0;
    for (auto& controlText : m_controlTexts) {
        if (controlText.second->getGlobalBounds().contains(mousePosition)) {
            if (controlText.first == "Minus") {
                decreaseVolume(10);
            } else if (controlText.first == "Pluse") {
                increaseVolume(10);
            } else if (controlText.first == "Mute") {
                if (m_volume != 0) {
                    setVolume(0);
                } else {
                    setVolume(100);
                }
                
            }
        }
    }
}

void VolumeManager::makeText(sf::Text &text, sf::Font &font, std::string str, sf::Vector2i vec2i)
{
    if (str != "Volume: " + std::to_string(m_volume) + " %") {
        text.setFont(font);
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::White);
        text.setString(str);
        text.setPosition(vec2i.x,vec2i.y);
        m_controlTexts.emplace_back(str, &text);
    } else {
        text.setFont(font);
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::Green);
        text.setString(str);
        text.setOutlineColor(sf::Color::Blue);
        text.setOutlineThickness(2);
        text.setPosition(vec2i.x,vec2i.y);
    }
}

void VolumeManager::updateText(const sf::Vector2u &windowSize)
{
    int size = -200;
    for (auto& controlText : m_controlTexts) {
        sf::Vector2f buttonPos = sf::Vector2f(windowSize.x / 2 - controlText.second->getGlobalBounds().width / 2, windowSize.y / 2 + size);
        controlText.second->setPosition(buttonPos);
        size += 100;
    }
    m_volumeText.setPosition(sf::Vector2f(windowSize.x / 2 - m_volumeText.getGlobalBounds().width / 2, windowSize.y / 2 + size));
}

void VolumeManager::setVolume(int volume)
{
    if (volume >= 0 && volume <= 100) {
        m_volume = volume;
        updateVolume();
        m_volumeText.setString("Volume: " + std::to_string(m_volume) + " %");
    }
}

void VolumeManager::increaseVolume(int increment)
{
    setVolume(m_volume + increment);
}

void VolumeManager::decreaseVolume(int decrement)
{
    setVolume(m_volume - decrement);
}

void VolumeManager::updateVolume()
{
    sf::Listener::setGlobalVolume(m_volume);

    // You can also update the volume of specific sound or music objects here
    // For example:
    // sound.setVolume(m_volume);
    // music.setVolume(m_volume);
}
