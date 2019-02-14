#ifndef FUZZY_EXPRESSION_H
#define FUZZY_EXPRESSION_H

namespace core {
    template<typename T>
    class Expression {
    public:
        virtual T evaluate() const = 0;


    };

}
#endif //FUZZY_EXPRESSION_H
