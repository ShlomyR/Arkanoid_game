#include "ContainerHandler.hpp"

#include <sstream>

std::vector<std::tuple<int, std::string, std::string>> ContainerHandler::createLevel(const std::string& str, const std::string& containerType, std::vector<int>& numOfBricks, std::vector<std::string>& colorOfBricks, std::vector<std::string>& directionOfBricks)
{
    try {
        if (containerType == "vector,tuple") {
            std::cout << "vector,tuple: " << "\n";
            std::vector<std::tuple<int, std::string, std::string>> myVectorTuple;
            std::tuple<int, std::string, std::string> myTuple;
            size_t strLength = convertStringToVectors(str, numOfBricks, colorOfBricks, directionOfBricks);
            for (size_t i = 0; i < strLength; i++) {
                if (colorOfBricks[i] == "skip") {
                    std::get<0>(myTuple) = 1;
                    std::get<1>(myTuple) = colorOfBricks[i];
                    std::get<2>(myTuple) = "null";
                    colorOfBricks.erase(colorOfBricks.begin() + i);
                    myVectorTuple.push_back(myTuple);
                } if (directionOfBricks[i] == "[["){
                    std::get<0>(myTuple) = 1;
                    std::get<1>(myTuple) = "null";
                    std::get<2>(myTuple) = directionOfBricks[i];
                    directionOfBricks.erase(directionOfBricks.begin() + i);
                    myVectorTuple.push_back(myTuple);
                } 
                std::get<0>(myTuple) = numOfBricks[i];
                std::get<1>(myTuple) = colorOfBricks[i];
                std::get<2>(myTuple) = directionOfBricks[i];
                myVectorTuple.push_back(myTuple);  
                
            }
            printVectorOfTuples(myVectorTuple);
            std::cout << "\n";
            return myVectorTuple;
        } else {
            std::cout << "Invalid container type specified." << std::endl;
        }
    } catch (const std::invalid_argument& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::vector<std::tuple<int, std::string, std::string>> empty = {};
    return empty;
}

size_t ContainerHandler::convertStringToVectors(const std::string& str, std::vector<int>& numOfBricks,
        std::vector<std::string>& colorOfBricks,
        std::vector<std::string>& directionOfBricks
) 
{
    std::istringstream iss(str);
    std::string token;

    while (std::getline(iss, token, ',')) {
        if (!token.empty()) {
            if (isdigit(token[0])) {
                numOfBricks.push_back(std::stoi(token));
            } else if (isalpha(token[0])) {
                colorOfBricks.push_back(token);
            } else {
                directionOfBricks.push_back(token);
            }
        }
    }
    
    return std::min(numOfBricks.size(), std::min(colorOfBricks.size(), directionOfBricks.size()));
}