add_subdirectory(compared_trees)
add_executable(compare_trees
    compare.cpp 
)

target_link_libraries(compare_trees 
SearchTrees
CompareTrees)
target_include_directories(compare_trees PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Final/src"
                          "${PROJECT_SOURCE_DIR}/Final/comparer/compared_trees"
                          )
