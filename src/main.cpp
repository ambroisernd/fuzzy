#include <iostream>
#define ASSERT_ON
#include "test.h"
#include "core/ValueModel.h"
#include "fuzzy/And/OpAndMin.h"
#include "fuzzy/And/OpAndMult.h"
#include "fuzzy/Or/OpOrMax.h"
#include "fuzzy/Then/OpThenMin.h"
#include "fuzzy/is/isTriangle.h"
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
    std::cout  << "OpAndMin test" << std::endl;
    AndMin am;
    Value t(true);
    Value f(false);
    ASSERT(am.evaluate(&t,&f) == 0) //expecting TRUE and FALSE = FALSE
}
void andMultTest(){
    std::cout << "OpAndMult test" << std::endl;
    AndMult am;
    Value l(2);
    Value r(3);
    ASSERT(am.evaluate(&l,&r) == 6); //expecting 2*3=6
}
void orMaxTest(){
    std::cout << "OpOrMax test" << std::endl;
    OrMax om;
    Value t(true);
    Value f(false);
    ASSERT(om.evaluate(&t,&f) == 1); //expecting TRUE or FALSE = TRUE
    Value f2(false);
    Value f3(false);
    ASSERT(om.evaluate(&f2,&f3) == 0); //expecting FALSE or FALSE = FALSE
}
void thenMinTest(){
    std::cout << "OpThenMin test" << std::endl;
    ThenMin tm;
    Value t(true);
    Value f(false);
    ASSERT(tm.evaluate(&t,&f) == 0);
}
void isTriangleTest(){
    std::cout << "isTriangle test" << std::endl;
    IsTriangle poor(-5,0,5);
    Value food(2);
    Value service(6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in triangle
    ASSERT(poor.evaluate(&service) == 0); //expecting false : 6 is not in triangle
}

int main() {
    valueModelTest();
    andMinTest();
    andMultTest();
    orMaxTest();
    thenMinTest();
    isTriangleTest();
    return 0;
}