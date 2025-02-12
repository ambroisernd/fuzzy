#ifndef FUZZY_ANDMIN_H
#define FUZZY_ANDMIN_H

#include "And.h"
#include <algorithm>
namespace fuzzy {
    template <typename T>
    class AndMin : public And<T> {
    public:
        virtual T evaluate( core::Expression<T>*, core::Expression<T>*) const ;

    };


    template <typename T>
    T AndMin<T>::evaluate( core::Expression<T> *l, core::Expression<T> *r) const {
        T left = l->evaluate();
        T right = r->evaluate();
        return std::min(left , right);
    }
}

#endif //FUZZY_ANDMIN_H
