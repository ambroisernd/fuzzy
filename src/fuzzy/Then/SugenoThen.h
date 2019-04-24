#ifndef FUZZY_SUGENOTHEN_H
#define FUZZY_SUGENOTHEN_H

#include <algorithm>
#include "Then.h"

namespace fuzzy {
    template <typename T>
    class SugenoThen : public Then<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;
        virtual T premiseValue() const;

    private:
        T PremiseValue;
    };


    template <typename T>
    T SugenoThen<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        T left = l->evaluate();
        T right = r->evaluate();
        PremiseValue= left;
        return left*right;
    }

    template <typename T>
    T SugenoThen<T>::premiseValue() const{
        return PremiseValue;
    }
}


#endif //FUZZY_SUGENOTHEN_H
