//
// Created by ambroise on 10/02/19.
//

#ifndef FUZZY_ISTRIANGLE_H
#define FUZZY_ISTRIANGLE_H

#include <algorithm>
#include "is.h"
namespace fuzzy {
    template <typename T>
    class isTriangle : public is<T> {
    public:
        isTriangle(T _left, T _peak, T _right);
        virtual T evaluate(core::Expression<T> *o) const ;

    private:
        T left;
        T peak;
        T right;

    };


    template <typename T>
    isTriangle<T>::isTriangle(T _left, T _peak, T _right) : left(_left), peak(_peak), right(_right){}

    template <typename T>
    T isTriangle<T>::evaluate(core::Expression<T> *o) const {
        return std::max(
                std::min((o->evaluate()-left)/(peak-left), (right-o->evaluate())/(right-peak))
                ,(T)0);
    }
}
#endif //FUZZY_ISTRIANGLE_H
