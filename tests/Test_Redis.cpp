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

    SUBCASE("getUserById") {
        std::optional<entity::User> user = access.getUser(1);
        CHECK(user.has_value());

        // fmt::print("user name{}", user->name);

        CHECK(user == entity::User{1, "stefan", 20});
    }
}
