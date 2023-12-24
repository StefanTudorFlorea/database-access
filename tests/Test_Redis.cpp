#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "dao/Users.hpp"
#include "dao/UsersPostgres.hpp"
#include "dao/UsersRedis.hpp"
#include "entity/User.hpp"

#include <vector>
#include <string>
#include <optional>


TEST_CASE("Redis") {
    dao::UsersRedis access;

    SUBCASE("getAllUsers") {
    //     std::vector<entity::User> users = access.getUsers();

    //     CHECK(users.size() == 4);
    //     utils::checkUser(users[0], 1, "user-1", 10);
    //     utils::checkUser(users[1], 2, "user-2", 20);
    //     utils::checkUser(users[2], 3, "user-3", 30);
    //     utils::checkUser(users[3], 4, "user-4", 40);
    }

    SUBCASE("getUserById") {
        std::optional<entity::User> user = access.getUser(1);
        CHECK(user.has_value());
        CHECK(user == entity::User{1, "user-1", 10});
    }
}
