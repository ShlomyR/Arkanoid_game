#pragma once

#include <string>
#include <vector>
#include <unordered_map>

class Command;

class Parser
{
public:
    explicit Parser();
    ~Parser();
    void parse(std::vector<std::vector<std::string>> const&);
public:
    static std::string::size_type getIndex();
private:
    static void incrementIndex();
    void resetIndex();
private:
    std::unordered_map<std::string,Command*> m_command_map;
    static std::string::size_type m_index;
};