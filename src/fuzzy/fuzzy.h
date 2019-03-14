#ifndef FUZZY_FUZZY_H
#define FUZZY_FUZZY_H
#define NUMERIC double
#include "Agg/AggMax.h"
#include "And/AndMin.h"
#include "And/AndMult.h"
#include "Defuzz/MamdaniDefuzz.h"
#include "is/isTriangle.h"
#include "Not/NotMinus1.h"
#include "Or/OrMax.h"
#include "Then/ThenMin.h"

typedef fuzzy::AggMax<NUMERIC> AggMax;
typedef fuzzy::AndMin<NUMERIC> AndMin;
typedef fuzzy::AndMult<NUMERIC> AndMult;
typedef fuzzy::MamdaniDefuzz<NUMERIC> MamdaniDefuzz;
typedef fuzzy::isTriangle<NUMERIC> isTriangle;
typedef fuzzy::NotMinus1<NUMERIC> NotMinus1;
typedef fuzzy::OrMax<NUMERIC> OrMax;
typedef fuzzy::ThenMin<NUMERIC> ThenMin;

#endif //FUZZY_FUZZY_H
