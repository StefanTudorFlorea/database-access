#pragma once

// app
#include "dao/Users.hpp"

// deps
#include <sw/redis++/redis++.h>
#include <fmt/core.h>
#include <string>
#include <optional>
#include <memory>
#include <unordered_map>
#include <iterator>


namespace dao {
namespace redis {

class Users : public dao::Users {
public:
    Users() {
        _redis = connect("localhost", "6379");
    }

    std::vector<entity::User> getUsers() override {
        return {};
    }

    std::optional<entity::User> getUser(int id) override {

        std::unordered_map<std::string, std::string> res;
        _redis->hgetall(fmt::format("user#{}", id), std::inserter(res, res.begin()));

        return entity::User{id, res["name"], std::stoi(res["age"])};
    }

private:
    std::unique_ptr<sw::redis::Redis> connect(const std::string& host, const std::string& port) {
        std::string connectionParams = fmt::format("tcp://{}:{}", host, port);
        return std::make_unique<sw::redis::Redis>(connectionParams);
    }

private:
    std::unique_ptr<sw::redis::Redis> _redis;
};

} // ns redis
} // ns dao