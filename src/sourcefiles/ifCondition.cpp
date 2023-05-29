#include "ConditionChecker.hpp"
#include "LinesPointer.hpp"
#include "ifCondition.hpp"
#include "Lexer.hpp"
#include "Parse.hpp"

void ifCondition::ifCon(std::vector<std::string> const&line)
{
    size_t tmp_lines_ptr = LinesPointer::getIndex()+2;
    bool condition = true;
    Parse parser;
    ConditionChecker conditionCheck;

    auto if_block = Lexer::get_if_blocks()[0];
    
    if ((condition = conditionCheck.check(line))) {
        parser.parse(if_block);
    }

    tmp_lines_ptr += if_block.size();
    std::cout << "\nifCon Parser finished\n";

    Lexer::get_if_blocks().erase(Lexer::get_if_blocks().begin());
    LinesPointer::setIndex(tmp_lines_ptr);

    condition = false;
}
