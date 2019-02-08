#ifndef FUZZY_VALUEMODEL_H
#define FUZZY_VALUEMODEL_H

#include "Expression.h"
namespace core {
    template<class T = double>
    class ValueModel : public Expression<T> {
    public:
        virtual T evaluate();

        virtual void setValue(T v);


    private:
        T value;
    };

    using Value = ValueModel<>;

    template<class T>
    void ValueModel<T>::setValue(T v) {
        value = v;
    }

    template<class T>
    T ValueModel<T>::evaluate() {
        return value;
    }
}
#endif //FUZZY_VALUEMODEL_H
