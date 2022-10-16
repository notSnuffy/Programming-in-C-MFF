add_executable(runtests
    test_linked_list.cpp
    linked_list.h linked_list.cpp
)

target_link_libraries(runtests gtest_main)

gtest_discover_tests(runtests)
