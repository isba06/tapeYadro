#include "tape.h"
#include <iostream>
void Tape::move_forward() {
    auto pos = m_file.tellg();
    std::string line;
    std::getline(m_file, line);
    pos = m_file.tellg();
    if(pos != -1) {
        m_file.seekg(pos, std::ios::beg);
    }
}

void Tape::move_backward() {
    if (m_file.tellg() == 0) {
        return;
    }
    m_file.seekg(-1, std::ios::cur);
    do {
        m_file.seekg(-1, std::ios::cur);
    } while (!std::isspace(m_file.peek()) && m_file.tellg() > 0);
    if (m_file.tellg() != 0) {
        m_file.seekg(1, std::ios::cur);
    }
}

std::streampos Tape::pos_input() {
    return m_file.tellg();
}

std::streampos Tape::pos_output() {
    return m_file.tellp();
}

void Tape::write(const int & value) {

    m_file << value << '\n';
}

int Tape::read() {
    if(!m_file.eof()) {
        int value;
        m_file >> value;
        return value;
    }
    return 0;
}

bool Tape::is_open() {
    return m_file.is_open();
}

bool Tape::eof() {
    return m_file.eof();
}
std::string Tape::getFilename() {
    return m_filename;
}
