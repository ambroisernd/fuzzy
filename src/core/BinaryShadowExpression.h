#ifndef FUZZY_BINARYSHADOWEXPRESSION_H
#define FUZZY_BINARYSHADOWEXPRESSION_H

#include "Expression.h"
#include "BinaryExpression.h"

namespace core {
    template <typename T>
    class BinaryShadowExpression : public BinaryExpression<T> {
    public:
        virtual T evaluate(Expression<T> *l, Expression<T> *r) const ;

    private:
        BinaryExpression<T> * target;
    public:
        void setTarget(const BinaryExpression<T> *target);
    };
    template<typename T>
    T BinaryShadowExpression<T>::evaluate(core::Expression<T> *l, core::Expression<T> *r) const {
        if(target!= nullptr){
            return target->evaluate(l,r);
        }
    }

    template<typename T>
    void BinaryShadowExpression<T>::setTarget(const BinaryExpression<T> *target) {
        BinaryShadowExpression::target = target;
    }
}
#endif //FUZZY_BINARYSHADOWEXPRESSION_H
