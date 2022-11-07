add_executable(lab5_test_list
    test_list.cpp
    single_linked_list.cpp
    list.h
)

target_link_libraries(lab5_test_list gtest_main)

gtest_discover_tests(lab5_test_list)
