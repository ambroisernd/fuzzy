//
// Created by ambroise on 10/02/19.
//

#ifndef FUZZY_ISTRIANGLE_H
#define FUZZY_ISTRIANGLE_H

#include <algorithm>
#include "is.h"
namespace fuzzy {
    template <class T = double>
    class isTriangle : public is<T> {
    public:
        isTriangle(T _left, T _peak, T _right);
        virtual T evaluate(core::Expression<T> *o);
        isTriangle<T> operator()(T left, T peak, T right);

    private:
        T left;
        T peak;
        T right;

    };

    using IsTriangle = isTriangle<>;

    template <class T>
    isTriangle<T>::isTriangle(T _left, T _peak, T _right) : left(_left), peak(_peak), right(_right){}

    template <class T>
    T isTriangle<T>::evaluate(core::Expression<T> *o) {
        return std::max(std::min((o->evaluate()-left)/(peak-left), (right-o->evaluate())/(right-peak),0));
    }

    template <class T>
    isTriangle<T> isTriangle<T>::operator()(T left, T peak, T right) {
        return isTriangle(left, peak, right);
    }
}
#endif //FUZZY_ISTRIANGLE_H
