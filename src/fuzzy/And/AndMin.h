#ifndef FUZZY_ANDMIN_H
#define FUZZY_ANDMIN_H

#include "And.h"

namespace fuzzy {
    template <class T>
    class AndMin : public And<T> {
    public:
        virtual T evaluate(core::Expression<T>, core::Expression<T>);

    };

    template <class T>
    T AndMin<T>::evaluate(core::Expression<T> l, core::Expression<T> r) {
        return min(l , r); //TODO
    }
}

#endif FUZZY_ANDMIN_H
