#include "SoundManager.hpp"

SoundManager::~SoundManager()
{}

SoundManager *SoundManager::getInstance()
{
    static SoundManager instance;
    return &instance;
}

void SoundManager::playSound(const std::string &filePath)
{
    m_soundBuffer = std::make_unique<sf::SoundBuffer>();
    if (!m_soundBuffer->loadFromFile(filePath)) {
        throw std::runtime_error("The Sound buffer dont loaded!!!");
        return;
    }
    m_sound.setBuffer(*m_soundBuffer);
    m_sound.setVolume(80);
    m_sound.play();
}

void SoundManager::play()
{
    m_sound.play();
}

void SoundManager::stopSound()
{
    m_sound.stop();
}

void SoundManager::setLoop(bool loop)
{
    m_sound.setLoop(loop);
}

void SoundManager::switchSound(const std::string &filename)
{
    stopSound();
    playSound(filename);
}

void SoundManager::playMusic(const std::string &filePath)
{
    if (!m_music.openFromFile(filePath)) {
        throw std::runtime_error("The Sound buffer dont loaded!!!");
        return;
    }
    m_music.play();
}

void SoundManager::stopSMusic()
{
    m_music.stop();
}

void SoundManager::setMusicLoop(bool loop)
{
    m_music.setLoop(loop);
}

void SoundManager::switchMusic(const std::string &filename)
{
    stopSMusic();
    playMusic(filename);
}
