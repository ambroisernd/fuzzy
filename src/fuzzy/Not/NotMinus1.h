#ifndef FUZZY_NOTMINUS1_H
#define FUZZY_NOTMINUS1_H

#include "Not.h"

namespace fuzzy{
    template <typename T>
    class NotMinus1 : public Not<T>{
    public:
        virtual T evaluate(core::Expression<T>*) const ;
    };

    template <typename T>
    T NotMinus1<T>::evaluate(core::Expression<T> *o) const {
        T object = o->evaluate();
        return 1.0 - object;
    }
}
#endif //FUZZY_NOTMINUS1_H
