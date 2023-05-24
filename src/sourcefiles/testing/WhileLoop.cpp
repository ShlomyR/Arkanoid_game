// #include "WhileLoop.hpp"
#include "../hederfiles/testing/WhileLoop.hpp"

int WhileLoop::whileLoop(std::vector<std::string> const&line)
{ 
    bool condition = true;
    Parser parser;
    std::vector<std::vector<std::string>> vec_vec_str = Lexer::getWhileVec()[0];
    
    while ((condition = CheckCondition(line))) {
        parser.parse(vec_vec_str);
    }
    printf("\nWhileLoop Parser finished\n");

    while (!vec_vec_str.empty()) { // or vec_vec_str = {}
        vec_vec_str.pop_back();
    }
    Lexer::getWhileVec().erase(Lexer::getWhileVec().begin());
    condition = false;

    return 0;
}