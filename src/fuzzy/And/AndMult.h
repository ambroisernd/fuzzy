#ifndef FUZZY_ANDMULT_H
#define FUZZY_ANDMULT_H

#include "And.h"

namespace fuzzy {
    template <typename T>
    class AndMult : public And<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };


    template <typename T>
    T AndMult<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        T left = l->evaluate();
        T right = r->evaluate();
        return left*right;
    }
}

#endif
