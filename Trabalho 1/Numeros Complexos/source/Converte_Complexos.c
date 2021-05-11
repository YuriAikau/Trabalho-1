#include "Converte_Complexos.h"

LI_Complexo_pt doubleParaInteiro (D_Complexo_pt n){
    LI_Complexo_pt temp = LI_criaComplexo(0,0);

    *temp->real = (int)round(*n->real);
    *temp->imag = (int)round(*n->imag);

    return temp;
}

D_Complexo_pt inteiroParaDouble (LI_Complexo_pt n){
    D_Complexo_pt temp = D_criaComplexo(0,0);

    *temp->real = (double)(*n->real);
    *temp->imag = (double)(*n->imag);

    return temp;
}

R_Complexo_pt doubleParaRacional (D_Complexo_pt n){
    R_Complexo_pt temp;

    *temp->real = dbleParaRacional(*n->real,1048576);
    *temp->imag = dbleParaRacional(*n->imag,1048576);

    return temp;
}

D_Complexo_pt racionalParaDouble (R_Complexo_pt n){
    D_Complexo_pt temp = D_criaComplexo(0.0,0.0);

    *temp->real = racionalParaDble(*n->real);
    *temp->imag = racionalParaDble(*n->imag);

    return temp;
}

LI_Complexo_pt racionalParaInteiro (R_Complexo_pt n){
    LI_Complexo_pt temp = LI_criaComplexo(0,0);

    *temp->real = (int)(round(racionalParaDble(*n->real)));
    *temp->imag = (int)(round(racionalParaDble(*n->imag)));

    return temp;
}

R_Complexo_pt inteiroParaRacional (LI_Complexo_pt n){
    R_Complexo_pt temp;

    *temp->real = criaRacional(*n->real,1);
    *temp->imag = criaRacional(*n->imag,1);

    return temp;
}