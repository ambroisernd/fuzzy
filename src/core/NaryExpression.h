#ifndef FUZZY_NARYEXPRESSION_H
#define FUZZY_NARYEXPRESSION_H
#include "Expression.h"
namespace core {
    template <typename T>
    class NaryExpression {
    public:
        virtual T evaluate(std::vector<Expression<T> *> *o) const = 0;
    };
}

#endif //FUZZY_NARYEXPRESSION_H
