#ifndef FUZZY_SUGENODEFUZZ_H
#define FUZZY_SUGENODEFUZZ_H

#include "../../core/NaryExpression.h"

namespace fuzzy{
    template <typename T>
    class SugenoDefuzz : public core::NaryExpression<T>{
    public:
        virtual T evaluate(std::vector<core::Expression<T>*> *o) const;
    };

    template <typename T>
    T SugenoDefuzz<T>::evaluate(std::vector<core::Expression<T> *> *o) const {
        T numerateur = 0;
        T denominateur = 0;
        for(std::vector<core::Expression<T>*>::iterator it = o->begin();it != o->end();it++){
            eval = *it->evaluate();



        }



        return numerateur/denominateur;
    }



}

#endif //FUZZY_SUGENODEFUZZ_H
