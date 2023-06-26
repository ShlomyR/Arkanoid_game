#pragma once

#include <string>

#include <SFML/Graphics.hpp>
class Hud;

struct Data{
    std::string name;
    int score;
};

class HighScoreManager 
{
public:
    HighScoreManager();

    size_t getFirstHighScore();
    std::string const& getStringName();
    sf::Text const& getInputString();
    bool getIsHighScoreShown();

    void setIsHighScoreShown(bool);

    void drew(sf::RenderWindow &);

    void scoreScoresTextLogic(sf::Text &);
    void scoreNameTextLogic(sf::Text &);
    void updateInputTextLogic(sf::Text &);

    Data &getData(int);
private:
    void initializeFile();
private:
    Data data[10];
    bool m_isHighScoreShown = false;
};