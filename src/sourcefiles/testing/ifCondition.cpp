// #include "ifCondition.hpp"
// #include "CheckCondition.hpp"
// #include "Parser.hpp"
// #include "Lexer.hpp"

#include "../hederfiles/testing/ifCondition.hpp"
#include "../hederfiles/testing/CheckCondition.hpp"
#include "../hederfiles/testing/Parser.hpp"
#include "../hederfiles/testing/Lexer.hpp"



int ifCondition::ifCon(std::vector<std::string> const&line)
{ 
    bool condition = true;
    Parser parser;
    std::vector<std::vector<std::string>> vec_vec_str = Lexer::getIfVec()[0];
    
    if ((condition = CheckCondition(line))) {
        parser.parse(vec_vec_str);
    }
    //printf("\nifCon Parser finished\n");

    if (condition) {
        while (!vec_vec_str.empty()) { // or vec_vec_str = {}
            vec_vec_str.pop_back();
        } if (line[0] != "if") {
            Lexer::getIfVec().erase(Lexer::getWhileVec().begin());
        } 
        condition = false;
    }

    return 0;
}