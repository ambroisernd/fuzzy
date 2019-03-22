//
// Created by Gauthier Masini on 18/03/2019.
//

#ifndef FUZZY_SUGENODEFUZZ_H
#define FUZZY_SUGENODEFUZZ_H

#include <algorithm>
#include "Then.h"

namespace fuzzy {
    template <typename T>
    class SugenoThen : public Then<T> {
    public:
        virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const ;
        virtual T premiseValue();

    private:
        T PremiseValue;
    };


    template <typename T>
    T SugenoThen<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        T left = l->evaluate();
        T right = r->evaluate();
        PremiseValue= left + right;
        return PremiseValue;
    }

    template <typename T>
    T SugenoThen<T>::premiseValue() {
        return PremiseValue;
    }
}


#endif //FUZZY_SUGENODEFUZZ_H
