#ifndef FUZZY_SUGENOCONCLUSION_H
#define FUZZY_SUGENOCONCLUSION_H

#include "../../core/Expression.h"
#include "../../core/NaryExpression.h"

namespace fuzzy{
    template <typename T>
    class SugenoConclusion : public core::NaryExpression<T>{
    public:
        explicit SugenoConclusion(std::vector<T> coeffs);

        virtual T evaluate(std::vector<core::Expression<T>*> *o) const;

    private:
        std::vector<T> coeffs; //size de coeff +1 que taille de o
    };

    template <typename T>
    T SugenoConclusion<T>::evaluate(std::vector<core::Expression<T>*> *o) const{
        T result = 0;
        int i = 0;
        for(std::vector<core::Expression<T>*>::iterator it = o->begin();it != o->end();it++){
            T eval = (it*) -> evaluate();
            T coeff = coeffs.at(i);
            result += coeff * eval;
            i++;
        }
        result += coeffs.at(i);
        return result;

    }

    template <typename T>
    SugenoConclusion<T>::SugenoConclusion(std::vector<T> v):coeffs(v) {}


}

#endif //FUZZY_SUGENOCONCLUSION_H
