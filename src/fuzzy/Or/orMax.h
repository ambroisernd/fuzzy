#ifndef FUZZY_ORMAX_H
#define FUZZY_ORMAX_H

#include "Or.h"

namespace fuzzy {
    template <class T = double>
    class orMax : public Or<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };

    using OrMax = orMax<>;

    template <class T>
    T orMax<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return std::max(l->evaluate() , r->evaluate());
    }
}



#endif //FUZZY_ORMAX_H
