#ifndef FUZZY_BINARYSHADOWEXPRESSION_H
#define FUZZY_BINARYSHADOWEXPRESSION_H

#include "Expression.h"
#include "BinaryExpression.h"

namespace core {
    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T> {
    public:
        virtual T evaluate(Expression<T> l, Expression<T> r);

    private:
        BinaryExpression<T> target;
    };

}
#endif FUZZY_BINARYSHADOWEXPRESSION_H
