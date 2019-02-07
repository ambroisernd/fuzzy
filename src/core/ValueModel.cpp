#include "ValueModel.h"
namespace core {
    template<class T>
    void ValueModel<T>::setValue(T v) {
        value = v;
    }

    template<class T>
    T ValueModel<T>::evaluate() {
        return value;
    }
}