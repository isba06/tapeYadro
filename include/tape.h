#pragma once
#include <fstream>

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
    void forward() override;
    void back() override;
    std::streampos pos_input() override;
    std::streampos pos_output() override;
    void write(const int & value) override;
    int read() override;
    std::size_t size();
    bool is_open();
    bool eof();
    std::streampos filesize();
    explicit Tape(std::string && filename)
    {
        m_file.open(filename, std::ios::in);
        if(!m_file.is_open()) {
            m_file.open(filename, std::ios::out);
        }
    }
    Tape(Tape && tape) : m_file(std::move(tape.m_file)) {}
    ~Tape() override { m_file.close(); }
private:
    std::fstream m_file;
};