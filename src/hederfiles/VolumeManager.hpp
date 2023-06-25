#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuScreenHandler;

class VolumeManager 
{
public:
    VolumeManager(sf::RenderWindow &, MenuScreenHandler&);

    void setVolume(int);
    void increaseVolume(int);
    void decreaseVolume(int);
    std::vector<std::pair<std::string, sf::Text *>> getTexts();
    void draw();
    void updateMouseMoved(sf::Vector2f&);
    void updateMousePrest(sf::Vector2f&);
    void updateText(const sf::Vector2u&);
    int getVolume();
private:
    void initializeGUI();
    void makeText(sf::Text &, sf::Font &, std::string, sf::Vector2i);
    void updateVolume();
private:
    int m_volume;
    bool static m_isMusicPlayed;
    sf::Font m_font;
    sf::Text m_masterVolumeText;
    sf::Text m_muteText;
    sf::Text m_pluseText;
    sf::Text m_minusText;
    sf::Text m_volumeText;
    std::vector<std::pair<std::string, sf::Text *>> m_controlTexts;
    sf::RenderWindow &m_window;
    MenuScreenHandler &m_menuScreenHandler;
};
