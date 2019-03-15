#ifndef FUZZY_COGDEFUZZ_H
#define FUZZY_COGDEFUZZ_H

#include "../Evaluator.h"
#include "MamdaniDefuzz.h"
namespace fuzzy{
    template <typename T>
    class CogDefuzz : public MamdaniDefuzz<T>{
    private:

    public:

        CogDefuzz(T min, T max, T step);

        T defuzz(typename Evaluator<T>::Shape shape) const ;
    };

    template<typename T>
    T CogDefuzz<T>::defuzz(typename Evaluator<T>::Shape shape) const {
        T fiber;
        T image;
        T num = 0 ;
        T denom = 0;
        for (int i = 0; i < shape.first.size() ; ++i) {
            fiber = shape.first.at(i);
            image = shape.second.at(i);
            num += image*fiber;
            denom += image;
        }
        return num/denom;
    }

    template<typename T>
    CogDefuzz<T>::CogDefuzz(T min, T max, T step):MamdaniDefuzz<T>(min, max, step) {}
}

#endif //FUZZY_COGDEFUZZ_H
