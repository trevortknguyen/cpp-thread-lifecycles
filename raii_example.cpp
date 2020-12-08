/**
 * raii_example.cpp
 *
 * This shows that the expensive resource's constructor is called when it is
 * declared in the function and the destructor is called when the function
 * exists.
 *
 * Output:
 *
 * Starting main.
 * "resource1" constructed.
 * Ending main.
 * "resource1" destructed.
 * 
 */
#include <iostream>

#include "expensive_resource.h"

int main() {
    std::cout << "Starting main." << std::endl;

    ExpensiveResource m("resource1");

    std::cout << "Ending main." << std::endl;
}

