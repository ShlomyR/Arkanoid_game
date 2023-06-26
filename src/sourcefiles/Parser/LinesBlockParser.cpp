#include "LinesBlockParser.hpp"
#include "Lexer.hpp"

#include <string>
#include <vector>

void LinesBlockParser::parse(std::vector<std::vector<std::string>> &lines)
{
    Lexer::get_lines_blocks().push_back(lines);
}
