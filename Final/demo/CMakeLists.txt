
add_executable(trees_demo
demo.cpp
)

target_link_libraries(trees_demo 
SearchTrees)
target_include_directories(trees_demo PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/Final/src"
                          )
