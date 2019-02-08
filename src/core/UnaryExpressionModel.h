#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
namespace core {
    template<class T>
    class UnaryExpressionModel : public UnaryExpression<T>, Expression<T> {
    public:
        virtual T evaluate();

        virtual T evaluate(Expression<T> o);

    private:
        UnaryExpression<T> operatore;
        Expression<T> operand;
    };
    template<class T>
    T UnaryExpressionModel<T>::evaluate() {
        if (operand != nullptr) {
            return evaluate(operand);
        }
    }

    template<class T>
    T UnaryExpressionModel<T>::evaluate(Expression<T> o) {
        if (operatore != nullptr) {
            return operatore.evaluate(o);
        }

    }
}

#endif //FUZZY_UNARYEXPRESSIONMODEL_H
