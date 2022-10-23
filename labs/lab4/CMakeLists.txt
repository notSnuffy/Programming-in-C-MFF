add_executable(sizeof
    test_sizeof.cpp
)

target_link_libraries(sizeof gtest_main)

gtest_discover_tests(sizeof)
