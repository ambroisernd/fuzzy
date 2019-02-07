//
// Created by Paul on 06/02/2019.
//

#ifndef FUZZY_VALUEMODEL_H
#define FUZZY_VALUEMODEL_H

namespace core {
    template<class T>
    class ValueModel : public Expression {
    public:
        virtual T evaluate();

        virtual void setValue(T v);


    private:
        T value;
    };

}
#endif FUZZY_VALUEMODEL_H
