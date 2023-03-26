#pragma once
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
            std::istringstream val(value);
            if(m_fields.contains(name)){
                if(std::holds_alternative<std::size_t>(m_fields[name])){
                    std::size_t tmp;
                    val >> tmp;
                    m_fields[name] = tmp;
                }
                else if(std::holds_alternative<std::int64_t>(m_fields[name])) {
                    std::int64_t tmp;
                    val >> tmp;
                    m_fields[name] = tmp;
                }
            }
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

    std::map<const std::string, std::variant<std::size_t, std::int64_t>> m_fields{
            {"position", std::int64_t(0) },
            {"shift", std::int64_t(0) },
            {"delay", std::size_t(0) }
    };
};
