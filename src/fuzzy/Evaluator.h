//
// Created by Ambroise Renaud on 2019-03-14.
//

#ifndef FUZZY_EVALUATOR_H
#define FUZZY_EVALUATOR_H
#include <vector>
#include "../core/ValueModel.h"

namespace fuzzy{
    using namespace std;
    template <class T> class Evaluator
    {
    public:
        class EvalFunc {
        public:
            virtual T operator () (const T&)=0;
        };
        typedef pair<vector<T>,vector<T> > Shape;
        static Shape BuildShape(const T& min, const T& max, const T& step, core::ValueModel<T> *in, core::Expression<T> * out);
    };
    template <class T>
    typename Evaluator<T>::Shape Evaluator<T>:: BuildShape(const T& min, const T& max, const T& step, core::ValueModel<T> *in, core::Expression<T> * out) {
        vector<T> x, y;
        for (T i= min ;i <= max ;i += step) {
            in->setValue(i);
            y.push_back(out->evaluate());
            x.push_back(i);
        }
        return Shape(x,y);

    }
}
#endif //FUZZY_EVALUATOR_H
