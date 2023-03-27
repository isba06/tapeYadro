#include "tape.h"
#include <iostream>
void Tape::forward() {

    while(!m_file.eof() && std::isdigit(m_file.peek())) { // убрать eof
        m_file.seekg(1, std::ios::cur);
    }
    while(!m_file.eof() && std::isspace(m_file.peek())) {
        m_file.seekg(1, std::ios::cur);
    }
   // m_file.seekp(m_file.tellg());
}

void Tape::back() {
    //tellg==tellp
    if(m_file.tellg() > 0) {
        m_file.seekg(-1, std::ios::cur);
        while(std::isspace(m_file.peek()) && m_file.tellg() > 0){
            m_file.seekg(-1, std::ios::cur);
        }
        while(std::isdigit(m_file.peek()) && m_file.tellg() > 0){
            m_file.seekg(-1, std::ios::cur);
        }
        m_file.seekg(1, std::ios::cur);
       // m_file.seekp(m_file.tellg());
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

std::size_t Tape::size() {
    std::size_t s = 0;
    if(is_open()) {
        auto tmp = m_file.tellg();
        m_file.seekg(0);
        while (!eof()) {
            ++s;
            forward();
        }
        m_file.seekg(tmp);
    }
    return s;
}

std::streampos Tape::filesize() {
    auto tmp = m_file.tellg();
    m_file.seekg(0, std::ios::end);
    auto end_pos = m_file.tellg();
    m_file.seekg(tmp);
    return end_pos;
}