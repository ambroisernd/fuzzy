#ifndef FUZZY_LOMDEFUZZ_H
#define FUZZY_LOMDEFUZZ_H

#include "MamdaniDefuzz.h"
#include "../Evaluator.h"
namespace fuzzy{
    template <typename T>
    class LomDefuzz : public MamdaniDefuzz<T>{
    private:
    public:
        LomDefuzz(T min, T max, T step);

        T defuzz(typename Evaluator<T>::Shape shape) const;

    };

    template<typename T>
    LomDefuzz<T>::LomDefuzz(T min, T max, T step):MamdaniDefuzz<T>(min, max, step) {}

    template<typename T>
    T LomDefuzz<T>::defuzz(typename Evaluator<T>::Shape shape) const {

        return shape.first.at(shape.first.size());
    }
}

#endif //FUZZY_LOMDEFUZZ_H
