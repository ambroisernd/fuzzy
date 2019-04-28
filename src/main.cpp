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

void useCase(){
    NotMinus1 opNot;
    AndMin opAnd;
    OrMax opOr;
    AggMax opgAgg;
    ThenMin opgThen;

    CogDefuzz opDefuzz(0, 25, 1);
    //BoaDefuzz opDefuzz(0, 25, 1);

    FuzzyFactory f(&opNot, &opAnd, &opOr, &opgThen, &opgAgg, &opDefuzz);

    //vent
    isGaussian leger(0, 1.5);
    isGaussian modere(5, 1.5);
    isGaussian violent(10, 1.5);

    //pluie
    isTrapezeLeft faible(2, 4);
    isTrapezeRight battante(7,9);

    //neige
    isTriangle legere(5, 10, 15);
    isTriangle epaisse(15, 20, 25);

    //temperature
    isBell glaciale(2,1,0);
    isBell douce(2,1,5);
    isBell eleve(2,1,10);

    //zone
    isGaussian verte(0,1.5);
    isGaussian jaune(3,1.5);
    isGaussian orange(6,1.5);
    isGaussian rouge(9,1.5);

    ValueModel vent(0);
    ValueModel pluie(0);
    ValueModel neige(0);
    ValueModel temperature(0);
    ValueModel zone(0);

    //si vent leger ou pluie faible ou temperature douce -> zone verte
    //si pluie battante -> zone jaune
    //si neige legere et vent modere ou temperature elevee -> zone orange
    //si temperature glaciale et vent violent ou neige epaisse -> zone rouge

    Expression *r =
            f.newAgg(
                    f.newAgg(
                            f.newThen(
                                    f.newOr(f.newOr(f.newIs(&leger,&vent),f.newIs(&faible,&pluie)),f.newIs(&douce,&temperature)),
                                    f.newIs(&verte, &zone)
                            ),
                            f.newThen(
                                    f.newIs(&battante, &pluie),
                                    f.newIs(&jaune, &zone)
                            )
                            ),
                    f.newAgg(
                            f.newThen(
                                    f.newOr(f.newIs(&eleve,&temperature),f.newAnd(f.newIs(&legere, &neige), f.newIs(&modere, &vent))),
                                    f.newIs(&orange, &zone)
                            ),
                            f.newThen(
                                    f.newOr(f.newIs(&epaisse,&neige),f.newAnd(f.newIs(&glaciale, &temperature), f.newIs(&violent, &vent))),
                                    f.newIs(&rouge, &zone)
                            )
                    )

            );



    Expression *system = f.newMamdani(&zone, r);

    float v;
    float p;
    float n;
    float t;
    while(true){
        std::cout << "vent: "; std::cin>>v;
        std::cout << "pluie: "; std::cin>>p;
        std::cout << "neige: "; std::cin>>n;
        std::cout << "temperature: "; std::cin>>t;
        vent.setValue(v);
        pluie.setValue(p);
        neige.setValue(n);
        temperature.setValue(t);
        std::cout << "zone-> " << system->evaluate() << std::endl;
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
    useCase();
    return 0;
}