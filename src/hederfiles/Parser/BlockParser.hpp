#pragma once

#include <string>
#include <vector>

#include "Parser.hxx"

class BlockParser : public Parser
{
public:
    ~BlockParser() = default;
    void reserve_block_type(std::vector<std::vector<std::string>> &, const std::string);
};