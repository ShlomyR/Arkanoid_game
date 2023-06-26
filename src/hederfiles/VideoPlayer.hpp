#pragma once

#include <SFML/Config.hpp>
#include <SFML/Graphics.hpp>
#include <sfeMovie/Movie.hpp>

class VideoPlayer 
{
public:
    VideoPlayer(sf::RenderWindow& window);

    void playVideo(const std::string& filePath);
    void update();
    void render();
    bool isPlaying() const;
    void pause();
    void resume();
    void stop();
    void moveForward();
    void moveBackward();
    sf::RectangleShape getBackground();
private:
    sf::RenderWindow& m_window;
    sfe::Movie m_movie;
    sf::RectangleShape m_blurBackground;
};
