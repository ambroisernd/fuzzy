#ifndef FUZZY_NARYSHADOWEXPRESSION_H
#define FUZZY_NARYSHADOWEXPRESSION_H

#include "NaryExpression.h"

namespace core {
    template <typename T>
    class NaryShadowExpression : public NaryExpression<T> {
    public:
        explicit NaryShadowExpression(NaryExpression <T> *target);
        void setTarget(NaryExpression<T> *target);
        virtual T evaluate(std::vector<core::Expression *> *o) const ;

    private:
        NaryExpression<T> * target;

    };
    template<typename T>
    T NaryShadowExpression<T>::evaluate(std::vector<core::Expression<T> *> *o) const {
        if(target!= nullptr){
            return target->evaluate(o);
        }
    }

    template<typename T>
    void NaryShadowExpression<T>::setTarget(NaryExpression<T> *target) {
        NaryShadowExpression::target = target;
    }

    template<typename T>
    NaryShadowExpression<T>::NaryShadowExpression(NaryExpression <T> *target):target(target) {}
}
#endif //FUZZY_NARYSHADOWEXPRESSION_H
