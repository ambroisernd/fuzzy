#ifndef FUZZY_AGGPLUS_H
#define FUZZY_AGGPLUS_H
#include "Agg.h"
namespace fuzzy{
    template <typename T>
    class AggPlus : public Agg<T>{
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;

    };
    template <typename T>
    T AggPlus<T>::evaluate( core::Expression<T> *l, core::Expression<T> *r) const {
        T left = l->evaluate();
        T right = r->evaluate();

        return left+right;

    }
}

#endif //FUZZY_AGGPLUS_H
