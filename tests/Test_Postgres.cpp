#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include "dao/Users.hpp"
#include "dao/UsersPostgres.hpp"
#include "entity/User.hpp"

#include <vector>
#include <string>


TEST_CASE("Postgres") {
    dao::UsersPostgres access;

    auto check_user = [](const entity::User& user, 
                         int expectedId, std::string expectedName, int expectedAge){
        CHECK(user.id   == expectedId);
        CHECK(user.name == expectedName);
        CHECK(user.age  == expectedAge);
    };

    SUBCASE("initializeDatabase") {
        std::vector<entity::User> users = access.getUsers();

        CHECK(users.size() == 4);
        check_user(users[0], 1, "user-1", 10);
        check_user(users[1], 2, "user-2", 20);
        check_user(users[2], 3, "user-3", 30);
        check_user(users[3], 4, "user-4", 40);
    }
}
