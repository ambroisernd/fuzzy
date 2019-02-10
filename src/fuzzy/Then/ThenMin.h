#ifndef FUZZY_THENMIN_H
#define FUZZY_THENMIN_H

#include <algorithm>
#include "Then.h"

namespace fuzzy {
    template <class T = double>
    class ThenMin : public Then<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };

    using ThenMini = ThenMin<>;

    template <class T>
    T ThenMin<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return std::min(l->evaluate() , r->evaluate());
    }
}


#endif
