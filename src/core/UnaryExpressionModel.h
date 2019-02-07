#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
namespace core {
    template<class T>
    class UnaryExpressionModel : public UnaryExpression<T> {
    public:
        virtual T evaluate();

        virtual T evaluate(Expression<T> o);

    private:
        UnaryExpression<T> operatore;
        Expression<T> operand;
    };
}

#endif FUZZY_UNARYEXPRESSIONMODEL_H
