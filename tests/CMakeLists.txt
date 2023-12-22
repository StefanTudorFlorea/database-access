add_executable(Test_Postgres Test_Postgres.cpp)

target_link_libraries(Test_Postgres PRIVATE database-access doctest::doctest)