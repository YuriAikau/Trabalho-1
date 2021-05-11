#ifndef VETORES_H_INCLUDED
#define VETORES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct TIPADO_(Vetor_st){
    int nAtual;
    int nMax;
    int indice;
    DESTE_TIPO_ *vet;
}TIPADO_(Vetor_t);

typedef struct TIPADO_(Vetor_st) * TIPADO_(Vetor_pt);


TIPADO_(Vetor_pt) TIPADO_(criaVetor) ();

void TIPADO_(destroiVetor)(TIPADO_(Vetor_pt) v);

void TIPADO_(copiaVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2);

TIPADO_(Vetor_pt) TIPADO_(criaCopiaVetor)(TIPADO_(Vetor_pt) v);

int TIPADO_(devolveNumeroAtual)(TIPADO_(Vetor_pt) v);

int TIPADO_(devolveNumeroMaximo)(TIPADO_(Vetor_pt) v);

int TIPADO_(devolveIndiceAtual)(TIPADO_(Vetor_pt) v);

DESTE_TIPO_ TIPADO_(retornaPrimeiroElemento)(TIPADO_(Vetor_pt) v);

DESTE_TIPO_ TIPADO_(retornaProxElemento)(TIPADO_(Vetor_pt) v);

DESTE_TIPO_ TIPADO_(retornaElementoAnterior)(TIPADO_(Vetor_pt) v);

DESTE_TIPO_ TIPADO_(retornaUltimoElemento)(TIPADO_(Vetor_pt) v);

DESTE_TIPO_ TIPADO_(retornaIesimoElemento)(TIPADO_(Vetor_pt) v, int i);

void TIPADO_(atribuiValorIesimaPosicao)(TIPADO_(Vetor_pt) v, DESTE_TIPO_ n, int i);

void TIPADO_(atribuiValorDepoisUltima)(TIPADO_(Vetor_pt) v, DESTE_TIPO_ n);

DESTE_TIPO_ TIPADO_(eliminaIesimaPosicao)(TIPADO_(Vetor_pt) v, int i);

void TIPADO_(eliminaTodosElementos)(TIPADO_(Vetor_pt) v);

DESTE_TIPO_ TIPADO_(obtemMaiorModulo)(TIPADO_(Vetor_pt) v);

DESTE_TIPO_ TIPADO_(obtemMenorModulo)(TIPADO_(Vetor_pt) v);

int TIPADO_(qntdDeNumerosIguais)(TIPADO_(Vetor_pt) v, DESTE_TIPO_ n);

int* TIPADO_(posicoesNumerosIguais)(TIPADO_(Vetor_pt) v, DESTE_TIPO_ n);

void TIPADO_(ordenaVetor)(TIPADO_(Vetor_pt) v, int n);

TIPADO_(Vetor_pt) TIPADO_(intercalaVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2);

TIPADO_(Vetor_pt) TIPADO_(somaVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2);

DESTE_TIPO_ TIPADO_(produtoInternoVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2);

TIPADO_(Vetor_pt) TIPADO_(subtraiVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2);

void TIPADO_(multiplicaEscalarVetor)(TIPADO_(Vetor_pt) v, DESTE_TIPO_ escalar);

void TIPADO_(acumulaVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2);

double TIPADO_(mediaAritmeticaVetor)(TIPADO_(Vetor_pt) v);

double TIPADO_(varianciaVetor)(TIPADO_(Vetor_pt) v);

double TIPADO_(dpVetor)(TIPADO_(Vetor_pt) v);

float TIPADO_(medianaVetor)(TIPADO_(Vetor_pt) v);

void TIPADO_(realocaVetor)(TIPADO_(Vetor_pt) v);

int TIPADO_(criterio)(DESTE_TIPO_ a, DESTE_TIPO_ b);

#endif
