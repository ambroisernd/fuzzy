#ifndef FUZZY_NOT_H
#define FUZZY_NOT_H
#include "../../core/UnaryExpression.h"

namespace fuzzy{
    template <typename T>
    class Not : public core::UnaryExpression<T>{

    };
}

#endif //FUZZY_NOT_H
