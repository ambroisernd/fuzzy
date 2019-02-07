#ifndef FUZZY_EXPRESSION_H
#define FUZZY_EXPRESSION_H

namespace core {
    template<class T>
    class Expression {
    public:
        virtual T evaluate() = 0;


    };

}
#endif FUZZY_EXPRESSION_H
