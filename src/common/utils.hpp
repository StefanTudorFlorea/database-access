#pragma once
#include <string>


namespace utils {

std::string getEnvVarOr(const std::string& envVar, const std::string& defaultValue);
    
} // ns utils
