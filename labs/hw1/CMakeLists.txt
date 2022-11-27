add_executable(hw1_main
    main.cpp
    hw1.cpp
    hw1.h
)

add_executable(hw1_test
    test_hw1.cpp
    hw1.cpp
    hw1.h
)
target_link_libraries(hw1_test gtest_main)
gtest_discover_tests(hw1_test)
