#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "dao/Users.hpp"
#include "dao/UsersPostgres.hpp"
#include "dao/UsersRedis.hpp"
#include "entity/User.hpp"

#include <fmt/core.h>
#include <vector>
#include <string>
#include <optional>


TEST_CASE("Redis") {
    dao::UsersRedis access;

    SUBCASE("getUserById") {
        std::optional<entity::User> user = access.getUser(1);
        CHECK(user.has_value());

        // fmt::print("user name{}", user->name);

        CHECK(user == entity::User{1, "stefan", 20});
    }
}
