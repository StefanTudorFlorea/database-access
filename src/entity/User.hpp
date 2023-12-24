#pragma once

#include <string>
#include <utility>


namespace entity {

struct User {
    int id;
    std::string name;
    int age;

    bool operator==(const User& other) const {
        return std::tie(id, name, age) == std::tie(other.id, other.name, other.age);
    }
};

} // ns entity