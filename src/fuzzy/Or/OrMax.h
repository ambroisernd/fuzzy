#ifndef FUZZY_ORMAX_H
#define FUZZY_ORMAX_H

#include "Or.h"

namespace fuzzy {
    template <typename T>
    class OrMax : public Or<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };


    template <typename T>
    T OrMax<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        T left = l->evaluate();
        T right = r->evaluate();
        return std::max(left , right);
    }
}



#endif //FUZZY_ORMAX_H
