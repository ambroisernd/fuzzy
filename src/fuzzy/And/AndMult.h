#ifndef FUZZY_ANDMULT_H
#define FUZZY_ANDMULT_H

#include "And.h"

namespace fuzzy {
    template <class T>
    class AndMult : public And<T> {
    public:
        virtual T evaluate(core::Expression<T>, core::Expression<T>);

    };

    template <class T>
    T AndMult<T>::evaluate(core::Expression<T> l, core::Expression<T> r) {
        return l*r; //TODO
    }
}

#endif
