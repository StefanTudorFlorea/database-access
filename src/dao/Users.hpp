#pragma once

// app
#include "entity/User.hpp"

// cpp
#include <string>
#include <vector>
#include <optional>

namespace dao {

class Users {
public:
    virtual std::vector<entity::User> getUsers() = 0;

    virtual std::optional<entity::User> getUser(int id) = 0;

    // virtual int addUser(const std::string& name, int age) = 0;

    // virtual void removeUser(int id) = 0;

    // virtual void removeUsers() = 0;

    // virtual void updateUser(int id, const std::string& name, int age) = 0;
};

} // ns dao