#include <iostream>
#define ASSERT_ON
#include "test.h"
#include "core/ValueModel.h"
#include "fuzzy/And/AndMin.h"
using namespace core;
using namespace fuzzy;
void valueModelTest()
{
    std::cout  << "ValueModel set test" << std::endl;
    Value v(5);
    ASSERT(v.evaluate() == 5);
}
void andMinTest(){
    std::cout  << "AndMin test" << std::endl;
    AndMini am;
    Value t(true);
    Value f(false);
    ASSERT(am.evaluate(&t,&f) == 0)
}

int main() {
    valueModelTest();
    andMinTest();
    return 0;
}