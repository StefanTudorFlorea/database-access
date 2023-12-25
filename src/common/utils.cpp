#include "utils.hpp"
#include <cstdlib>


namespace utils {

std::string getEnvVarOr(const std::string& envVar,
                        const std::string& defaultValue) {
                            
    const char* env = std::getenv(envVar.c_str());
    if (!env) {
        return defaultValue;
    }

    return env;
}

} // ns utils

