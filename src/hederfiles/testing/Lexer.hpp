#pragma once

#include <string>
#include <vector>
#include <fstream>



class Lexer 
{
public:
    static std::vector<std::vector<std::vector<std::string>>>& getWhileVec();
    static std::vector<std::vector<std::vector<std::string>>>& getIfVec();
    std::vector<std::vector<std::string>> doLexer(std::string &);
    
private:
    std::vector<std::string> splitByWord(std::string const &, const char Delim);
    void pushLinesToVec(std::vector<std::vector<std::string>> const&);
    void printVec(std::vector<std::vector<std::string>> const&);
    void searchVec(std::vector<std::vector<std::string>> const&,std::string const);
    //void ifVec(std::vector<std::vector<std::string>> const&);
    int sizeOfFilesInDirectory(std::string const&);
private:
    static std::vector<std::vector<std::vector<std::string>>> m_vec_vec_vec_while;
    static std::vector<std::vector<std::vector<std::string>>> m_vec_vec_vec_if;
    std::ifstream m_program;
};