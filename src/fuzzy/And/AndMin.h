#ifndef FUZZY_ANDMIN_H
#define FUZZY_ANDMIN_H

#include "And.h"
#include <algorithm>
namespace fuzzy {
    template <class T = double>
    class AndMin : public And<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*);

    };

    using AndMini = AndMin<>;

    template <class T>
    T AndMin<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) {
        return std::min(l->evaluate() , r->evaluate());
    }
}

#endif //FUZZY_ANDMIN_H
