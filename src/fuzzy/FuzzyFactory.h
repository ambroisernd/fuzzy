#ifndef FUZZY_FUZZYFACTORY_H
#define FUZZY_FUZZYFACTORY_H
#include "../core/ExpressionFactory.h"
#include "Not/Not.h"
#include "And/And.h"
#include "Or/Or.h"
#include "Then/Then.h"
#include "is/is.h"
#include "../core/BinaryShadowExpression.h"
#include "../core/UnaryShadowExpression.h"
#include "Agg/Agg.h"
#include "Defuzz/MamdaniDefuzz.h"
#include "Defuzz/SugenoDefuzz.h"
#include "Defuzz/SugenoConclusion.h"
#include "../core/NaryExpression.h"
#include "../core/NaryShadowExpression.h"

namespace fuzzy{
    template <typename T>
    class FuzzyFactory : public core::ExpressionFactory<T>{
    private:
        core::UnaryShadowExpression<T> opNot;
        core::BinaryShadowExpression<T> opAnd;
        core::BinaryShadowExpression<T> opAgg;
        core::BinaryShadowExpression<T> opOr;
        core::BinaryShadowExpression<T> opThen;
        core::BinaryShadowExpression<T> opMamdani;
        core::NaryShadowExpression<T> opSugeno;
        core::NaryShadowExpression<T> opSugenoConclusion;
    public:
        FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr,
                     Then<T> *opThen, Agg<T> *opAgg, MamdaniDefuzz<T> *opMamdani);
        FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr,
                     Then<T> *opThen, Agg<T> *opAgg, SugenoConclusion<T> * opSugenoConclusion, SugenoDefuzz<T>* opSugeno);

        core::Expression<T>* newAnd(core::Expression<T>* l, core::Expression<T>* r);
        core::Expression<T>* newOr(core::Expression<T>* l, core::Expression<T>* r);
        core::Expression<T>* newThen(core::Expression<T>* l, core::Expression<T>* r);
        core::Expression<T>* newAgg(core::Expression<T>* l, core::Expression<T>* r);
        core::Expression<T>* newMamdani(core::Expression<T> *l, core::Expression<T> *r);
        core::Expression<T>* newNot(core::Expression<T>* o);
        core::Expression<T>* newIs(fuzzy::is<T>* op, core::Expression<T> * o);
        core::Expression<T>* newSugeno(std::vector<core::Expression<T>*> *o);
        core::Expression<T>* newSugenoConclusion(std::vector<core::Expression<T>*> *o);
        void changeAnd(And<T> *op);
        void changeOr(Or<T> *op);
        void changeThen(Then<T> *op);
        void changeNot(Not<T> *op);
        void changeAgg(Agg<T> *op);
        void changeMamdani(MamdaniDefuzz<T> *op);
        void changeSugeno(SugenoDefuzz<T> *op);
        void changeSugenoConclusion(SugenoConclusion<T> *op);

    };

    template<typename T>
    FuzzyFactory<T>::FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr,
                                  Then<T> *opThen, Agg<T> *opAgg, SugenoConclusion<T> *opSugenoConclusion, SugenoDefuzz<T>* opSugeno)
            :opNot(opNot), opAnd(opAnd), opOr(opOr), opThen(opThen), opAgg(opAgg), opSugenoConclusion(opSugenoConclusion), opSugeno(opSugeno), opMamdani(NULL) {}

    template<typename T>
    FuzzyFactory<T>::FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr,
                                  Then<T> *opThen, Agg<T> *opAgg, MamdaniDefuzz<T> *opMamdani)
            :opNot(opNot), opAnd(opAnd), opOr(opOr), opThen(opThen), opAgg(opAgg), opMamdani(opMamdani), opSugeno(NULL), opSugenoConclusion(NULL) {}


    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newAnd(core::Expression<T> *l, core::Expression<T> *r) {
        return core::ExpressionFactory<T>::newBinary(&opAnd, l, r);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newOr(core::Expression<T> *l, core::Expression<T> *r) {
        return core::ExpressionFactory<T>::newBinary(&opOr, l, r);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newThen(core::Expression<T> *l, core::Expression<T> *r) {
        return core::ExpressionFactory<T>::newBinary(&opThen, l, r);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newNot(core::Expression<T>* o) {
        return core::ExpressionFactory<T>::newUnary(&opNot, o);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newIs(is<T>* op, core::Expression<T> * o) {
        return core::ExpressionFactory<T>::newUnary(op, o);
    }

    template<typename T>
    void FuzzyFactory<T>::changeAnd(And<T> *op) {
        opAnd->setTarget(op);
    }

    template<typename T>
    void FuzzyFactory<T>::changeOr(Or<T> *op) {
        opOr->setTarget(op);
    }

    template<typename T>
    void FuzzyFactory<T>::changeThen(Then<T> *op) {
        opThen->setTarget(op);
    }

    template<typename T>
    void FuzzyFactory<T>::changeNot(Not<T> *op) {
        opNot->setTarget(op);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newAgg(core::Expression<T> *l, core::Expression<T> *r) {
        return core::ExpressionFactory<T>::newBinary(&opAgg, l, r);
    }

    template<typename T>
    void FuzzyFactory<T>::changeAgg(Agg<T> *op) {
        opAgg->setTarget(op);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newMamdani(core::Expression<T> *l, core::Expression<T> *r) {
        return core::ExpressionFactory<T>::newBinary(&opMamdani, l, r);
    }

    template<typename T>
    void FuzzyFactory<T>::changeMamdani(MamdaniDefuzz<T> *op) {
        opMamdani->setTarget(op);
    }


    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newSugeno(vector<core::Expression<T> *> *o) {
        return newNary(&opSugeno, o);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newSugenoConclusion(vector<core::Expression<T> *> *o) {
        return newNary(&opSugenoConclusion, o);
    }

    template<typename T>
    void FuzzyFactory<T>::changeSugenoConclusion(SugenoConclusion<T> *op) {
        opSugenoConclusion.setTarget(op);
    }

    template<typename T>
    void FuzzyFactory<T>::changeSugeno(SugenoDefuzz<T> *op) {
        opSugeno.setTarget(op);
    }

}
#endif //FUZZY_FUZZYFACTORY_H
