
#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {

    template<typename T>
    class UnaryShadowExpression : public UnaryExpression<T> {
    public:
        explicit UnaryShadowExpression(UnaryExpression <T> *target );

        virtual T evaluate(Expression<T> *o) const ;
    private:
        UnaryExpression<T>* target;
    public:
        void setTarget(const UnaryExpression<T> *target);
    };
    template<typename T>
    T UnaryShadowExpression<T>::evaluate(core::Expression<T> *o) const {
        if(target!= nullptr){
            return target->evaluate(o);
        }
    }

    template<typename T>
    void UnaryShadowExpression<T>::setTarget(const UnaryExpression<T> *target) {
        UnaryShadowExpression::target = target;
    }

    template<typename T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression <T> *target):target(target) {}
}

#endif //FUZZY_UNARYSHADOWEXPRESSION_H
