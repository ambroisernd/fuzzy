#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
namespace core {
    template<class T>
    class BinaryExpressionModel : BinaryExpression<T> {
    public:
        virtual T evaluate();

        virtual T evaluate(Expression<T> l, Expression<T> r);

    private:
        Expression<T> left;
        Expression<T> right;
        BinaryExpression<T> operatore;
    };
}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H
