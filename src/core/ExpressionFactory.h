#ifndef FUZZY_EXPRESSIONFACTORY_H
#define FUZZY_EXPRESSIONFACTORY_H
#include "Expression.h"
#include "UnaryExpression.h"
#include "BinaryExpression.h"
#include "UnaryExpressionModel.h"
#include "BinaryExpressionModel.h"
#include <set>
namespace core{
    template <typename T>
    class ExpressionFactory : public Expression<T>{
    private:
        std::set<Expression<T>*> memory;
    public:
        virtual ~ExpressionFactory();

        Expression<T>* Hold(Expression<T>*);
        Expression<T>* newUnary(UnaryExpression<T>* ope, Expression<T>* o);
        Expression<T>* newBinary(BinaryExpression<T> * ope, Expression<T>* l, Expression<T>* r);
    };
    template <typename T>
    Expression<T>* ExpressionFactory<T>::Hold(core::Expression<T> * o) {
        memory.insert(o);
        return o;
    }
    template <typename T>
    Expression<T>* ExpressionFactory<T>::newUnary(core::UnaryExpression<T> *ope, core::Expression<T> *o) {
        return hold(new UnaryExpressionModel<T>(ope, o));
    }
    template <typename T>
    Expression<T>* ExpressionFactory<T>::newBinary(core::BinaryExpression<T> *ope, core::Expression<T> *l,
                                                   core::Expression<T> *r) {
        return hold(new BinaryExpressionModel<T>(ope, l, r));
    }

    template<typename T>
    ExpressionFactory<T>::~ExpressionFactory() {
        for (Expression<T> o : this->memory) {
            delete(o);
        }
    }
}
#endif //FUZZY_EXPRESSIONFACTORY_H
