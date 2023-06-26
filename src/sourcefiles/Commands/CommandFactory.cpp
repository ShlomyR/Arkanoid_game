#include "InitObjectsCommand.hpp"
#include "CommandFactory.hpp"
#include "WhileCommand.hpp"
#include "SleepCommand.hpp"
#include "PrintCommand.hpp"
#include "BreakCommand.hpp"
#include "LevelCommand.hpp"
#include "VerCommand.hpp"
#include "IfCommand.hpp"

#include <string>
#include <vector>

CommandFactory::CommandFactory()
{
    m_command_creators["var"] = []() { return std::make_shared<VerCommand>(); };
    m_command_creators["if"] = []() { return std::make_shared<IfCommand>(); };
    m_command_creators["while"] = []() { return std::make_shared<WhileCommand>(); };
    m_command_creators["sleep"] = []() { return std::make_shared<SleepCommand>(); };
    m_command_creators["print"] = []() { return std::make_shared<PrintCommand>(); };
    m_command_creators["break"] = []() { return std::make_shared<BreakCommand>(); };
    m_command_creators["level"] = []() { return std::make_shared<LevelCommand>(); };
    m_command_creators["initObjects"] = []() { return std::make_shared<InitObjectsCommand>(); };
}

std::shared_ptr<Command> CommandFactory::createCommand(const std::vector<std::string>& tokens) const
{
    if (tokens.empty()) {
        return nullptr;
    }

    auto creator_func = m_command_creators.find(tokens[0]);
    if (tokens.size() > 1 && creator_func == m_command_creators.end()) {
        creator_func = m_command_creators.find(tokens[1]);
    }
    
    if (creator_func == m_command_creators.end()) {
        return nullptr;
    }

    return creator_func->second();
}