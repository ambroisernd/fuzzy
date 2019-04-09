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
#include "fuzzy/FuzzyFactory.h"

#include "fuzzy/Defuzz/CogDefuzz.h"
#include "fuzzy/Defuzz/SugenoConclusion.h"

#include "fuzzy/fuzzy.h"
#include "core/core.h"


void valueModelTest()
{
    std::cout  << "ValueModel test" << std::endl;
    ValueModel v(5);
    ASSERT(v.evaluate() == 5);
    v.setValue(10);
    ASSERT(v.evaluate() == 10);
}
void andMinTest(){
    std::cout  << "AndMin test" << std::endl;
    AndMin am;
    ValueModel t(true);
    ValueModel f(false);
    ASSERT(!am.evaluate(&t, &f)) //expecting TRUE and FALSE = FALSE
}
void andMultTest(){
    std::cout << "AndMult test" << std::endl;
    AndMult am;
    ValueModel l(2);
    ValueModel r(3);
    ASSERT(am.evaluate(&l,&r) == 6); //expecting 2*3=6
}
void orMaxTest(){
    std::cout << "OrMax test" << std::endl;
    OrMax om;
    ValueModel t(true);
    ValueModel f(false);
    ASSERT(om.evaluate(&t,&f) == 1); //expecting TRUE or FALSE = TRUE
    ValueModel f2(false);
    ValueModel f3(false);
    ASSERT(om.evaluate(&f2,&f3) == 0); //expecting FALSE or FALSE = FALSE
}
void thenMinTest(){
    std::cout << "ThenMin test" << std::endl;
    ThenMin tm;
    ValueModel t(true);
    ValueModel f(false);
    ASSERT(!tm.evaluate(&t, &f));
}
void isTriangleTest(){
    std::cout << "isTriangle test" << std::endl;
    isTriangle poor(-5,0,5);
    ValueModel food(2);
    ValueModel service(6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in triangle
    ASSERT(poor.evaluate(&service) == 0); //expecting false : 6 is not in triangle
}

void isTrapezeTest(){
    std::cout << "isTrapeze test" << std::endl;
    isTrapeze poor(-5,-1,1,5);
    ValueModel food(2);
    ValueModel service(6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in trapeze
    ASSERT(poor.evaluate(&service) == 0); //expecting false : 6 is not in trapeze
}

void isTrapezeLeftTest(){
    std::cout << "isTrapezeLeft test" << std::endl;
    isTrapezeLeft poor(0,5);
    ValueModel food(2);
    ValueModel service(6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in lefttrapeze
    ASSERT(poor.evaluate(&service) == 0); //expecting false : 6 is not in lefttrapeze
}

void isTrapezeRightTest(){
    std::cout << "isTrapezeRight test" << std::endl;
    isTrapezeRight poor(-5,0);
    ValueModel food(2);
    ValueModel service(-6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in righttrapeze
    ASSERT(poor.evaluate(&service) == 0); //expecting flase : -6 is not in righttrapeze
}

void isGaussianTest(){
    std::cout << "isGaussian test" << std::endl;
    isGaussian poor(2,5);
    ValueModel food(2);
    ValueModel service(6);
    ASSERT(poor.evaluate(&food) != 0); //expecting true : 2 is in gaussian
    ASSERT(poor.evaluate(&service) != 0); //expecting true : 6 is in gaussian
}

void isBellTest(){
    std::cout << "isBell test" << std::endl;
    isBell poor(0,5,0);
    ValueModel food(2);
    ValueModel service(6);
    ASSERT(poor.evaluate(&food) == 0); //expecting false : 2 is in bell
    ASSERT(poor.evaluate(&service) == 0); //expecting false : 6 is not in bell
}

void notMinusTest(){
    std::cout << "notMinus test" << std::endl;
    ValueModel t(true);
    NotMinus1 nobool;
    ASSERT(!nobool.evaluate(&t));
    ValueModel val(0.75);
    NotMinus1 nofloat;
    ASSERT(nofloat.evaluate(&val) == 0.25);
}

void aggregationMaxTest(){
    std::cout << "aggregationMax test" << std::endl;
    AggMax ag;
    ValueModel t(0.75);
    ValueModel f(0.5);
    ASSERT(ag.evaluate(&t,&f) == 0.75);
    ValueModel f2(0.1);
    ValueModel f3(10);
    ASSERT(ag.evaluate(&f2,&f3) == 10);
}

void aggregationPlusTest(){
    std::cout << "aggregationPlus test" << std::endl;
    AggPlus ag;
    ValueModel t(0.7);
    ValueModel f(0.3);
    ASSERT(ag.evaluate(&t,&f) == 1.0);
    ValueModel a(1.5);
    ValueModel b(0.5);
    ASSERT(ag.evaluate(&a,&b) == 2.0);
}

void orPlusTest(){
    std::cout << "orPlus test" << std::endl;
    OrPlus ag;
    ValueModel t(0.7);
    ValueModel f(0.3);
    ASSERT(ag.evaluate(&t,&f) == 1.0);
    ValueModel a(1.5);
    ValueModel b(0.5);
    ASSERT(ag.evaluate(&a,&b) == 2.0);
}

void sugenoConclusionTest(){
    std::cout << "sugenoConclusion test" << std::endl;
    //Construction du vecteur coeffs
    std::vector<int> coeffs;
    for(int i=0; i<4; i++){
        coeffs.push_back(i);
    }
    fuzzy::SugenoConclusion<int> sc(coeffs);

    core::ValueModel<int> v3(3);
    core::ValueModel<int> v2(2);
    core::ValueModel<int> v1(1);

    std::vector<core::Expression<int> *> op;
    op.push_back(&v1);
    op.push_back(&v2);
    op.push_back(&v3);

    ASSERT(sc.evaluate(&op) == 0*1+1*2+2*3+3);

}

void useCase(){
    NotMinus1 opNot;
    AndMin opAnd;
    OrMax opOr;
    AggMax opgAgg;
    ThenMin opgThen;

    CogDefuzz opDefuzz(0, 25, 1);
    //BoaDefuzz opDefuzz(0, 25, 1);

    FuzzyFactory f(&opNot, &opAnd, &opOr, &opgThen, &opgAgg, &opDefuzz);
    isGaussian poor(0, 1.5);
    isGaussian good(5, 1.5);
    isGaussian excellent(10, 1.5);

    isTriangle cheap(0, 5, 10);
    isTriangle average(10, 15, 20);
    isTriangle generous(20, 25, 30);

    ValueModel service(0);
    ValueModel food(0);
    ValueModel tips(0);

    Expression *r =
            f.newAgg(
                    f.newAgg(
                            f.newThen(
                                    f.newIs(&poor, &service),
                                    f.newIs(&cheap, &tips)
                                    ),
                                    f.newThen(
                                            f.newIs(&good, &service),
                                            f.newIs(&average, &tips)
                                            )
                            ),
                            f.newThen(
                                    f.newIs(&excellent, &service),
                                    f.newIs(&generous, &tips)
                                    )
                    );

    Expression *system = f.newMamdani(&tips, r);

    float s;
    while(true){
        std::cout << "service: "; std::cin>>s;
        service.setValue(s);
        std::cout << "tips-> " << system->evaluate() << std::endl;
    }

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
    sugenoConclusionTest();
    useCase();
    return 0;
}