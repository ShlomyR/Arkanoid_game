#pragma once

#include <vector>
#include <memory>

#include "CommandFactory.hpp"
#include "LinesPointer.hpp"
#include "Command.hxx"
#include "Parser.hxx"

class Parse : public Parser
{
public:
    Parse() = default;
    void parse(std::vector<std::vector<std::string>> &) override;
private:
    Parse(const Parse&) = delete;
    Parse& operator=(const Parse&) = delete;
private:
    CommandFactory m_command_factory;
    LinesPointer m_lines_pointer;
};
