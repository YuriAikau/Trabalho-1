#ifndef CONVCOMPLEXOS_H_INCLUDED
#define CONVCOMPLEXOS_H_INCLUDED

#include "Complexos_Double.h"
#include "Complexos_LongInt.h"
#include "Complexos_Racionais.h"

LI_Complexo_pt doubleParaInteiro (D_Complexo_pt n);

D_Complexo_pt inteiroParaDouble (LI_Complexo_pt n);

R_Complexo_pt doubleParaRacional (D_Complexo_pt n);

D_Complexo_pt racionalParaDouble (R_Complexo_pt n);

LI_Complexo_pt racionalParaInteiro (R_Complexo_pt n);

R_Complexo_pt inteiroParaRacional (LI_Complexo_pt n);

#endif