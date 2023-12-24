#pragma once

// app
#include "Users.hpp"

// deps
#include <fmt/core.h>
#include <string>
#include <optional>

namespace dao {

class UsersRedis : public Users {
public:
    std::vector<entity::User> getUsers() override {
        return {};
    }

    std::optional<entity::User> getUser(int id) override {
        return {};
    }
};

} // ns dao