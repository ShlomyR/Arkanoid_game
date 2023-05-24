#include <sstream>
#include <iostream>
#include <boost/filesystem.hpp>

// #include "Lexer.hpp"

#include "../hederfiles/Lexer.hpp"

#define PATH "src/levels"

std::vector<std::vector<std::vector<std::string>>> Lexer::m_vec_vec_vec_while;
std::vector<std::vector<std::vector<std::string>>> Lexer::m_vec_vec_vec_if;

std::vector<std::vector<std::vector<std::string>>> &Lexer::getWhileVec()
{
    return m_vec_vec_vec_while;
}

std::vector<std::vector<std::vector<std::string>>> &Lexer::getIfVec()
{
    return m_vec_vec_vec_if;
}

std::vector<std::vector<std::string>> Lexer::doLexer(std::string &src)
{
    std::vector<std::vector<std::string>> main_vector_arr;
    for(int i = 1; i < sizeOfFilesInDirectory(PATH) + 1; i++) {
        src = "src/levels/level-" + std::to_string(i) + ".dat";
        m_program.open(src);
        if (!m_program.is_open()) {
            throw std::runtime_error("file not opened");
        }

        std::string line;
        while (getline(m_program, line)) {
            std::vector<std::string> vec_words = splitByWord(line, ' ');
            main_vector_arr.push_back(vec_words);
        }
        m_program.close();
    }
    pushLinesToVec(main_vector_arr);
    printVec(main_vector_arr);

    return main_vector_arr;
}

std::vector<std::string> Lexer::splitByWord(std::string const &str, const char Delim)
{
    std::string token;
    std::stringstream stream(str);
    std::vector<std::string> vec_str;

    while (getline(stream, token, Delim)) {
        vec_str.push_back(token);
    }
    return vec_str;
}

void Lexer::pushLinesToVec(std::vector<std::vector<std::string>> const& arr)
{
    searchVec(arr,"while");
    searchVec(arr,"if");
}

void Lexer::searchVec(std::vector<std::vector<std::string>> const& arr,std::string const search)
{
    std::string str = "";
    std::vector<std::vector<std::string>> vec_vec_str = {};
    std::vector<std::string> vec_words = {};

    for (std::string::size_type i = 0; i < arr.size(); i++) {
        for (std::string::size_type j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == search) {
                i++;
                i++;
                while (arr[i][0] != "}")
                {
                    std::string::size_type temp = 0;
                    int temp_j = 0;
                    while (temp != arr[i].size()) {
                        if (arr[i][temp_j].size() > 0) {
                            str += arr[i][temp_j] + " ";
                        }
                        temp_j++;
                        temp++;
                    }
                    vec_words = splitByWord(str, ' ');
                    vec_vec_str.push_back(vec_words);
                    vec_words.clear();
                    str = "";
                    i++;
                }
                if (search == "while") {
                    m_vec_vec_vec_while.push_back(vec_vec_str);
                } else if (search == "if") {
                    m_vec_vec_vec_if.push_back(vec_vec_str);
                } else {
                    throw std::runtime_error("The search term do not exist!");
                }
                vec_vec_str.clear();
                str = "";

            }
        }
    }
}


void Lexer::printVec(std::vector<std::vector<std::string>> const &vec_arr)
{
    for (std::string::size_type i = 0; i < vec_arr.size(); i++) {
        std::cout << "[";
        for (std::string::size_type j = 0; j < vec_arr[i].size(); j++) {
            std::cout << vec_arr[i][j] << " ";
        }
        std::cout << "]" << "\n";
    }
}

int Lexer::sizeOfFilesInDirectory(std::string const& dir_path) {
    boost::filesystem::path dir(dir_path);
    int file_count = 0;
    boost::filesystem::directory_iterator end_iter;
    for (boost::filesystem::directory_iterator iter(dir); iter != end_iter; ++iter) {
        if (boost::filesystem::is_regular_file(iter->status())) {
            ++file_count;
        }
    }
    return file_count;
}