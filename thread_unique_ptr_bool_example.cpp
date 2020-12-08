/**
 * thread_unique_ptr_bool_example.cpp
 *
 * Here, I try to illustrate how threads can be controlled while they're
 * running.
 *
 * In some cases, you want threads to be running in a loop until you tell them
 * to stop. We can do this by sharing memory using an atomic boolean variable
 * that tells threads if they're still running.
 *
 * It's especially important to make sure the while loop will reference the
 * variable as `running->load()` otherwise the truthiness of `running` will
 * always be true because it is a non-null shared pointer.
 *
 */
#include <iostream>
#include <memory> // for std::unique_ptr
#include <thread>
#include <atomic>

#include <cstdio> // getchar

#include "expensive_resource.h"

int main() {
    std::cout << "Starting main." << std::endl;

    std::shared_ptr<std::atomic<bool>> running(new std::atomic<bool>(true));

    // always use the actual object, not the pointer
    // right now it's empty
    std::unique_ptr<ExpensiveResource> resource;

    resource = std::move(
            std::unique_ptr<ExpensiveResource>(
                new ExpensiveResource("resource1")));

    std::thread thread1 = std::thread([res = std::move(resource), running]() {
        std::cout << "Starting thread1." << std::endl;

        while (running->load()) {
            std::cout << "thread1 looping..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(600)); 
        }

        std::cout << "Ending thread1." << std::endl;
    });
    
    std::thread thread2 = std::thread([running]() {
        std::cout << "Starting thread2." << std::endl;
        ExpensiveResource localRes("resource2");

        while (running->load()) {
            std::cout << "thread2 looping..." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(800)); 
        }

        std::cout << "Ending thread2." << std::endl;
    });
 

    std::cout << "(press enter to end the program)" << std::endl;
    std::getchar();
    std::cout << "(enter was pressed)" << std::endl;
    running->store(false);

    thread1.join();
    thread2.join();

    std::cout << "Ending main." << std::endl;
}

