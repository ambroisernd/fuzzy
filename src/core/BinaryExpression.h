#ifndef FUZZY_BINARYEXPRESSION_H
#define FUZZY_BINARYEXPRESSION_H

#include "Expression.h"
namespace core{

    template <class T>
    class BinaryExpression {
    public:
        virtual T evaluate(core::Expression<T> *l, core::Expression<T> *r) const = 0;

    };
}

#endif //FUZZY_BINARYEXPRESSION_H
