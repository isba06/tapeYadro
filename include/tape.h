#pragma once
#include <fstream>

struct ITape {
    virtual void move_forward() = 0;
    virtual void move_backward() = 0;
    virtual int read() = 0;
    virtual void write(const int & value) = 0;
    virtual std::streampos pos_input() = 0;
    virtual  std::streampos pos_output() = 0;
    virtual ~ITape() = default;
};

struct Tape : public ITape {
    void move_forward() override;
    void move_backward() override;
    std::streampos pos_input() override;
    std::streampos pos_output() override;
    void write(const int & value) override;
    int read() override;
    std::string getFilename();
    bool is_open();
    bool eof();
    explicit Tape(std::string && filename) : m_filename(filename)
    {
        m_file.open(m_filename, std::ios::in);
        if(!m_file.is_open()) {
            m_file.open(m_filename, std::ios::out);
        }
    }
    Tape(Tape && tape) : m_file(std::move(tape.m_file)) {}
    ~Tape() override { m_file.close(); }
private:
    std::string m_filename;
    std::fstream m_file;
};