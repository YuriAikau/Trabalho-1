#include <stdio.h>

#include "Vetores_Double.h"
#include "Vetores_Inteiros.h"
#include "Vetores_ComplexosDbl.h"
#include "Vetores_ComplexosInt.h"

int main()
{
    //VD_Vetor_pt vetorInt = VD_criaVetor();
    VC_I_Vetor_pt vetorComp = VC_I_criaVetor();
    //VC_I_Vetor_pt somaComp = VC_I_criaVetor(); 

    int i, j = 5;

    for (i = 0; i < 6; i++){
        vetorComp->vet[i] = I_criaComplexo(i,j);
        vetorComp->nAtual += 1;
        vetorComp->indice = i;

        VC_I_realocaVetor(vetorComp);
        j--;
    }

    float x = VC_I_medianaVetor(vetorComp);

    printf("%.2f\n", x);

    /*
    for(i = 0; i < vetorComp->nAtual; i++){
        I_imprimeComplexo(vetorComp->vet[i]);
    }
    printf("\n");
    */

    /*somaComp = VC_I_somaVetores(vetorComp,vetorComp);

    for(i = 0; i < somaComp->nAtual; i++){
        I_imprimeComplexo(somaComp->vet[i]);
    }
    printf("\n");
    */
    /*
    for (i = 0; i < 6; i++){
        vetorInt->vet[i] = (double)j-(double)i;
        vetorInt->nAtual += 1;
        vetorInt->indice = i;

        VD_realocaVetor(vetorInt);
        j--;
    }

    for(i = 0; i < vetorInt->nAtual; i++){
        printf("%.2f\n",vetorInt->vet[i]);
    }
    printf("\n");

    VD_Vetor_pt x = VD_intercalaVetores(vetorInt,vetorInt);

    for(i = 0; i < x->nAtual; i++){
        printf("%.2f\n",x->vet[i]);
    }

    VD_destroiVetor(vetorInt);
    VD_destroiVetor(x);
    */
   
   VC_I_destroiVetor(vetorComp);
   //VC_I_destroiVetor(somaComp);

    return 0;
}