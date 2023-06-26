#include "WhileBlockParser.hpp"
#include "LinesBlockParser.hpp"
#include "IfBlockParser.hpp"
#include "BlockParser.hpp"
#include "FileReader.hpp"
#include "Lexer.hpp"

#include <iostream>

std::vector<std::vector<std::vector<std::string>>> Lexer::m_while_blocks;
std::vector<std::vector<std::vector<std::string>>> Lexer::m_lines_blocks;
std::vector<std::vector<std::vector<std::string>>> Lexer::m_if_blocks;

std::vector<std::vector<std::vector<std::string>>> &Lexer::get_while_blocks()
{
    return m_while_blocks;
}

std::vector<std::vector<std::vector<std::string>>> &Lexer::get_lines_blocks()
{
    return m_lines_blocks;
}

std::vector<std::vector<std::vector<std::string>>> &Lexer::get_if_blocks()
{
    return m_if_blocks;
}

Lexer::Lexer(std::string &src)
: m_fileReader()
, m_src(src)
{}

std::vector<std::vector<std::string>> Lexer::read_file_contents()
{
    return m_fileReader.read_file<std::vector<std::vector<std::string>>>(m_src);
}

void Lexer::process_blocks()
{
    std::vector<std::vector<std::string>> lines;
    for (const auto &[blockType, parser] : m_blockParsers) {
        lines = read_file_contents();
        parser->parse(lines);
        if (!lines.empty()) {
            print_vector(lines, blockType);
        }
    }
}

std::vector<std::vector<std::string>> Lexer::tokenize_file()
{
    register_block_parser("while", std::make_unique<WhileBlockParser>());
    register_block_parser("if", std::make_unique<IfBlockParser>());
    register_block_parser("all_lines", std::make_unique<LinesBlockParser>());
    process_blocks();
    return m_lines_blocks[0];
}

void Lexer::register_block_parser(const std::string &block_type, std::shared_ptr<BlockParser> parser)
{
    m_blockParsers[block_type] = std::move(parser);
}

void Lexer::print_vector(const std::vector<std::vector<std::string>>& vec, const std::string &blockType)
{
    std::cout << "\n" << "Print type: " << blockType << "\n\n";
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < vec[i].size(); j++) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << "]" << "\n";
    }
}
