#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

#include "../../core/BinaryExpression.h"

namespace fuzzy{
    template <typename T>
    class MamdaniDefuzz : core::BinaryExpression<T>{
    private:

    public:
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r);
        virtual T defuzz();
    };

}
#endif //FUZZY_MAMDANIDEFUZZ_H
