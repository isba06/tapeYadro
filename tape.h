//
// Created by Исмаил Байрамов on 26.02.2023.
//

#include <fstream>
#include <limits>

struct ITape {
    virtual void forward() = 0;
    virtual void back() = 0;
    virtual int read() = 0;
    virtual void write(const int & value) = 0;
    virtual std::streampos pos_input() = 0;
    virtual  std::streampos pos_output() = 0;
    virtual ~ITape() = default;
};

struct Tape : public ITape {
    void forward() override {

        while(!m_file.eof() && std::isdigit(m_file.peek())) {
            m_file.seekg(1, std::ios::cur);
        }
        while(!m_file.eof() && std::isspace(m_file.peek())) {
            m_file.seekg(1, std::ios::cur);
        }
        m_file.seekp(m_file.tellg());
    }

    void back() override {
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
            m_file.seekp(m_file.tellg());
        }
    }

    std::streampos pos_input() override {
        return m_file.tellg();
    }

    std::streampos pos_output() override {
        return m_file.tellg();
    }

    void write(const int & value) override {
        m_file << value;
    }

    int read() override {
        if(!m_file.eof()) {
            int value;
            m_file >> value;
            return value;
        }
    }

    Tape(std::string && filename) : m_file(filename)
    {
    }

    bool is_open() {
        return m_file.is_open();
    }

    bool eof() {
        return m_file.eof();
    }

    ~Tape(){
        m_file.close();
    }
private:
    std::streamoff m_pos = 0;
    std::fstream m_file;
};