#include <iostream>
#define ASSERT_ON
#include "test.h"
void dummyTest()
{
    std::cout  << "dummy test" << std::endl;
    ASSERT(1==1);
}

int main() {
    dummyTest();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}