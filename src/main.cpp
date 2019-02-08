#include <iostream>
#define ASSERT_ON
#include "test.h"
#include "core/ValueModel.h"
using namespace core;
void valueModelTest()
{
    std::cout  << "set test" << std::endl;
    Value v;
    v.setValue(5);
    ASSERT(v.evaluate() == 5);
}

int main() {
    valueModelTest();
    return 0;
}