#pragma once
#include "tape.h"

struct Mergesort {
    void run();

    Mergesort(Tape & tape) : m_tape(&tape) {}
    ~Mergesort() {m_tape = nullptr;}
private:

Tape * m_tape = nullptr;
};
