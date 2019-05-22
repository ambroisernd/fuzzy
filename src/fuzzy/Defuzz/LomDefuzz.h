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
        T max = shape.second.at(0);
        T fiber = 0;
        for (int i = 0; i < shape.first.size(); i++) {
            if (shape.second.at(i)>=max){
                max = shape.second.at(i);
                fiber = shape.first.at(i);
            }
        }
        return fiber;
    }
}

#endif //FUZZY_LOMDEFUZZ_H
