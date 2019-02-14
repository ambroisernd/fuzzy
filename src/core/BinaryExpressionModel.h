#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"

namespace core {
    template<typename T>
    class BinaryExpressionModel : BinaryExpression<T>, Expression<T> {
    public:
        virtual T evaluate() const ;

        virtual T evaluate(Expression<T> *l, Expression<T> *r) const ;

    private:
        Expression<T> left;
        Expression<T> right;
        BinaryExpression<T> operatore;
    };
}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H
