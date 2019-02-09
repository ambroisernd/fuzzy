#ifndef FUZZY_VALUEMODEL_H
#define FUZZY_VALUEMODEL_H

#include "Expression.h"
namespace core {
    template<class T = double>
    class ValueModel : public Expression<T> {
    public:

        ValueModel();
        explicit ValueModel(T v);

        virtual T evaluate();

        virtual void setValue(T v);

        ValueModel<T> operator()(T v);
    private:
        T value;
    };

    using Value = ValueModel<>;

    template <class T>
    ValueModel<T>::ValueModel(T v):value(v) {}

    template<class T>
    void ValueModel<T>::setValue(T v) {
        value = v;
    }

    template<class T>
    T ValueModel<T>::evaluate() {
        return value;
    }

    template <class T>
    ValueModel<T> ValueModel<T>::operator()(T v) {
        return ValueModel(v);
    }
}
#endif //FUZZY_VALUEMODEL_H
