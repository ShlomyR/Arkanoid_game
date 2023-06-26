#include "WhileBlockParser.hpp"

#include <string>
#include <vector>

void WhileBlockParser::parse(std::vector<std::vector<std::string>> &lines)
{
    reserve_block_type(lines, "while");
}
