#include <doctest/doctest.h>

#include "dao/Users.hpp"
#include "dao/UsersPostgres.hpp"
#include "dao/UsersRedis.hpp"
#include "entity/User.hpp"

#include <vector>
#include <string>
#include <optional>


TEST_CASE("Postgres") {
    dao::UsersPostgres access;

    SUBCASE("getAllUsers") {
        std::vector<entity::User> users = access.getUsers();

        CHECK(users.size() == 4);
        CHECK(users[0] == entity::User{1, "user-1", 10});
        CHECK(users[1] == entity::User{2, "user-2", 20});
        CHECK(users[2] == entity::User{3, "user-3", 30});
        CHECK(users[3] == entity::User{4, "user-4", 40});
    }

    SUBCASE("getExistingUserById") {
        std::optional<entity::User> user = access.getUser(2);
        CHECK(user.has_value());
        CHECK(user == entity::User{2, "user-2", 20});
    }

    SUBCASE("getNonExistingUserById") {
        std::optional<entity::User> user = access.getUser(-1);
        CHECK(!user.has_value());
    }
}
