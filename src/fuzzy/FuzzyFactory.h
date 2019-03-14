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

namespace fuzzy{
    template <typename T>
    class FuzzyFactory : public core::ExpressionFactory<T>{
    private:
        core::UnaryShadowExpression<T>* opNot;
        core::BinaryShadowExpression<T>* opAnd;
        core::BinaryShadowExpression<T>* opAgg;
        core::BinaryShadowExpression<T>* opOr;
        core::BinaryShadowExpression<T>* opThen;
        core::BinaryShadowExpression<T>* opMamdani;
    public:
        FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr, Then<T> *opThen, Agg<T> *opAgg);

        core::Expression<T>* newAnd(core::Expression<T>* l, core::Expression<T>* r);
        core::Expression<T>* newOr(core::Expression<T>* l, core::Expression<T>* r);
        core::Expression<T>* newThen(core::Expression<T>* l, core::Expression<T>* r);
        core::Expression<T>* newAgg(core::Expression<T>* l, core::Expression<T>* r);
        core::Expression<T>* newMamdani(core::Expression<T> *l, core::Expression<T> *r);
        core::Expression<T>* newNot(core::Expression<T>* o);
        core::Expression<T>* newIs(fuzzy::is<T>* op, core::Expression<T> * o);

        void changeAnd(And<T> *op);
        void changeOr(Or<T> *op);
        void changeThen(Then<T> *op);
        void changeNot(Not<T> *op);
        void changeAgg(Agg<T> *op);
        void changeMamdani(MamdaniDefuzz<T> *op);
    };

    template<typename T>
    FuzzyFactory<T>::FuzzyFactory(Not<T> *opNot, And<T> *opAnd, Or<T> *opOr, Then<T> *opThen, Agg<T> *opAgg) {}

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newAnd(core::Expression<T> *l, core::Expression<T> *r) {
        return newBinary(opAnd, l, r);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newOr(core::Expression<T> *l, core::Expression<T> *r) {
        return newBinary(opOr, l, r);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newThen(core::Expression<T> *l, core::Expression<T> *r) {
        return newBinary(opThen, l, r);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newNot(core::Expression<T>* o) {
        return newUnary(opNot, o);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newIs(is<T>* op, core::Expression<T> * o) {
        return newUnary(op, o);
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
        return newBinary(opAgg, l, r);
    }

    template<typename T>
    void FuzzyFactory<T>::changeAgg(Agg<T> *op) {
        opAgg->setTarget(op);
    }

    template<typename T>
    core::Expression<T> *FuzzyFactory<T>::newMamdani(core::Expression<T> *l, core::Expression<T> *r) {
        return newBinary(opMamdani, l, r);
    }

    template<typename T>
    void FuzzyFactory<T>::changeMamdani(MamdaniDefuzz<T> *op) {
        opMamdani->setTarget(op);
    }


}
#endif //FUZZY_FUZZYFACTORY_H
