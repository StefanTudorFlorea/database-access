#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "dao/Users.hpp"
#include "dao/redis/Users.hpp"
#include "entity/User.hpp"

#include <fmt/core.h>
#include <vector>
#include <string>
#include <optional>


TEST_CASE("Redis") {
    dao::redis::Users access;

    SUBCASE("addUser") {
        access.addUser("user-1", 10);
        access.addUser("user-2", 20);
        access.addUser("user-3", 30);
    }
}