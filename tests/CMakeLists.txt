# add_definitions(-DDOCTEST_CONFIG_IMPLEMENT_WITH_MAIN)

add_executable(Test_DatabaseAccess 
    utils.hpp
    
    Test_Redis.cpp
    Test_Postgres.cpp
)

target_link_libraries(Test_DatabaseAccess 
    PRIVATE 
        database-access 
        doctest::doctest
)