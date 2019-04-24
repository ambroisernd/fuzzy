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

    CogDefuzz opDefuzz(0, 30, 1);
    //BoaDefuzz opDefuzz(0, 30, 1);

    FuzzyFactory f(&opNot, &opAnd, &opOr, &opgThen, &opgAgg, &opDefuzz);

    //service
    isGaussian poor(0, 1.5);
    isGaussian good(5, 1.5);
    isGaussian excellent(10, 1.5);

    //food
    isTrapezeLeft rancid(1, 3);
    isTrapezeRight delicious(7,9);
    //trapère rancid 0 0 1 3
    //trapere delicious 7 9 10 10

    //tips
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
                                    f.newOr(f.newIs(&poor, &service), f.newIs(&rancid, &food)),
                                    f.newIs(&cheap, &tips)
                            ),
                            f.newThen(
                                    f.newIs(&good, &service),
                                    f.newIs(&average, &tips)
                            )
                            ),
                            f.newThen(
                                     f.newOr(f.newIs(&excellent, &service),f.newIs(&delicious, &food)),
                                     f.newIs(&generous, &tips)
                    )
            );



    Expression *system = f.newMamdani(&tips, r);

    double s;
    double p;
    while(true){
        std::cout << "service: "; std::cin>>s;
        std::cout << "food: "; std::cin>>p;
        service.setValue(s);
        food.setValue(p);
        std::cout << "tips-> " << system->evaluate() << std::endl;
    }

}

void useCaseSugeno(){
    NotMinus1 opNot;
    AndMin opAnd;
    OrMax opOr;
    AggMax opgAgg;
    SugenoThen opgThen;

    std::vector<double> v;
    v.push_back(2.0L);
    v.push_back(1.0L);
    v.push_back(0.0L);

    SugenoDefuzz opSugeno;

    SugenoConclusion opSugenoConclusion(v);
    SugenoConclusion opSugenoConclusion1(v);
    SugenoConclusion opSugenoConclusion2(v);

    FuzzyFactory f(&opNot, &opAnd, &opOr, &opgThen, &opgAgg, &opSugenoConclusion, &opSugeno);

    ValueModel humidite(0.5);
    ValueModel pression(0.2);

    ValueModel orage(0);

    isTriangle faible(0, 5, 10);
    isTriangle moyenne(10, 15, 20);
    isTriangle forte(20, 25, 30);

    isTriangle minime(0, 5, 10);
    isTriangle medium(10, 15, 20);
    isTriangle elevee(20, 25, 30);

    isTriangle peu(0, 5, 10);
    isTriangle probable(10, 15, 20);
    isTriangle certain(20, 25, 30);

    std::vector<Expression*> vectValueModel;
    vectValueModel.push_back(&humidite);
    vectValueModel.push_back(&pression);


    Expression *r1 = f.newThen(
            f.newAnd(f.newIs(&faible, &humidite), f.newIs(&minime,&pression)),
            f.newSugenoConclusion(&vectValueModel)
    );

    f.changeSugenoConclusion(&opSugenoConclusion1);

    Expression *r2 = f.newThen(
            f.newAnd(f.newIs(&moyenne, &humidite), f.newIs(&medium,&pression)),
            f.newSugenoConclusion(&vectValueModel)
    );

    f.changeSugenoConclusion(&opSugenoConclusion2);
    Expression *r3 = f.newThen(
            f.newAnd(f.newIs(&forte, &humidite), f.newIs(&elevee,&pression)),
            f.newSugenoConclusion(&vectValueModel)
    );

    std::vector<Expression *> vectExpression;
    vectExpression.push_back(r1);
    vectExpression.push_back(r2);
    vectExpression.push_back(r3);

    Expression* system = f.newSugeno(&vectExpression);

    float h;
    float p;
    while(true){

        std::cout << "humidite:" ; std::cin >>h;

        std::cout << "pression: "; std::cin>>p;
        humidite.setValue(h);
        pression.setValue(p);
        std::cout << "orage-> " << system->evaluate() << std::endl;

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
    //useCase();
    useCaseSugeno();
    return 0;
}
