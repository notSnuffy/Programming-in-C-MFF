add_executable(lab7_memory_faults
    memory_faults.cpp
)

add_executable(lab7_test_ctor
    test_ctor.cpp
)
target_link_libraries(lab7_test_ctor gtest_main)
gtest_discover_tests(lab7_test_ctor)
