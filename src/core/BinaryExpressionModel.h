#ifndef FUZZY_BINARYEXPRESSIONMODEL_H
#define FUZZY_BINARYEXPRESSIONMODEL_H

#include "BinaryExpression.h"

namespace core {
    template<typename T>
    class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {
    public:
        BinaryExpressionModel(BinaryExpression <T> *operatore, Expression <T> *left, Expression <T> *right);

        virtual T evaluate() const ;

        virtual T evaluate(Expression<T> *l, Expression<T> *r) const ;

        BinaryExpression <T> *getOperatore() const;

    private:
        BinaryExpression<T>* operatore;
        Expression<T>* left;
        Expression<T>* right;

    };

    template<typename T>
    T BinaryExpressionModel<T>::evaluate() const {
        if (left !=nullptr && right!=nullptr) {
            return evaluate(left, right);
        }
    }

    template<typename T>
    BinaryExpression <T> *BinaryExpressionModel<T>::getOperatore() const {
        return operatore;
    }

    template<typename T>
    T BinaryExpressionModel<T>::evaluate(Expression <T> *l, Expression <T> *r) const {
        if(operatore != nullptr){
            return operatore->evaluate(l, r);
        }
    }

    template<typename T>
    BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression <T> *operatore, Expression <T> *left,
                                                    Expression <T> *right):operatore(operatore), left(left),
                                                                           right(right) {}
}

#endif //FUZZY_BINARYEXPRESSIONMODEL_H
