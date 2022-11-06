add_executable(lab6_test_list
    test_list.cpp
    single_linked_list.cpp
    vector_list.cpp
    list.h
)

target_link_libraries(lab6_test_list gtest_main)

gtest_discover_tests(lab6_test_list)
