#ifndef FUZZY_ISTRAPEZERIGHT_H
#define FUZZY_ISTRAPEZERIGHT_H

#include <algorithm>
#include "is.h"
namespace fuzzy {
    template <typename T>
    class isTrapezeRight : public is<T> {
    public:
        isTrapezeRight(T _leftfeet, T _leftshoulder);
        virtual T evaluate(core::Expression<T> *o) const ;

    private:
        T leftfeet;
        T leftshoulder;
    };


    template <typename T>
    isTrapezeRight<T>::isTrapezeRight(T _leftfeet, T _leftshoulder) : leftfeet(_leftfeet), leftshoulder(_leftshoulder){}

    template <typename T>
    T isTrapezeRight<T>::evaluate(core::Expression<T> *o) const {
        T object = o->evaluate();
        return std::max(
                std::min((object-leftfeet)/(leftshoulder-leftfeet), (T)1)
                ,(T)0);
    }
}
#endif //FUZZY_ISTRAPEZERIGHT_H
