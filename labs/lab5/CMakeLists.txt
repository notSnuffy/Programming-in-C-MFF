add_executable(test_list
    test_list.cpp
    single_linked_list.cpp
    list.h
)

target_link_libraries(test_list gtest_main)

gtest_discover_tests(test_list)
