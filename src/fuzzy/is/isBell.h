#ifndef FUZZY_ISBELL_H
#define FUZZY_ISBELL_H

#include <algorithm>
#include "is.h"
#include <math.h>
namespace fuzzy {
    template <typename T>
    class isBell : public is<T> {
    public:
        isBell(T _a, T _b, T _c);
        virtual T evaluate(core::Expression<T> *o) const ;

    private:
        T a;
        T b;
        T c;

    };


    template <typename T>
    isBell<T>::isBell(T _a, T _b, T _c) : a(_a), b(_b), c(_c){}

    template <typename T>
    T isBell<T>::evaluate(core::Expression<T> *o) const {
        T object = o->evaluate();
        return 1/(1+pow(abs((object-c)/a),2*b));
    }
}
#endif //FUZZY_ISBELL_H
