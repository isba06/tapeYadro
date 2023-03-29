#include "mergesort.h"
#include <vector>
#include <fstream>
void Mergesort::run() {
    if(m_tape){
        std::vector<int> storage;
        storage.reserve(104'857'600); //100 MB
        while(!m_tape->eof() && storage.size() <= storage.capacity()) {
            storage.push_back(m_tape->read());
        }
        std::sort(storage.begin(), storage.end());
        int file_number = 1;
        Tape tape_tmp("tmp_" + std::to_string(file_number) + m_tape->getFilename());
        for(auto && value : storage) {
            tape_tmp.write(value);
        }
    }
}
