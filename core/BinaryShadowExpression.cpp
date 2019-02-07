#include "BinaryShadowExpression.h"

namespace core {

    template<class T>
    T BinaryShadowExpression::evaluate(core::Expression l, core::Expression r) {
        if(target!=null){
            return target.evaluate(l,r);
        }
    }

}