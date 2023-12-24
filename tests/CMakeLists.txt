add_executable(Test_DatabaseAccess 
    utils.hpp
    
    Test_Postgres.cpp
)

target_link_libraries(Test_DatabaseAccess 
    PRIVATE 
        database-access 
        doctest::doctest
)