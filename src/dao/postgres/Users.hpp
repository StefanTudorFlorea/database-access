#pragma once

// app
#include "dao/Users.hpp"
#include "common/utils.hpp"

// deps
#include <fmt/core.h>
#include <pqxx/pqxx>
#include <string>
#include <memory>
#include <optional>

namespace dao { 
namespace postgres {

class Users : public dao::Users {
public:
    Users() {
        _conn = connect(utils::getEnvVarOr("postgres.hostname", "localhost"), 
                        utils::getEnvVarOr("postgres.port", "5432"), 
                        utils::getEnvVarOr("postgres.user", "admin"), 
                        utils::getEnvVarOr("postgres.password", "demo123"), 
                        utils::getEnvVarOr("postgres.database", "data"));
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

} // ns postgres
} // ns dao
