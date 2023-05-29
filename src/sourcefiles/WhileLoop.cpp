#include "ConditionChecker.hpp"
#include "LinesPointer.hpp"
#include "MapException.hpp"
#include "SymbolVar.hpp"
#include "WhileLoop.hpp"
#include "Lexer.hpp"
#include "Parse.hpp"

#include <iostream>
#include <string>
#include <vector>

void WhileLoop::whileLoop(std::vector<std::string> const&line)
{
    size_t tmp_lines_ptr = LinesPointer::getIndex() + 2;
    bool condition = true;
    bool breakLoop = false;
    Parse parser;
    ConditionChecker conditionCheck;
    auto while_block = Lexer::get_while_blocks()[0];
    auto &varStringMap = SymbolVar::getInstance()->getMapStr();
    
    while ((condition = conditionCheck.check(line))) {
        if (breakLoop) {
            break;
        }
        parser.parse(while_block);
        std::string val = "";
        try {
            if (varStringMap.count("breakLoop")) {
                breakLoop = varStringMap.at("breakLoop") == "true";
            } else {
                throw MapException("Error: " + std::string("breakLoop") + " not found in map_strDB.", std::string(__FILE__) + ":" + std::to_string(__LINE__));
            }
        } catch (const MapException& me) {
            std::cout << me.what() << " at line " << me.where() << "\n";
        }
    }

    tmp_lines_ptr += while_block.size();
    std::cout << "\nWhileLoop Parser finished\n";

    Lexer::get_while_blocks().erase(Lexer::get_while_blocks().begin());
    LinesPointer::setIndex(tmp_lines_ptr);

    condition = false;
}
