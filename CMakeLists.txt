cmake_minimum_required(VERSION 3.10)

project(ThreadLifecycles)

add_executable(raii_example raii_example.cpp)

add_executable(unique_ptr_example unique_ptr_example.cpp)

add_executable(thread_unique_ptr_example thread_unique_ptr_example.cpp)
target_link_libraries(thread_unique_ptr_example
    # add pthread if Clang or GNU, but not Windows
    $<$<CXX_COMPILER_ID:Clang,GNU>:pthread>
)


add_executable(thread_unique_ptr_bool_example thread_unique_ptr_bool_example.cpp)

target_link_libraries(thread_unique_ptr_bool_example
    # add pthread if Clang or GNU, but not Windows
    $<$<CXX_COMPILER_ID:Clang,GNU>:pthread>
)
