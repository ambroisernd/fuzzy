
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
}

#endif FUZZY_UNARYSHADOWEXPRESSION_H
