#pragma once

#include <string>
#include <fmt/core.h>


namespace dao {
namespace redis {
namespace keys {

std::string user(int id) { 
    return fmt::format("user:#{}", id); 
}

std::string configNextUserId() { 
    return fmt::format("config:nextUserId"); 
}

} // ns keys
} // ns redis
} // ns dao