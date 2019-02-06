//
// Created by Paul on 06/02/2019.
//

#ifndef FUZZY_BINARYEXPRESSION_H
#define FUZZY_BINARYEXPRESSION_H

#include "Expression.h"

<template class T>
class BinaryExpression {
public:
    virtual T evaluate(Expression l, Expression r) =0;

};


#endif FUZZY_BINARYEXPRESSION_H
