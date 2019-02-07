
#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {

    template<class T>
    class UnaryShadowExpression : public UnaryExpression<T> {
    public:
        virtual T evaluate(Expression<T> o);
    private:
        UnaryExpression<T> target;
    };
    template<class T>
    T UnaryShadowExpression<T>::evaluate(core::Expression<T> o) {
        if(target!= nullptr){
            return target.evaluate(o);
        }
    }
}

#endif FUZZY_UNARYSHADOWEXPRESSION_H
