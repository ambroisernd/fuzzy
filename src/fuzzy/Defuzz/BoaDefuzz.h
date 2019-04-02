#ifndef FUZZY_BOADEFUZZ_H
#define FUZZY_BOADEFUZZ_H

#include "MamdaniDefuzz.h"
namespace fuzzy{
    template <typename T>
    class BoaDefuzz : public MamdaniDefuzz<T>{
    private:
    public:
        BoaDefuzz(T min, T max, T step);

        T defuzz(typename Evaluator<T>::Shape shape) const;

    };

    template<typename T>
    BoaDefuzz<T>::BoaDefuzz(T min, T max, T step):MamdaniDefuzz<T>(min, max, step) {}

    template<typename T>
    T BoaDefuzz<T>::defuzz(typename Evaluator<T>::Shape shape) const {
        int start = 0;


        do {
            T left = 0;
            T right = 0;
            for (int i = 0; i <= start; i++) {
                left += shape.second.at(i);
            }
            for (int j = (shape.first.size() - 1); j >= start; j--) {
                right += shape.second.at(j);
            }
            if (left>right){
                return (2*shape.first.at(start)+1)/2;
            }
            else if(left==right){
                return shape.first.at(start);
            }
            start++;
        }while (start<shape.first.size());

        return shape.first.at(start);
    }
}

#endif //FUZZY_BOADEFUZZ_H
