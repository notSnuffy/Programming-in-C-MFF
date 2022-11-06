add_executable(lab3_test_list
    test_linked_list.cpp
    linked_list.h linked_list.cpp
)

target_link_libraries(lab3_test_list gtest_main)

gtest_discover_tests(lab3_test_list)
