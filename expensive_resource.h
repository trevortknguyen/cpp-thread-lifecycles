#pragma once

#include <iostream>
#include <string>

class ExpensiveResource {
public:
    ExpensiveResource(std::string name_) : name(name_) {
        std::cout << "\"" << name  << "\" constructed." << std::endl;
    }

    ~ExpensiveResource() {
        std::cout << "\"" << name  << "\" destructed." << std::endl;
    }
private:
    std::string name;
};

