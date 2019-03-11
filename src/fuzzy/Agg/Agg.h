#ifndef FUZZY_AGG_H
#define FUZZY_AGG_H
#include "../../core/BinaryExpression.h"

namespace fuzzy{
    template <typename T>
    class Agg : public core::BinaryExpression<T>{
    };
}

#endif //FUZZY_AGG_H
