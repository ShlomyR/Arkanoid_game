#include "FileReader.hpp"

#include <boost/filesystem.hpp>
#include <vector>
#include <sstream>

#define PATH "src/levels"

template <>
std::string FileReader::read_file<std::string>(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Failed to open file: " + filename);
    }
    std::stringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

int sizeOfFilesInDirectory(std::string const& dir_path) {
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

template <>
std::vector<std::vector<std::string>> FileReader::read_file<std::vector<std::vector<std::string>>>(const std::string &filename)
{
    std::vector<std::vector<std::string>> lines;
    for(int i = 1; i < sizeOfFilesInDirectory(PATH) + 1; i++) {
        std::string src = filename;
        src.replace(17, 1, std::to_string(i));
        m_program.open(src);
        
        if (!m_program.is_open()) {
            throw std::runtime_error("file not opened in vvsFileReader, file: " + src + "\n");
        }

        std::string line;
        while (std::getline(m_program, line)) {
            std::vector<std::string> tokens;
            std::istringstream iss(line);
            for (std::string token; iss >> token;) {
                if (line.size() > 0) {
                    tokens.push_back(token);
                }
            }
            if (tokens.size() > 0) {
                lines.push_back(tokens);
            }
        }
        m_program.close();
    }

    return lines;
}
