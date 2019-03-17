#ifndef FUZZY_ISTRAPEZELEFT_H
#define FUZZY_ISTRAPEZELEFT_H

#include <algorithm>
#include "is.h"
namespace fuzzy {
    template <typename T>
    class isTrapezeLeft : public is<T> {
    public:
        isTrapezeLeft(T _rightshoulder, T _rightfeet);
        virtual T evaluate(core::Expression<T> *o) const ;

    private:
        T rightshoulder;
        T rightfeet;
    };


    template <typename T>
    isTrapezeLeft<T>::isTrapezeLeft(T _rightshoulder, T _rightfeet) : rightshoulder(_rightshoulder), rightfeet(_rightfeet){}

    template <typename T>
    T isTrapezeLeft<T>::evaluate(core::Expression<T> *o) const {
        T object = o->evaluate();
        return std::max(
                std::min((T)1, (rightfeet-object)/(rightfeet-rightshoulder))
                ,(T)0);
    }
}
#endif //FUZZY_ISTRAPEZELEFT_H
