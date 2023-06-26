#include "ifCondition.hpp"
#include "IfCommand.hpp"
#include "Parse.hpp"

#include <string>
#include <vector>

void IfCommand::DoCommand(std::vector<std::string> const&line)
{
    ifCondition::ifCon(line);
}