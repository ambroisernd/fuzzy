#ifndef FUZZY_AGGMAX_H
#define FUZZY_AGGMAX_H
#include "Agg.h"
#include "algorithm"

namespace fuzzy{
    template <typename T>
    class AggMax : public Agg<T>{
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };
    template <typename T>
    T AggMax<T>::evaluate( core::Expression<T> *l, core::Expression<T> *r) const {
        T left = l->evaluate();
        T right = r->evaluate();

        return std::max(left, right);

    }
}
#endif //FUZZY_AGGMAX_H
