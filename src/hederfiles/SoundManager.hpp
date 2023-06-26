#pragma once

#include <SFML/Audio.hpp>

#include <memory>

class SoundManager
{
public:
    ~SoundManager();
    static SoundManager *getInstance();

    void playSound(const std::string&);
    void playSound();
    void stopSound();
    void pausedSound();
    void setLoop(bool);
    void switchSound(const std::string&);

    void playMusic(const std::string&);
    void playMusic();
    void stopSMusic();
    void pausedMusic();
    void setMusicLoop(bool);
    void switchMusic(const std::string&);
private:
    SoundManager() {}
    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;

    sf::Sound m_sound;
    sf::Music m_music;
    std::unique_ptr<sf::SoundBuffer> m_soundBuffer;
};

