#include "BlockParser.hpp"
#include "Lexer.hpp"

#include <string>
#include <vector>

void BlockParser::reserve_block_type(std::vector<std::vector<std::string>> &lines, const std::string blockType)
{
    size_t i = 0;
    std::vector<std::vector<std::string>> vvc = {};
    while (!lines[i].empty() && i < lines.size()) {
        if (lines[i][0] != blockType) {
            lines.erase(lines.begin() + i);
        } else {
            lines.erase(lines.begin() + i);
            lines.erase(lines.begin() + i);
            while (lines[i][0] != "}")  {
                vvc.push_back(lines[i]);
                ++i;
            }
            if (blockType == "while") {
                Lexer::get_while_blocks().push_back(vvc);
            } else if (blockType == "if") {
                Lexer::get_if_blocks().push_back(vvc);
            }
            lines.erase(lines.begin() + i);
            vvc.clear();
        }
    }
}
