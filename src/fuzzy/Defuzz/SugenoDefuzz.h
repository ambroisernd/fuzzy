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
            auto *binModel = (core::BinaryExpressionModel<T> *)(*it);
            auto *binShadow = (core::BinaryShadowExpression<T> *)(binModel->getOperatore());
            auto *sgThen = (fuzzy::SugenoThen<T> *)(binShadow->getTarget());

            numerateur += (*it)->evaluate();
            denominateur += sgThen->premiseValue();
        }
        return numerateur/denominateur;
    }



}

#endif //FUZZY_SUGENODEFUZZ_H
