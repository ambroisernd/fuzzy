#ifndef FUZZY_THENMIN_H
#define FUZZY_THENMIN_H

#include <algorithm>
#include "Then.h"

namespace fuzzy {
    template <typename T>
    class ThenMin : public Then<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };


    template <typename T>
    T ThenMin<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        T left = l->evaluate();
        T right = r->evaluate();
        return std::min(left , right);
    }
}


#endif
