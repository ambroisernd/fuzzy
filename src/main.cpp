#include <iostream>
#define ASSERT_ON
#include "test.h"
#include "core/ValueModel.h"
#include "fuzzy/And/AndMin.h"
#include "fuzzy/And/AndMult.h"
using namespace core;
using namespace fuzzy;
void valueModelTest()
{
    std::cout  << "ValueModel test" << std::endl;
    Value v(5);
    ASSERT(v.evaluate() == 5);
    v.setValue(10);
    ASSERT(v.evaluate() == 10);
}
void andMinTest(){
    std::cout  << "AndMin test" << std::endl;
    AndMini am;
    Value t(true);
    Value f(false);
    ASSERT(am.evaluate(&t,&f) == 0) //expecting TRUE and FALSE = FALSE
}
void andMultTest(){
    std::cout << "AndMult test" << std::endl;
    AndMulti am;
    Value l(2);
    Value r(3);
    ASSERT(am.evaluate(&l,&r) == 6); //expecting 2*3=6
}

int main() {
    valueModelTest();
    andMinTest();
    andMultTest();
    return 0;
}