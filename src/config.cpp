#include <config.h>

std::pair<std::string , std::string> Config::split(const std::string & line) {
    auto pos = line.find('=');
    if(pos == std::string::npos){
        std::cerr << "Incorrect format in config file: " + line << '\n';
        return std::make_pair("", "");
    }
    return std::make_pair(line.substr(0, pos), line.substr(pos+1));
}

std::ostream& operator<<(std::ostream& os, const Config& config) {
    for(auto [key, value] : config.m_param){
        os << key << ' ' << value << '\n';
    }
    return os;
}