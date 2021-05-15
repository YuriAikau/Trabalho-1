#ifndef RACIONAIS_H_INCLUDED
#define RACIONAIS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

typedef struct Racional_st{ 
    long int num;
    long int den;
} Racional_t;

typedef struct Racional_st * Racional_pt;

long int maiorDivisor (long int n1, long int n2);

void reduzNumeroRacional (Racional_pt n);

Racional_pt criaRacional (long int a, long int b);

void destroiRacional(Racional_pt n);

Racional_pt copiaRacional (Racional_pt n);

int comparaRacional (Racional_pt a, Racional_pt b);

int verificaEquivalencia (Racional_pt a, Racional_pt b);

int verificaDenZero (Racional_pt n);

int verificaNumZero (Racional_pt n);

int verificaZeroOverZero (Racional_pt n);

Racional_pt somaRacionais (Racional_pt a, Racional_pt b);

void acumulaRacional (Racional_pt a, Racional_pt b);

Racional_pt subtraiRacionais (Racional_pt a, Racional_pt b);

void multiplicaRacional (Racional_pt a, Racional_pt b);

Racional_pt divideRacionais (Racional_pt a, Racional_pt b);

void quadradoRacional (Racional_pt n);

double raizquadradaRacional (Racional_pt n, int i, double chute);

double racionalParaDble (Racional_pt n);

Racional_pt dbleParaRacional (double f, int precisao);

int verificaRacionalParaInteiro (Racional_pt n, double eps);

void imprimeEmCSV (FILE* fp, Racional_pt n);

Racional_pt leCSV (FILE* fp, int posicao);

long int menorMultiplo (long int n1, long int n2);

void approx_racional(double f, int64_t md, int64_t *num, int64_t *denom);

int menorDistFloorCeil (double n);

double distInteiro (double n);

void imprimeRacional(Racional_pt n);

void arrumaSinal(Racional_pt n);

#endif
