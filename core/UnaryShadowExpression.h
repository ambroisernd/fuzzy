
#ifndef FUZZY_UNARYSHADOWEXPRESSION_H
#define FUZZY_UNARYSHADOWEXPRESSION_H

#include "UnaryExpression.h"
#include "Expression.h"

namespace core {

    template<class T>
    class UnaryShadowExpression : public UnaryExpression {
    public:
        virtual T evaluate(Expression o);
    private:
        UnaryExpression target;
    };
}

#endif FUZZY_UNARYSHADOWEXPRESSION_H
