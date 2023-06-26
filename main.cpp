#include "Parse.hpp"
#include "Lexer.hpp"


#define PATH "src/levels/level-1.dat"

int main(int argc, char *argv[]) 
{
    std::string file_name;

    if(argc > 1) {
        file_name = argv[1];
    } else {
        file_name = PATH;
    }

    Lexer lexer(file_name);
    auto Lines_blocks = lexer.tokenize_file();

    Parse parse;
    parse.parse(Lines_blocks);

    return 0;
}
