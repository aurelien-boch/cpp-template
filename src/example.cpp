#include <iostream>
#include "example.hpp"

void example::say_hello() {
    std::cout << "Hello, world !" << std::endl;
}

int example::addition(int a, int b)
{
    return a + b;
}
