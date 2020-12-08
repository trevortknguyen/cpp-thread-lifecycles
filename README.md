# C++ Thread Lifecycles

Here, we explore the lifecycle of C++ threads.

## Goals

We would like to show how RAII (resource acquisition is initialization) objects
are handled within the context of threads.

I would also like to cover what it means to "detach" a thread using the
cross-platform `std::thread` API.

Lastly, I would like to show a way to ensure the destruction of resources in
loop-based threads via atomic booleans.

Here's the suggested order to explore the examples.
- raii_example.cpp
- unique_ptr_example.cpp
- thread_unique_ptr_example.cpp
- thread_unique_ptr_bool_example.cpp

## Compiling

This project uses CMake. You can do a platform-independent build using CMake's
commands.

`cmake -B build`

`cmake --build build`

## Running

`./build/raii_example`

`./build/unique_ptr_example`

`./build/thread_unique_ptr_example`

`./build/thread_unique_ptr_bool_example`

