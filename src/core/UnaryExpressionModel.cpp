//
// Created by Paul on 07/02/2019.
//

#include "UnaryExpressionModel.h"
namespace core {
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