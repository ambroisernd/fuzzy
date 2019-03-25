#ifndef FUZZY_NARYEXPRESSIONMODEL_H
#define FUZZY_NARYEXPRESSIONMODEL_H

#include "NaryExpression.h"
namespace core{
    template <typename T>
    class NaryExpressionModel : public NaryExpression<T>, public Expression<T>{
    public:
        NaryExpressionModel(NaryExpressionModel<T> *op, std::vector<Expression<T> *> *o);

        virtual T evaluate() const;

        virtual T evaluate(std::vector<NaryExpression<T> *> *o) const ;
    private:
        NaryExpression<T>* operatore;
        std::vector<Expression<T>*>* o;
    };


    template<typename T>
    T NaryExpressionModel<T>::evaluate() const {
        if (!o -> empty()) {
            return evaluate(o);
        }
    }

    template<typename T>
    T NaryExpressionModel<T>::evaluate(std::vector<Expression <T>*> *o) const {
        if(operatore != nullptr){
            return operatore->evaluate(o);
        }
    }

    template<typename T>
    NaryExpressionModel<T>::NaryExpressionModel(NaryExpression <T> *operatore, std::vector<Expression<T>*> *o):operatore(operatore), o(o){}
}


#endif //FUZZY_NARYEXPRESSIONMODEL_H
