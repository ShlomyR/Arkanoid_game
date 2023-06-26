#pragma once

#include <string>
#include <fstream>

class FileReader
{
public:
    template <typename T>
    T read_file(const std::string &);
private:
    std::ifstream m_program;
};
