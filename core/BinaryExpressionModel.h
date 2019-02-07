//
// Created by Paul on 07/02/2019.
//

#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"
template <class T>
class BinaryExpressionModel : BinaryExpression {
public:
    virtual T evaluate();
    virtual T evaluate(Expression l, Expression r);

private:
    Expression left;
    Expression right;
    BinaryExpression operatore;
};


#endif FUZZY_BINARYEXPRESSIONMODEL_H
