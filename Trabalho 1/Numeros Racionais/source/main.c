#include <stdio.h>

#include "Racionais.h"

int main(){
    Racional_pt a = criaRacional(1,3);
    Racional_pt t;
    double c = 7.0;
    FILE *fp;

    //imprimeEmCSV(fp,a);
    t = leCSV(fp,7);
    
    imprimeRacional(t);

    printf("\n");

    destroiRacional(a);
    destroiRacional(t);

    return 0;
}