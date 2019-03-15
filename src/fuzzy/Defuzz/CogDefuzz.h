#ifndef FUZZY_COGDEFUZZ_H
#define FUZZY_COGDEFUZZ_H

#include "../Evaluator.h"
#include "MamdaniDefuzz.h"
namespace fuzzy{
    template <typename T>
    class CogDefuzz : MamdaniDefuzz<T>{
    private:

        T defuzz(typename Evaluator<T>::Shape shape) const {
            return nullptr;
        }

    public:
    };
}

#endif //FUZZY_COGDEFUZZ_H
