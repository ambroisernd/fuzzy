#ifndef FUZZY_ISTRAPEZE_H
#define FUZZY_ISTRAPEZE_H

#include <algorithm>
#include "is.h"
namespace fuzzy {
    template <typename T>
    class isTrapeze : public is<T> {
    public:
        isTrapeze(T _leftfeet, T _leftshoulder, T _rightshoulder, T _rightfeet);
        virtual T evaluate(core::Expression<T> *o) const ;

    private:
        T leftfeet;
        T leftshoulder;
        T rightshoulder;
        T rightfeet;
    };


    template <typename T>
    isTrapeze<T>::isTrapeze(T _leftfeet, T _leftshoulder, T _rightshoulder, T _rightfeet) : leftfeet(_leftfeet), leftshoulder(_leftshoulder), rightshoulder(_rightshoulder), rightfeet(_rightfeet){}

    template <typename T>
    T isTrapeze<T>::evaluate(core::Expression<T> *o) const {
        T object = o->evaluate();
        return std::max(
                std::min(std::min((object-leftfeet)/(leftshoulder-leftfeet), (T)1), (rightfeet-object)/(rightfeet-rightshoulder))
                ,(T)0);
    }
}
#endif //FUZZY_ISTRAPEZE_H
