#ifndef FUZZY_SUGENODEFUZZ_H
#define FUZZY_SUGENODEFUZZ_H

#include "../../core/NaryExpression.h"
#include "../Then/SugenoThen.h"

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
        for(typename std::vector<core::Expression<T>*>::iterator it = o->begin();it != o->end();it++){
            T eval = (*it)->evaluate();
            SugenoThen<T> sgThen = (**it);
            denominateur += sgThen->premiseValue();
            numerateur += eval;

        }
        return numerateur/denominateur;
    }



}

#endif //FUZZY_SUGENODEFUZZ_H
