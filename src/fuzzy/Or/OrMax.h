#ifndef FUZZY_ORMAX_H
#define FUZZY_ORMAX_H

#include "Or.h"

namespace fuzzy {
    template <class T>
    class OrMax : public Or {
        virtual T evaluate(core::Expression, core::Expression);

    };

    template <class T>
    T OrMax<T>::evaluate(core::Expression l, core::Expression r) {
        return max(l , r); //TODO
    }
}



#endif FUZZY_ORMAX_H
