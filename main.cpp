#include <iostream>
#include <string>
#include <fstream>
#include "tape.h"
#include "config.h"


int main() {
    std::ifstream configfile("../config.txt");
    if (configfile.is_open()) {
        Config config(configfile);
 //       std::cout << std::get<std::int64_t>(config["position"]) << std::endl;
//        std::cout << std::get<std::size_t>(config["delay"]) << std::endl;
    }
    std::fstream file("../tape1.txt");
    Tape tape("../tape1.txt");

    std::cout << tape.pos_input() << std::endl;
    tape.forward();
    std::cout << tape.pos_input() << std::endl;
    tape.forward();
    tape.back();
    std::cout << tape.pos_input() << std::endl;
    int b = 667;
    tape.write(b);
    std::cout << tape.pos_input() << std::endl;
    return 0;
}
