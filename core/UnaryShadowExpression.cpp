#include "UnaryShadowExpression.h"
namespace core {

    template<class T>
    T UnaryShadowExpression::evaluate(core::Expression o) {
        if(target!=null){
            return target.evaluate(o);
        }
    }

}