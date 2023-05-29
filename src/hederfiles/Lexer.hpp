#pragma once

#include "BlockParser.hpp"
#include "FileReader.hpp"

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>
#include <fstream>

class Lexer
{
public:
    Lexer(std::string &);
    std::vector<std::vector<std::string>> tokenize_file();
    static std::vector<std::vector<std::vector<std::string>>>& get_while_blocks();
    static std::vector<std::vector<std::vector<std::string>>>& get_lines_blocks();
    static std::vector<std::vector<std::vector<std::string>>>& get_if_blocks();
private:
    std::vector<std::vector<std::string>> read_file_contents();
    void process_blocks();
    void register_block_parser(const std::string &, std::shared_ptr<BlockParser> );
    void print_vector(const std::vector<std::vector<std::string>> &, const std::string &);
private:
    FileReader m_fileReader;
    std::ifstream m_program;
    std::string m_src;
    std::unordered_map<std::string, std::shared_ptr<BlockParser>> m_blockParsers;
    static std::vector<std::vector<std::vector<std::string>>> m_while_blocks;
    static std::vector<std::vector<std::vector<std::string>>> m_if_blocks;
    static std::vector<std::vector<std::vector<std::string>>> m_lines_blocks;
};