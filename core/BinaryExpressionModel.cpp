//
// Created by Paul on 07/02/2019.
//

#include "BinaryExpressionModel.h"

template <class T>
T BinaryExpressionModel::evaluate() {
    if(left != null && right != null){
        return operatore.evaluate(l,r);
    }
}

template <class T>
T BinaryExpressionModel::evaluate(Expression l, Expression r) {
    if(operatore != null){
        return operatore.evaluate(l,r);
    }
}