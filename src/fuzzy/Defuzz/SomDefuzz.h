#ifndef FUZZY_SOMDEFUZZ_H
#define FUZZY_SOMDEFUZZ_H

#include "MamdaniDefuzz.h"
#include "../Evaluator.h"
namespace fuzzy{
    template <typename T>
    class SomDefuzz : public MamdaniDefuzz<T>{
    private:
    public:
        SomDefuzz(T min, T max, T step);

        T defuzz(typename Evaluator<T>::Shape shape) const;

    };

    template<typename T>
    SomDefuzz<T>::SomDefuzz(T min, T max, T step):MamdaniDefuzz<T>(min, max, step) {}

    template<typename T>
    T SomDefuzz<T>::defuzz(typename Evaluator<T>::Shape shape) const {
        T max = shape.second.at(0);
        T fiber = 0;
        for (int i = 0; i < shape.first.size(); i++) {
            if (shape.second.at(i)>max){
                max = shape.second.at(i);
                fiber = shape.first.at(i);
            }
        }
        return fiber;
    }
}

#endif //FUZZY_SOMDEFUZZ_H
