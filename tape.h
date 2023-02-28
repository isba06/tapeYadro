//
// Created by Исмаил Байрамов on 26.02.2023.
//

#include <fstream>
struct ITape {
    virtual void forward() = 0;
    virtual void back() = 0;
    virtual void read() = 0;
    virtual void write() = 0;
    virtual ~ITape() = default;
};

struct Tape : public ITape {
    void forward() override {

    }

    Tape(std::string filename) : file(filename)
    {

    }

private:
    std::fstream file;
    std::size_t pos;
};