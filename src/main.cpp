#include <iostream>
#define ASSERT_ON
#include "test.h"
#include "core/ValueModel.h"
#include "fuzzy/And/AndMin.h"
#include "fuzzy/And/AndMult.h"
#include "fuzzy/Or/OrMax.h"
#include "fuzzy/Then/ThenMin.h"
#include "fuzzy/is/isTriangle.h"
#include "fuzzy/Not/NotMinus1.h"
#include "fuzzy/Agg/AggMax.h"
using namespace core;
using namespace fuzzy;
void valueModelTest()
{
    std::cout  << "ValueModel test" << std::endl;
    ValueModel<float> v(5);
    ASSERT(v.evaluate() == 5);
    v.setValue(10);
    ASSERT(v.evaluate() == 10);
}
void andMinTest(){
    std::cout  << "AndMin test" << std::endl;
    AndMin<bool> am;
    ValueModel<bool> t(true);
    ValueModel<bool> f(false);
    ASSERT(!am.evaluate(&t, &f)) //expecting TRUE and FALSE = FALSE
}
void andMultTest(){
    std::cout << "AndMult test" << std::endl;
    AndMult<float> am;
    ValueModel<float> l(2);
    ValueModel<float> r(3);
    ASSERT(am.evaluate(&l,&r) == 6); //expecting 2*3=6
}
void orMaxTest(){
    std::cout << "OrMax test" << std::endl;
    OrMax<bool> om;
    ValueModel<bool> t(true);
    ValueModel<bool> f(false);
    ASSERT(om.evaluate(&t,&f) == 1); //expecting TRUE or FALSE = TRUE
    ValueModel<bool> f2(false);
    ValueModel<bool> f3(false);
    ASSERT(om.evaluate(&f2,&f3) == 0); //expecting FALSE or FALSE = FALSE
}
void thenMinTest(){
    std::cout << "ThenMin test" << std::endl;
    ThenMin<bool> tm;
    ValueModel<bool> t(true);
    ValueModel<bool> f(false);
    ASSERT(!tm.evaluate(&t, &f));
}
void isTriangleTest(){
    std::cout << "isTriangle test" << std::endl;
    isTriangle<float> poor(-5,0,5);
    ValueModel<float> food(2);
    ValueModel<float > service(6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in triangle
    ASSERT(poor.evaluate(&service) == 0); //expecting false : 6 is not in triangle
}

void notMinusTest(){
    std::cout << "notMinus test" << std::endl;
    ValueModel<bool> t(true);
    NotMinus1<bool> nobool;
    ASSERT(!nobool.evaluate(&t));
    ValueModel<float> val(0.75);
    NotMinus1<float> nofloat;
    ASSERT(nofloat.evaluate(&val) == 0.25);
}

void aggregationMax(){
    std::cout << "aggregationMax test" << std::endl;
    AggMax<float> ag;
    ValueModel<float> t(0.75);
    ValueModel<float> f(0.5);
    ASSERT(ag.evaluate(&t,&f) == 0.75); //expecting TRUE or FALSE = TRUE
    ValueModel<float> f2(0.1);
    ValueModel<float> f3(10);
    ASSERT(ag.evaluate(&f2,&f3) == 10); //expecting FALSE or FALSE = FALSE
}

int main() {
    valueModelTest();
    andMinTest();
    andMultTest();
    orMaxTest();
    thenMinTest();
    isTriangleTest();
    notMinusTest();
    aggregationMax();
    return 0;
}