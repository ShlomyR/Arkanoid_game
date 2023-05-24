#include "../hederfiles/InitObjects.hpp"

int main()
{
    InitObjects initGame(sf::Vector2u (std::min(800u, sf::VideoMode::getDesktopMode().width), std::min(600u, sf::VideoMode::getDesktopMode().height)),"Arkanoid-game",3,0,2);
    initGame.init();
    initGame.run();

    return 0;
}

// #include "../hederfiles/Parser.hpp"
// #include "../hederfiles/Lexer.hpp"



// #define PATH "src/levels/level- .dat"

// int main(int argc, char *argv[]) 
// {
//     std::string file_name;
    
//     if(argc > 1) {
//         file_name = argv[1];
//     } else {
//         file_name = PATH;
//     }
    
//     Lexer lexer;

//     std::vector<std::vector<std::string>> arr = lexer.doLexer(file_name);

//     Parser parser;
//     parser.parse(arr);

//     return 0;

// }