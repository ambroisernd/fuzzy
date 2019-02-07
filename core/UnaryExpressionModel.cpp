//
// Created by Paul on 07/02/2019.
//

#include "UnaryExpressionModel.h"

template <class T>
T UnaryExpressionModel::evaluate() {
    if (operand != null) {
        return evaluate(operand);
    }
}

template <class T>
T UnaryExpressionModel::evaluate(Expression o) {
    if(operatore != null){
        return operatore.evaluate(o);
    }

}