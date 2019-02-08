#include <iostream>
#define ASSERT_ON
#include "test.h"
#include "core/ValueModel.h"
#include "fuzzy/And/AndMin.h"
using namespace core;
using namespace fuzzy;
void valueModelTest()
{
    std::cout  << "set test" << std::endl;
    Value v;
    v.setValue(5);
    ASSERT(v.evaluate() == 5);
}

int main() {
    valueModelTest();
    AndMin<bool> a;
    ValueModel<bool> *t = new ValueModel<bool>();
    t->setValue(true);
    ValueModel<bool> *f = new ValueModel<bool>();
    f->setValue(false);
    std::cout<< a.evaluate(t, f) << std::endl;
    return 0;
}