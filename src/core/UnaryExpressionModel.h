#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
namespace core {
    template<typename T>
    class UnaryExpressionModel : public UnaryExpression<T>, Expression<T> {
    public:
        virtual T evaluate() const ;

        virtual T evaluate(Expression<T> *o) const ;

    private:
        UnaryExpression<T> operatore;
        Expression<T> operand;
    };
    template<typename T>
    T UnaryExpressionModel<T>::evaluate() const {
        if (operand != nullptr) {
            return evaluate(operand);
        }
    }

    template<typename T>
    T UnaryExpressionModel<T>::evaluate(Expression<T> *o) const {
        if (operatore != nullptr) {
            return operatore.evaluate(o);
        }

    }
}

#endif //FUZZY_UNARYEXPRESSIONMODEL_H
