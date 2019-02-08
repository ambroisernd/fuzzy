#ifndef FUZZY_ORMAX_H
#define FUZZY_ORMAX_H

#include "Or.h"

namespace fuzzy {
    template <class T>
    class OrMax : public Or<T> {
        virtual T evaluate(core::Expression<T>, core::Expression<T>);

    };

    template <class T>
    T OrMax<T>::evaluate(core::Expression<T> l, core::Expression<T> r) {
        return max(l , r); //TODO
    }
}



#endif FUZZY_ORMAX_H
