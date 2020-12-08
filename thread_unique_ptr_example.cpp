/**
 * thread_unique_ptr_example.cpp
 *
 * Here, I try to illustrate how threads end.
 *
 * If you have a thread that is not detached, then it is technically an error
 * to deconstruct the thread while the thread is still running. Detaching just
 * means that you are not allowed to join them again. There is essentially no
 * control over how the thread runs. Thus, we can't make sure anything is
 * destructed by the time we're done.
 *
 * In the next example, we should look at ways to make sure destruction
 * happens.
 *
 */
#include <iostream>
#include <memory> // for std::unique_ptr
#include <thread>

#include <cstdio> // getchar

#include "expensive_resource.h"

int main() {
    std::cout << "Starting main." << std::endl;

    // always use the actual object, not the pointer
    // right now it's empty
    std::unique_ptr<ExpensiveResource> resource;

    resource = std::move(
            std::unique_ptr<ExpensiveResource>(
                new ExpensiveResource("resource1")));

    std::thread thread1 = std::thread([res = std::move(resource)]() {
        std::cout << "Thread started." << std::endl;
    });
    thread1.detach();
    
    std::thread thread2 = std::thread([]() {
        std::cout << "Thread2 started." << std::endl;
        ExpensiveResource localRes("resource2");
        std::cout << "Thread2 ended." << std::endl;
    });
    thread2.detach();

    // try commenting this out
    std::cout << "(press enter to end the program)" << std::endl;
    std::getchar();

    std::cout << "Ending main." << std::endl;
}

