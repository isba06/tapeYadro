#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <variant>
#include <iostream>

struct Config {
    explicit Config(std::ifstream & file) {
        if (!file.is_open()) {
            throw std::runtime_error("Could not open config file");
        }
        std::string line;
        while (std::getline(file, line)) {
            auto [name, value] = split(line);
            m_param[name] = value;
        }
    }

    auto operator[](std::string && str){
        return m_param[str];
    }

    auto size() {
        return m_param.size();
    }

    friend std::ostream& operator<<(std::ostream& os, const Config& config);
private:
    std::map<const std::string, std::string> m_param;

    std::pair<std::string , std::string> split(const std::string & line);
};
