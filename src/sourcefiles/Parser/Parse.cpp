#include "Parse.hpp"

#include <string>
#include <vector>
#include <memory>

void Parse::parse(std::vector<std::vector<std::string>> &lines)
{
    m_lines_pointer.resetIndex();
    for (m_lines_pointer.getIndex(); m_lines_pointer.getIndex() < lines.size(); m_lines_pointer.incrementIndex()) {
        std::shared_ptr<Command> c = m_command_factory.createCommand(lines[m_lines_pointer.getIndex()]);
        if (c != nullptr) {
            c->DoCommand(lines[m_lines_pointer.getIndex()]);
        }
    }
}
