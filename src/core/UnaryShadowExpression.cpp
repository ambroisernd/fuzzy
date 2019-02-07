#include "UnaryShadowExpression.h"
namespace core {

    template<class T>
    T UnaryShadowExpression<T>::evaluate(core::Expression<T> o) {
        if(target!=null){
            return target.evaluate(o);
        }
    }

}