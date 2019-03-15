#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"

namespace core {
    template<typename T>
    class BinaryExpressionModel : public BinaryExpression<T>, Expression<T> {
    public:
        virtual T evaluate() const ;

        virtual T evaluate(Expression<T> *l, Expression<T> *r) const ;

    private:
        Expression<T> left;
        Expression<T> right;
        BinaryExpression<T> operatore;
    };

    template<typename T>
    T BinaryExpressionModel<T>::evaluate() const {
        if(operatore != nullptr){
            return operatore.evaluate(left, right);
        }
    }

    template<typename T>
    T BinaryExpressionModel<T>::evaluate(Expression <T> *l, Expression <T> *r) const {
        if (left !=nullptr && right!=nullptr) {
            return evaluate(left, right);
        }
    }
}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H
