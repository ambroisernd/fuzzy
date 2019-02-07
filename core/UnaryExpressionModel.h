//
// Created by Paul on 07/02/2019.
//

#ifndef FUZZY_UNARYEXPRESSIONMODEL_H
#define FUZZY_UNARYEXPRESSIONMODEL_H

#include "UnaryExpression.h"
template <class T>
class UnaryExpressionModel : public UnaryExpression {
public:
    virtual T evaluate();
    virtual T evaluate(Expression o);

private:
    UnaryExpression operatore;
    Expression operand;
};


#endif FUZZY_UNARYEXPRESSIONMODEL_H
