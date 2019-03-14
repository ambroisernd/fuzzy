#include <iostream>
#define ASSERT_ON
#include "test.h"
#include "core/ValueModel.h"
#include "fuzzy/And/AndMin.h"
#include "fuzzy/And/AndMult.h"
#include "fuzzy/Or/OrMax.h"
#include "fuzzy/Then/ThenMin.h"
#include "fuzzy/is/isTriangle.h"
#include "fuzzy/is/isTrapeze.h"
#include "fuzzy/is/isTrapezeLeft.h"
#include "fuzzy/is/isTrapezeRight.h"
#include "fuzzy/is/isBell.h"
#include "fuzzy/is/isGaussian.h"
#include "fuzzy/Agg/AggPlus.h"


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

void isTrapezeTest(){
    std::cout << "isTrapeze test" << std::endl;
    isTrapeze<float> poor(-5,-1,1,5);
    ValueModel<float> food(2);
    ValueModel<float> service(6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in trapeze
    ASSERT(poor.evaluate(&service) == 0); //expecting false : 6 is not in trapeze
}

void isTrapezeLeftTest(){
    std::cout << "isTrapezeLeft test" << std::endl;
    isTrapezeLeft<float> poor(0,5);
    ValueModel<float> food(2);
    ValueModel<float > service(6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in lefttrapeze
    ASSERT(poor.evaluate(&service) == 0); //expecting false : 6 is not in lefttrapeze
}

void isTrapezeRightTest(){
    std::cout << "isTrapezeRight test" << std::endl;
    isTrapezeRight<float> poor(-5,0);
    ValueModel<float> food(2);
    ValueModel<float > service(-6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in righttrapeze
    ASSERT(poor.evaluate(&service) == 0); //expecting flase : -6 is not in righttrapeze
}

void isGaussianTest(){
    std::cout << "isGaussian test" << std::endl;
    isGaussian<float> poor(2,5);
    ValueModel<float> food(2);
    ValueModel<float> service(6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in gaussian
    ASSERT(poor.evaluate(&service) != 0); //expecting true : 6 is in gaussian
}

void isBellTest(){
    std::cout << "isBell test" << std::endl;
    isBell<float> poor(0,5,0);
    ValueModel<float> food(2);
    ValueModel<float> service(6);
    ASSERT(poor.evaluate(&food) == 0); //expecting false : 2 is in bell
    ASSERT(poor.evaluate(&service) == 0); //expecting false : 6 is not in bell
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

void aggregationMaxTest(){
    std::cout << "aggregationMax test" << std::endl;
    AggMax<float> ag;
    ValueModel<float> t(0.75);
    ValueModel<float> f(0.5);
    ASSERT(ag.evaluate(&t,&f) == 0.75);
    ValueModel<float> f2(0.1);
    ValueModel<float> f3(10);
    ASSERT(ag.evaluate(&f2,&f3) == 10);
}

void aggregationPlusTest(){
    std::cout << "aggregationPlus test" << std::endl;
    AggPlus<float> ag;
    ValueModel<float> t(0.7);
    ValueModel<float> f(0.3);
    ASSERT(ag.evaluate(&t,&f) == 1.0);
    ValueModel<float> a(1.5);
    ValueModel<float> b(0.5);
    ASSERT(ag.evaluate(&a,&b) == 2.0);
}

void orPlusTest(){
    std::cout << "orPlus test" << std::endl;
    AggPlus<float> ag;
    ValueModel<float> t(0.7);
    ValueModel<float> f(0.3);
    ASSERT(ag.evaluate(&t,&f) == 1.0);
    ValueModel<float> a(1.5);
    ValueModel<float> b(0.5);
    ASSERT(ag.evaluate(&a,&b) == 2.0);
}

int main() {
    valueModelTest();
    andMinTest();
    andMultTest();
    orMaxTest();
    thenMinTest();
    isTriangleTest();
    isTrapezeTest();
    isTrapezeLeftTest();
    isTrapezeRightTest();
    isGaussianTest();
    isBellTest();
    notMinusTest();
    aggregationMaxTest();
    aggregationPlusTest();
    orPlusTest();
    return 0;
}