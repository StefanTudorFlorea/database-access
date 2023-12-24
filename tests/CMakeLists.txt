add_executable(Test_DatabaseAccess 
    Test_Redis.cpp
    Test_Postgres.cpp
)

target_link_libraries(Test_DatabaseAccess 
    PRIVATE 
        database-access 
        doctest::doctest
)