/**
 * unique_ptr_example.cpp
 *
 * Here, I try to illustrate how unique_ptrs are used and how they function
 * in regards to how and when they automatically call constructors.
 *
 * This should behave exactly like RAII except it should allow for dynamic
 * assignment.
 *
 * You can investigate how you can pass the unique pointer into functions.
 *
 */
#include <iostream>
#include <memory> // for std::unique_ptr

#include "expensive_resource.h"

int main() {
    std::cout << "Starting main." << std::endl;

    // always use the actual object, not the pointer
    // right now it's empty
    std::unique_ptr<ExpensiveResource> resource;

    resource = std::move(
            std::unique_ptr<ExpensiveResource>(
                new ExpensiveResource("resource1")));

    std::cout << "Ending main." << std::endl;
}

