#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "utils.hpp"

#include "dao/Users.hpp"
#include "dao/UsersPostgres.hpp"
#include "entity/User.hpp"

#include <vector>
#include <string>
#include <optional>


TEST_CASE("Postgres") {
    dao::UsersPostgres access;

    SUBCASE("getAllUsers") {
        std::vector<entity::User> users = access.getUsers();

        CHECK(users.size() == 4);
        utils::checkUser(users[0], 1, "user-1", 10);
        utils::checkUser(users[1], 2, "user-2", 20);
        utils::checkUser(users[2], 3, "user-3", 30);
        utils::checkUser(users[3], 4, "user-4", 40);
    }

    SUBCASE("getExistingUserById") {
        std::optional<entity::User> user = access.getUser(2);
        CHECK(user.has_value());
        utils::checkUser(user.value(), 2, "user-2", 20);
    }

    SUBCASE("getNonExistingUserById") {
        std::optional<entity::User> user = access.getUser(-1);
        CHECK(!user.has_value());
    }
}
