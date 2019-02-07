#ifndef FUZZY_VALUEMODEL_H
#define FUZZY_VALUEMODEL_H

#include "Expression.h"
namespace core {
    template<class T>
    class ValueModel : public Expression<T> {
    public:
        virtual T evaluate();

        virtual void setValue(T v);


    private:
        T value;
    };

}
#endif FUZZY_VALUEMODEL_H
