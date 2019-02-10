#ifndef FUZZY_ANDMULT_H
#define FUZZY_ANDMULT_H

#include "And.h"

namespace fuzzy {
    template <class T = double>
    class andMult : public And<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };

    using AndMult = andMult<>;

    template <class T>
    T andMult<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return l->evaluate()*r->evaluate();
    }
}

#endif
