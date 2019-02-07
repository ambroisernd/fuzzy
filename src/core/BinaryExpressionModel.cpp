#include "BinaryExpressionModel.h"
namespace core {
    template<class T>
    T BinaryExpressionModel<T>::evaluate() {
        if (left != nullptr && right != nullptr) {
            return operatore.evaluate(left, right);
        }
    }

    template<class T>
    T BinaryExpressionModel<T>::evaluate(core::Expression<T> l, core::Expression<T> r) {
        if (operatore != nullptr) {
            return operatore.evaluate(l, r);
        }
    }
}