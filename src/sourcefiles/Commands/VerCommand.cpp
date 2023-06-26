#include "VerCommand.hpp"
#include "SymbolVar.hpp"

#include <string>
#include <vector>

void VerCommand::DoCommand(std::vector<std::string> const&line)
{
    SymbolVar::getInstance()->createVar(line);
}