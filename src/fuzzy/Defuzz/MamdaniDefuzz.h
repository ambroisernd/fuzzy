#ifndef FUZZY_MAMDANIDEFUZZ_H
#define FUZZY_MAMDANIDEFUZZ_H

#include "../../core/BinaryExpression.h"
#include "../Evaluator.h"

namespace fuzzy{
    template <typename T>
    class MamdaniDefuzz : public core::BinaryExpression<T>{
    private:
        T min;
        T max;
        T step;

    public:
        MamdaniDefuzz(T min, T max, T step);
        virtual T evaluate(core::Expression<T>* l, core::Expression<T>* r) const;
        virtual T defuzz(typename Evaluator<T>::Shape) const = 0;
    };

    template<typename T>
    T MamdaniDefuzz<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        return defuzz(Evaluator<T>::BuildShape(min, max, step, (core::ValueModel<T>*) l, r));
    }

    template<typename T>
    MamdaniDefuzz<T>::MamdaniDefuzz(T min, T max, T step):min(min), max(max), step(step) {}

}
#endif //FUZZY_MAMDANIDEFUZZ_H
