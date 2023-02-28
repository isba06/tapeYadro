#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <variant>

struct Config {
    Config(std::ifstream & file) {
        std::string line;
        while (std::getline(file, line)) {
            auto [name, value] = split(line);
            //fields[name] = std::stoll(value);
            std::istringstream val(value);
            std::size_t v;
            val >> v;
            m_fields[name] = v;
        }
    }

    auto operator[](std::string && str){
        return m_fields[str];
    }

    auto size() {
        return m_fields.size();
    }

private:
    std::pair<std::string, std::string> split(const std::string & line) {
        std::stringstream line_stream(line);
        std::string name, value;
        line_stream >> name;
        line_stream >> value;
        return std::make_pair(name, value);
    }

    std::map<const std::string, std::size_t> m_fields{
            {"position", 0},
            {"shift", 0},
            {"delay", 0}
    };
};

int main() {
    std::ifstream configfile("../config.txt");
    if (configfile.is_open()) {
        Config config(configfile);
        std::cout << config.size();
    }
    return 0;
}
