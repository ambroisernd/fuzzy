#ifndef FUZZY_UNARYEXPRESSION_H
#define FUZZY_UNARYEXPRESSION_H

#include "Expression.h"
namespace core {
    template<typename T>
    class UnaryExpression {
    public:
        virtual T evaluate(Expression<T> *o) const = 0;

    };
}

#endif //FUZZY_UNARYEXPRESSION_H
