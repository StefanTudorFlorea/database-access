#pragma once

// app
#include "Users.hpp"

// deps
#include <fmt/core.h>
#include <pqxx/pqxx>
#include <string>
#include <memory>


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
