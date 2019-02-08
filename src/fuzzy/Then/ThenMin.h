#ifndef FUZZY_THENMIN_H
#define FUZZY_THENMIN_H
#include "Then.h"

namespace fuzzy {
    template <class T>
    class ThenMin : public Then<T> {
    public:
        virtual T evaluate(core::Expression<T>, core::Expression<T>);

    };

    template <class T>
    T ThenMin<T>::evaluate(core::Expression<T> l, core::Expression<T> r) {
        return min(l , r);
    }
}


#endif
