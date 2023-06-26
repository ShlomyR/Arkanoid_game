#pragma once

#include "Command.hxx"

#include <unordered_map>
#include <functional>
#include <memory>
#include <string>

class CommandFactory {
public:
    CommandFactory();
    std::shared_ptr<Command> createCommand(const std::vector<std::string> &) const;
private:
    std::unordered_map<std::string, std::function<std::shared_ptr<Command>()>> m_command_creators;
};

