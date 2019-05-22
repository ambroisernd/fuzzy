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
#include "fuzzy/Defuzz/LomDefuzz.h"
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

    //CogDefuzz opDefuzz(0, 30, 1);
    //BoaDefuzz opDefuzz(0, 30, 1);
    LomDefuzz opDefuzz(0, 30, 1);

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
    isBell douce(2,1,0);
    isBell eleve(2,1,5);
    isBell glaciale(2,1,10);

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
        double a= system->evaluate();
        std::cout << "zone-> " <<system->evaluate() << std::endl;
        std::string condition;
        if(a<=2) {
            condition ="zone verte";
        }
        if(a<=4 && a>2) {
            condition = "zone jaune";
        }
        if(a<=6 && a>4) {
            condition = "zone orange";
        }
        else {
            condition = "zone rouge";
        }
        std::cout<<condition<<std::endl;

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
    v.push_back(5.0L);
    v.push_back(1.0L);

    SugenoDefuzz opSugeno;

    SugenoConclusion opSugenoConclusion(v);
    SugenoConclusion opSugenoConclusion1(v);
    SugenoConclusion opSugenoConclusion2(v);

    FuzzyFactory f(&opNot, &opAnd, &opOr, &opgThen, &opgAgg, &opSugenoConclusion, &opSugeno);

    ValueModel humidite(0.5);
    ValueModel pression(0.2);

    isTrapezeLeft faible(1, 3);
    isTrapezeRight forte(7, 9);

    isGaussian minime(0, 1.5);
    isGaussian medium(5, 1.5);
    isGaussian elevee(10, 1.5);


    std::vector<Expression*> vectValueModel;
    vectValueModel.push_back(&humidite);
    vectValueModel.push_back(&pression);


    Expression *r1 = f.newThen(
            f.newOr(f.newIs(&faible, &humidite), f.newIs(&minime,&pression)),
            f.newSugenoConclusion(&vectValueModel)
    );

    f.changeSugenoConclusion(&opSugenoConclusion1);

    Expression *r2 = f.newThen(
            f.newIs(&medium,&pression),
            f.newSugenoConclusion(&vectValueModel)
    );

    f.changeSugenoConclusion(&opSugenoConclusion2);
    Expression *r3 = f.newThen(
            f.newOr(f.newIs(&forte, &humidite), f.newIs(&elevee,&pression)),
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
    useCase();
    //useCaseSugeno();
    return 0;
}
