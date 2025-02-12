#ifndef FUZZY_ISGAUSSIAN_H
#define FUZZY_ISGAUSSIAN_H

#include <algorithm>
#include "is.h"
#include <math.h>
namespace fuzzy {
    template <typename T>
    class isGaussian : public is<T> {
    public:
        isGaussian(T _c, T _t);
        virtual T evaluate(core::Expression<T> *o) const;

    private:
        T c;
        T t;

    };


    template <typename T>
    isGaussian<T>::isGaussian(T _c, T _t) : c(_c), t(_t){}

    template <typename T>
    T isGaussian<T>::evaluate(core::Expression<T> *o) const {
        T object = o->evaluate();
        T a = exp(-pow((object-c),2)/(2*pow(t,2)));
        return a;
    }
}
#endif //FUZZY_ISGAUSSIAN_H
