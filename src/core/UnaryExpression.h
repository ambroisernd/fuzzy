//
// Created by Paul on 06/02/2019.
//

#ifndef FUZZY_UNARYEXPRESSION_H
#define FUZZY_UNARYEXPRESSION_H

#include "Expression.h"
namespace core {
    template<class T>
    class UnaryExpression {
    public:
        virtual T evaluate(Expression<T> o) = 0;

    };
}

#endif FUZZY_UNARYEXPRESSION_H
