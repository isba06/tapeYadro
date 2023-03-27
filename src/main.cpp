#include "config.h"
#include "tape.h"
#include <fstream>
#include <iostream>
#include <string>
#include "mergesort.h"

int main() {
    std::ifstream configfile("../config.txt");
    if (configfile.is_open()) {
        Config config(configfile);
 //       std::cout << std::get<std::int64_t>(config["position"]) << std::endl;
//        std::cout << std::get<std::size_t>(config["delay"]) << std::endl;
    }
    //std::ofstream file("../tape2.tape", std::ios::out | std::ios::binary);
    //file.write(reinterpret_cast<const char *>(&x), sizeof(int));
    Tape tape("../tape3.txt");
    std::cout << tape.filesize() << std::endl;
    return 0;
}
