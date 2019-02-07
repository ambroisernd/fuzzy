#include "BinaryShadowExpression.h"

namespace core {

    template<class T>
    T BinaryShadowExpression<T>::evaluate(core::Expression<T> l, core::Expression<T> r) {
        if(target!=null){
            return target.evaluate(l,r);
        }
    }

}