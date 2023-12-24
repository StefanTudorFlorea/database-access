#pragma once

// app
#include "Users.hpp"

// deps
#include <fmt/core.h>
#include <pqxx/pqxx>
#include <string>
#include <memory>
#include <optional>

namespace dao {

class UsersPostgres : public Users {
public:
    UsersPostgres() {
        _conn = connect("localhost", "5432", "admin", "demo123", "data");
    }

    std::vector<entity::User> getUsers() override {

        // query
        pqxx::work tx{*_conn};
        auto res = tx.query<int, std::string, int>("SELECT id,name,age FROM user_");

        std::vector<entity::User> users;
        for (auto[id, name, age] : res) {
            users.push_back(entity::User{id, name, age});
        }

        // done
        return users;
    }

    std::optional<entity::User> getUser(int id) override {

        // query
        std::string query = fmt::format("SELECT id,name,age FROM user_ WHERE id = {}", id);
        pqxx::work tx{*_conn};

        try {
            auto[uid, name, age] = tx.query1<int, std::string, int>(query);
            return entity::User{uid, name, age};

        } catch(const pqxx::unexpected_rows& err) {
            fmt::print("[ERROR]: Cannot get user. Requested id {} does not exists", id);
            return {};
        }

        // done
        return {};
    }

private:
    std::unique_ptr<pqxx::connection> connect(std::string host,
                                              std::string port,
                                              std::string user,
                                              std::string password,
                                              std::string dbname) {
                            
    std::string connectionParams = fmt::format("host={} port={} user={} password={} dbname={}", 
                                                host, port, user, password, dbname);

    return std::make_unique<pqxx::connection>(connectionParams);
}

private:
    std::unique_ptr<pqxx::connection> _conn;
};
    
} // ns dao
