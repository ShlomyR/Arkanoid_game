#include "HighScoreManager.hpp"
#include "Hud.hpp"


#include <fstream>

HighScoreManager::HighScoreManager()
{
    initializeFile();
}

size_t HighScoreManager::getFirstHighScore()
{
    return data[0].score;
}

void HighScoreManager::setIsHighScoreShown(bool value)
{
    m_isHighScoreShown = value;
}

bool HighScoreManager::getIsHighScoreShown()
{
    return m_isHighScoreShown;
}

void HighScoreManager::drew(sf::RenderWindow &)
{
    
}

void HighScoreManager::initializeFile()
{
    // Check if the file exists
    std::ifstream file_in("src/scores/top10.dat");
    if (!file_in.good()) {
        // Open file for writing
        std::ofstream file_out("src/scores/top10.dat");

        // Initialize the data with the initial values
        for (int i = 0; i < 10; i++) {
            data[i].name = "00000";
            data[i].score = 0;
            file_out << data[i].name << " " << data[i].score << "\n";
        }
        file_out.close();
    } else {
        file_in.close();
    }

    std::ifstream file_in2("src/scores/top10.dat");
    for(int i=0;i<10;i++){
        file_in2 >> data[i].name >> data[i].score;
    }
    file_in2.close();
}

void HighScoreManager::scoreNameTextLogic(sf::Text &text)
{
    std::string scoresString = "";
    std::string space_dot = "";

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            space_dot = "   ";
        } else if (i == 9) {
            space_dot = " ";
        } else {
            space_dot = "  ";
        }
        scoresString += std::to_string(i+1) + "." + space_dot + data[i].name +  "\n";       
    }

    text.setString(scoresString);
}

void HighScoreManager::updateInputTextLogic(sf::Text &text)
{
    std::string scoresString = "Please enter your name: ";
    text.setString(scoresString);
}

Data &HighScoreManager::getData(int i)
{
    return data[i];
}

void HighScoreManager::scoreScoresTextLogic(sf::Text &text)
{
    std::string scoresString = "";
    std::string space_score = "";

    for (int i = 0; i < 10; i++) {
        scoresString += space_score + std::to_string(data[i].score) +  "\n";       
    }

    text.setString(scoresString);
}
