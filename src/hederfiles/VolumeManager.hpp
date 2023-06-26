#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class VolumeManager {
public:
    VolumeManager(sf::RenderWindow &);

    void setVolume(int);
    void increaseVolume(int);
    void decreaseVolume(int);
    void draw();
    void updateMouseMoved(sf::Vector2f&);
    void updateMousePrest(sf::Vector2f&);
    void updateText(const sf::Vector2u&);
private:
    void initializeGUI();
    void makeText(sf::Text &, sf::Font &, std::string, sf::Vector2i);
    void updateVolume();
private:
    int m_volume;
    bool static m_isMusicPlayed;
    sf::Font m_font;
    sf::Text m_pluseText;
    sf::Text m_minusText;
    sf::Text m_volumeText;
    sf::Text m_muteText;
    std::vector<std::pair<std::string, sf::Text *>> m_controlTexts;
    sf::RenderWindow &m_window;

};
