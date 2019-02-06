//
// Created by Paul on 06/02/2019.
//

#include "ValueModel.h"

template <class T>
void ValueModel<T>::setValue(T v) {
    value = v;
}

template <class T>
T ValueModel<T>::evaluate() {
    return value;
}
