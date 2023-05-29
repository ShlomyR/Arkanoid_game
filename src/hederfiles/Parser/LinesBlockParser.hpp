#pragma once

#include <string>
#include <vector>

#include "BlockParser.hpp"

class LinesBlockParser : public BlockParser
{
public:
    void parse(std::vector<std::vector<std::string>> &) override;
};