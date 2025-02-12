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
#include "is/isBell.h"
#include "is/isGaussian.h"
#include "is/isTrapeze.h"
#include "is/isTrapezeLeft.h"
#include "is/isTrapezeRight.h"
#include "Defuzz/CogDefuzz.h"
#include "Or/OrPlus.h"
#include "Defuzz/BoaDefuzz.h"
#include "Then/SugenoThen.h"
#include "Defuzz/SugenoConclusion.h"
#include "Defuzz/SugenoDefuzz.h"
#include "Defuzz/SomDefuzz.h"

typedef fuzzy::AggMax<NUMERIC> AggMax;
typedef fuzzy::AndMin<NUMERIC> AndMin;
typedef fuzzy::AndMult<NUMERIC> AndMult;
typedef fuzzy::MamdaniDefuzz<NUMERIC> MamdaniDefuzz;
typedef fuzzy::isTriangle<NUMERIC> isTriangle;
typedef fuzzy::isBell<NUMERIC> isBell;
typedef fuzzy::isGaussian<NUMERIC> isGaussian;
typedef fuzzy::isTrapeze<NUMERIC> isTrapeze;
typedef fuzzy::isTrapezeLeft<NUMERIC> isTrapezeLeft;
typedef fuzzy::isTrapezeRight<NUMERIC> isTrapezeRight;
typedef fuzzy::NotMinus1<NUMERIC> NotMinus1;
typedef fuzzy::OrMax<NUMERIC> OrMax;
typedef fuzzy::ThenMin<NUMERIC> ThenMin;
typedef fuzzy::MamdaniDefuzz<NUMERIC> MamdaniDefuzz;
typedef fuzzy::CogDefuzz<NUMERIC> CogDefuzz;
typedef fuzzy::LomDefuzz<NUMERIC> LomDefuzz;
typedef fuzzy::SomDefuzz<NUMERIC> SomDefuzz;
typedef fuzzy::FuzzyFactory<NUMERIC> FuzzyFactory;
typedef fuzzy::AggPlus<NUMERIC> AggPlus;
typedef fuzzy::OrPlus<NUMERIC> OrPlus;
typedef fuzzy::BoaDefuzz<NUMERIC> BoaDefuzz;
typedef fuzzy::SugenoThen<NUMERIC> SugenoThen;
typedef fuzzy::SugenoConclusion<NUMERIC> SugenoConclusion;
typedef fuzzy::SugenoDefuzz<NUMERIC> SugenoDefuzz;

#endif //FUZZY_FUZZY_H
