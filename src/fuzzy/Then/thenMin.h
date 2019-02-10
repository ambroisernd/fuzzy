#ifndef FUZZY_THENMIN_H
#define FUZZY_THENMIN_H

#include <algorithm>
#include "Then.h"

namespace fuzzy {
    template <class T = double>
    class thenMin : public Then<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };

    using ThenMin = thenMin<>;

    template <class T>
    T thenMin<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return std::min(l->evaluate() , r->evaluate());
    }
}


#endif
