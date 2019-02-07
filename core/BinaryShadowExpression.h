#ifndef FUZZY_BINARYSHADOWEXPRESSION_H
#define FUZZY_BINARYSHADOWEXPRESSION_H

#include "Expression.h"
#include "BinaryExpression.h"

namespace core {
    template <class T>
    class BinaryShadowExpression : public BinaryExpression {
    public:
        virtual T evaluate(Expression l, Expression r);

    private:
        BinaryExpression target;
    };

}
#endif FUZZY_BINARYSHADOWEXPRESSION_H
