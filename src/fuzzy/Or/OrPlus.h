#ifndef FUZZY_ORPLUS_H
#define FUZZY_ORPLUS_H
#include "Or.h"

namespace fuzzy {
    template <typename T>
    class OrPlus : public Or<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };


    template <typename T>
    T OrPlus<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        T left = l->evaluate();
        T right = r->evaluate();
        return left+right;
    }
}


#endif //FUZZY_ORPLUS_H
