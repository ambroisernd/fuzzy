
#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {

    template<typename T>
    class UnaryShadowExpression : public UnaryExpression<T> {
    public:
        virtual T evaluate(Expression<T> *o) const ;
    private:
        UnaryExpression<T> target;
    };
    template<typename T>
    T UnaryShadowExpression<T>::evaluate(core::Expression<T> *o) const {
        if(target!= nullptr){
            return target.evaluate(o);
        }
    }
}

#endif //FUZZY_UNARYSHADOWEXPRESSION_H
