#pragma once

#include "entity/User.hpp"

#include <doctest/doctest.h>
#include <vector>
#include <string>


namespace utils {

void checkUser(const entity::User& user,
               int expectedId, std::string expectedName, int expectedAge) {

    CHECK(user.id   == expectedId);
    CHECK(user.name == expectedName);
    CHECK(user.age  == expectedAge);
}
} // ns utils
