#include <iostream>
#define ASSERT_ON
#include "test.h"
#include "core/ValueModel.h"
using namespace core;
void valueModelTest()
{
    std::cout  << "set test" << std::endl;
    ValueModel <int> vm = ValueModel<int>();
    vm.setValue(5);
    ASSERT(vm.evaluate() == 6);
}

int main() {
    valueModelTest();
    return 0;
}