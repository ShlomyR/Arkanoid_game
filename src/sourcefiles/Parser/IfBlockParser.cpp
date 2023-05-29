#include "IfBlockParser.hpp"

#include <string>
#include <vector>

void IfBlockParser::parse(std::vector<std::vector<std::string>> &lines)
{
    reserve_block_type(lines, "if");
}
