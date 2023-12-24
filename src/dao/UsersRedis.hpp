#pragma once

// app
#include "Users.hpp"

// deps
#include <sw/redis++/redis++.h>
#include <fmt/core.h>
#include <string>
#include <optional>
#include <memory>

namespace dao {

class UsersRedis : public Users {
public:
    UsersRedis() {
        _redis = connect("localhost", "6379");
    }

    std::vector<entity::User> getUsers() override {
        return {};
    }

    std::optional<entity::User> getUser(int id) override {
        auto name = _redis->get(fmt::format("user:{}:name", id));
        auto age = _redis->get(fmt::format("user:{}:age", id));
        return entity::User{id, *name, std::stoi(*age)};
    }

private:
    std::unique_ptr<sw::redis::Redis> connect(const std::string& host, const std::string& port) {
        std::string connectionParams = fmt::format("tcp://{}:{}", host, port);
        return std::make_unique<sw::redis::Redis>(connectionParams);
    }

private:
    std::unique_ptr<sw::redis::Redis> _redis;
};

} // ns dao