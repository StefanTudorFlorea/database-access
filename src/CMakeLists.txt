# database-access
file(GLOB SRC_FILES ./*.cpp)
file(GLOB HFR_FILES ./*.hpp)

add_library(database-access INTERFACE)
target_include_directories(database-access INTERFACE .)

target_link_libraries(database-access
    INTERFACE
        fmt::fmt-header-only
        libpqxx::pqxx
        redis++::redis++_static       
)