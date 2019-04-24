#ifndef FUZZY_NARYEXPRESSION_H
#define FUZZY_NARYEXPRESSION_H
#include "Expression.h"
#include <stdlib.h>
#include <vector>
namespace core {
    template <typename T>
    class NaryExpression {
    public:
        virtual T evaluate(std::vector<Expression<T> *> *o) const = 0;
    };
}

#endif //FUZZY_NARYEXPRESSION_H
