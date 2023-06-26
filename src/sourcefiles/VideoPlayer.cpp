#include "VideoPlayer.hpp"
#include <stdexcept>

VideoPlayer::VideoPlayer(sf::RenderWindow& window)
    : m_window(window) {
}

void VideoPlayer::playVideo(const std::string& filePath) {
    if (!m_movie.openFromFile(filePath)) {
        throw std::runtime_error("Failed to open file: " + filePath);
    }

    m_movie.fit(0, 0, m_window.getSize().x, m_window.getSize().y);
    m_movie.play();

    m_blurBackground.setSize(sf::Vector2f(static_cast<float>(m_window.getSize().x), static_cast<float>(m_window.getSize().y)));
    m_blurBackground.setFillColor(sf::Color(20, 20, 20, 215));
}

void VideoPlayer::update() {
    m_movie.update();
}

void VideoPlayer::render() {
    m_window.draw(m_movie);
}

sf::RectangleShape VideoPlayer::getBackground() {
    return m_blurBackground;
}

bool VideoPlayer::isPlaying() const {
    return m_movie.getStatus() == sfe::Status::Playing;
}

void VideoPlayer::pause() {
    m_movie.pause();
}

void VideoPlayer::resume() {
    m_movie.play();
}

void VideoPlayer::stop() {
    m_movie.stop();
}

void VideoPlayer::moveForward() {
    sf::Time currentTime = m_movie.getPlayingOffset();
    sf::Time newTime = currentTime + sf::seconds(5.0f); // Adjust the duration as needed
    m_movie.setPlayingOffset(newTime);
}

void VideoPlayer::moveBackward() {
    sf::Time currentTime = m_movie.getPlayingOffset();
    sf::Time newTime = currentTime - sf::seconds(5.0f); // Adjust the duration as needed
    m_movie.setPlayingOffset(newTime);
}
