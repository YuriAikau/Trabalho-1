#include <stdio.h>

#include "Converte_Complexos.h"

int main()
{

    Racional_pt re = criaRacional(1,-5);
    Racional_pt im = criaRacional(-3,-2);

    R_Complexo_pt ene1 = R_criaComplexo(re,im);
    R_Complexo_pt sum1;

    LI_Complexo_pt ene2 = LI_criaComplexo(1,3);
    LI_Complexo_pt sum2;

    D_Complexo_pt ene3 = D_criaComplexo(2.0,5.0);
    D_Complexo_pt sum3;

    double d1,d2;

    sum1 = R_divideComplexos(ene1,ene1);

    R_imprimeComplexo(sum1);
    printf("\n");

    R_imprimeComplexo(ene1);

    d1 = R_moduloComplexo(ene1);
    printf("antes da rotacao: %.2f\n", d1);

    R_atribuiNovoAngulo(ene1, 0.5);

    R_imprimeComplexo(ene1);

    d2 = R_moduloComplexo(ene1);
    printf("depois da rotacao: %.2f\n", d2);

    //sum1 = R_somaComplexos(ene1,ene1);
    //sum2 = LI_divideComplexos(ene2,ene2);
    //sum3 = D_multiplicaComplexos(ene3,ene3);

    //LI_imprimeCSV(fp,ene2);

    //R_imprimeComplexo(sum1);
    //LI_imprimeComplexo(sum2);
    //D_imprimeComplexo(sum3);


    destroiRacional(re);
    destroiRacional(im);
    R_destroiComplexo(ene1);
    R_destroiComplexo(sum1);
    LI_destroiComplexo(ene2);
    LI_destroiComplexo(sum2);
    D_destroiComplexo(ene3);
    D_destroiComplexo(sum3);

    return 0;
}