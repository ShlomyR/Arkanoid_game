#include "VolumeManager.hpp"
#include "SoundManager.hpp"
#include "MenuScreenHandler.hpp"

#include <iostream>

bool VolumeManager::m_isMusicPlayed;

void printTextVector(const std::vector<std::vector<sf::Text*>>& textVector) {
    int i = -1;
    for (const auto& row : textVector) {
        std::cout << "vec:" << ++i << "\n";
        for (const auto& text : row) {
            std::cout << text->getString().toAnsiString() << ",\n";
        }
        std::cout << std::endl;
    }
}

VolumeManager::VolumeManager(sf::RenderWindow &window, MenuScreenHandler &menuScreenHandler)
: m_volume(100)
, m_window(window)
, m_menuScreenHandler(menuScreenHandler)
{
    initializeGUI();
}

void VolumeManager::initializeGUI()
{
    if (!m_font.loadFromFile("src/fonts/DIN.ttf")) {
        std::cout << "Failed to load font!" << "\n";
    }
    makeText(m_masterVolumeText, m_font, "Master Volume", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 100));
    makeText(m_muteText, m_font, "Mute Volume", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 150));
    makeText(m_minusText, m_font, "<", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + m_menuScreenHandler.getOptionsBoxShape().getSize().x - 150, m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 100));
    makeText(m_volumeText, m_font, std::to_string(m_volume) + " %", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + m_menuScreenHandler.getOptionsBoxShape().getSize().x - 100, m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 100));
    makeText(m_pluseText, m_font, ">", sf::Vector2i(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + m_menuScreenHandler.getOptionsBoxShape().getSize().x , m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 100));
    initVectors();
}

void VolumeManager::initVectors()
{
    std::vector<sf::Text*> tmp;
    tmp.push_back(&m_masterVolumeText);
    tmp.push_back(&m_muteText);
    m_volumeVec.push_back(tmp);
    tmp.clear();
    tmp.push_back(&m_minusText);
    tmp.push_back(&m_pluseText);
    m_volumeVec.push_back(tmp);
    printTextVector(m_volumeVec);
}

void VolumeManager::draw()
{
    m_window.draw(m_masterVolumeText);
    m_window.draw(m_muteText);
    m_window.draw(m_pluseText);
    m_window.draw(m_minusText);
    m_window.draw(m_volumeText);
}

void VolumeManager::updateMouseMoved(sf::Vector2f& mousePosition)
{
    bool isMouseHovering = false;
    for (auto& controlText : m_controlTexts) {
        if (sf::Joystick::isConnected(0)) {
            if (controlText.second->getFillColor() == sf::Color::White) {
                isMouseHovering = true;
                controlText.second->setOutlineColor(sf::Color::White);
                controlText.second->setFillColor(sf::Color::White);
                controlText.second->setOutlineThickness(2);
            } else {
                controlText.second->setOutlineColor(sf::Color{ 128,128,128 });
                controlText.second->setOutlineThickness(0);
                controlText.second->setFillColor(sf::Color{ 128,128,128 });
            }
        } else if (controlText.second->getGlobalBounds().contains(mousePosition)) {
            isMouseHovering = true;
            controlText.second->setOutlineColor(sf::Color::White);
            controlText.second->setFillColor(sf::Color::White);
            controlText.second->setOutlineThickness(2);
        } else {
            controlText.second->setOutlineColor(sf::Color{ 128,128,128 });
            controlText.second->setOutlineThickness(0);
            controlText.second->setFillColor(sf::Color{ 128,128,128 });
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
    for (auto& controlText : m_controlTexts) {
        if (controlText.second->getGlobalBounds().contains(mousePosition) || controlText.second->getFillColor() == sf::Color::White) {
            if (controlText.first == "<") {
                decreaseVolume(10);
            } else if (controlText.first == ">") {
                increaseVolume(10);
            } else if (controlText.first == "Mute Volume") {
                if (m_volume != 0) {
                    setVolume(0);
                } else {
                    setVolume(100);
                }
                
            }
        }
    }
}

std::vector<std::pair<std::string, sf::Text *>> VolumeManager::getTexts()
{
    return m_controlTexts;
}

void VolumeManager::makeText(sf::Text &text, sf::Font &font, std::string str, sf::Vector2i vec2i)
{
    if (str != std::to_string(m_volume) + " %") {
        text.setFont(font);
        text.setCharacterSize(48);
        text.setFillColor(sf::Color{ 128,128,128 });
        text.setString(str);
        text.setScale(0.5, 0.5);
        text.setPosition(vec2i.x,vec2i.y);
        m_controlTexts.emplace_back(str, &text);
    } else {
        text.setFont(font);
        text.setCharacterSize(48);
        text.setFillColor(sf::Color::White);
        text.setString(str);
        text.setScale(0.5, 0.5);
        text.setOutlineColor(sf::Color::White);
        text.setOutlineThickness(2);
        text.setPosition(vec2i.x,vec2i.y);
    }
}

void VolumeManager::updateText(const sf::Vector2u &)
{
    m_masterVolumeText.setPosition(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 100);
    m_muteText.setPosition(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + 40, m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 150);
    m_minusText.setPosition(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + m_menuScreenHandler.getOptionsBoxShape().getSize().x - 150, m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 100);
    m_volumeText.setPosition(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + m_menuScreenHandler.getOptionsBoxShape().getSize().x - 100, m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 100);
    m_pluseText.setPosition(m_menuScreenHandler.getOptionsBoxShape().getPosition().x + m_menuScreenHandler.getOptionsBoxShape().getSize().x , m_menuScreenHandler.getOptionsBoxShape().getPosition().y + 100);
}

int VolumeManager::getVolume()
{
    return m_volume;
}

std::vector<std::vector<sf::Text*>> VolumeManager::getVectorsTexts()
{
    return m_volumeVec;
}

void VolumeManager::setVolume(int volume)
{
    if (volume >= 0 && volume <= 100) {
        m_volume = volume;
        updateVolume();
        m_volumeText.setString(std::to_string(m_volume) + " %");
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
}
