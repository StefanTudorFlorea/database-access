# database-access
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src *.cpp)
file(GLOB_RECURSE HDR_FILES ${PROJECT_SOURCE_DIR}/src *.hpp)

add_library(database-access ${SRC_FILES} ${HDR_FILES})
target_include_directories(database-access PUBLIC .)

target_link_libraries(database-access
    PUBLIC
        fmt::fmt-header-only
        libpqxx::pqxx
        redis++::redis++_static       
)