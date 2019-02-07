#include "UnaryShadowExpression.h"
namespace core {

    template<class T>
    T UnaryShadowExpression<T>::evaluate(core::Expression<T> o) {
        if(target!= nullptr){
            return target.evaluate(o);
        }
    }

}