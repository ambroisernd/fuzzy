#ifndef FUZZY_ANDMIN_H
#define FUZZY_ANDMIN_H

#include "And.h"
#include "Expression.h"

namespace fuzzy {
    template <class T>
    class AndMin : public And {
    public:
        virtual T evaluate(core::Expression, core::Expression);

    };

    template <class T>
    T AndMin<T>::evaluate(core::Expression l, core::Expression r) {
        return min(l , r);
    }
}

#endif FUZZY_ANDMIN_H
