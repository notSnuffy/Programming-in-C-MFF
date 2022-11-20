add_executable(lab8_memory
    memory.cpp
)

add_executable(lab8_test_list
    test_list.cpp
    list.cpp
    list.h
)
target_link_libraries(lab8_test_list gtest_main)
gtest_discover_tests(lab8_test_list)

add_executable(lab8_histogram
    histogram.cpp
)

add_executable(lab8_test_histogram
    test_histogram.cpp
    histogram.h
)
target_link_libraries(lab8_test_histogram gtest_main)
gtest_discover_tests(lab8_test_histogram)
