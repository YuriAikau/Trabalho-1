#ifndef COMPLEXOS_H_INCLUDED
#define COMPLEXOS_H_INCLUDED

/*
#define DESTE_TIPO_ long int
#define DESTE_FORMATO_ "%ld"
#define TIPADO_(Coisa) LI_ ## Coisa
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

#include "Racionais.h"

typedef struct TIPADO_(Complexo_st){
    DESTE_TIPO_ *real;
    DESTE_TIPO_ *imag;
}TIPADO_(Complexo_t);

typedef struct TIPADO_(Complexo_st) * TIPADO_(Complexo_pt);


TIPADO_(Complexo_pt) TIPADO_(criaComplexo) (DESTE_TIPO_ re, DESTE_TIPO_ im);

void TIPADO_(destroiComplexo) (TIPADO_(Complexo_pt) n);

void TIPADO_(atrbuiComplexos) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b);

TIPADO_(Complexo_pt) TIPADO_(copiaComplexo) (TIPADO_(Complexo_pt) n);

int TIPADO_(verificaModuloZero) (TIPADO_(Complexo_pt) n);

int TIPADO_(verificaModuloZero) (TIPADO_(Complexo_pt) n);

int TIPADO_(verificaApenasReal) (TIPADO_(Complexo_pt) n);

int TIPADO_(verificaApenasImag) (TIPADO_(Complexo_pt) n);

int TIPADO_(comparaComplexosModulo) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b);

int TIPADO_(comparaComplexosAngulo) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b);

DESTE_TIPO_ TIPADO_(retornaParteReal)(TIPADO_(Complexo_pt) n);

DESTE_TIPO_ TIPADO_(retornaParteImaginaria)(TIPADO_(Complexo_pt) n);

double TIPADO_(moduloComplexo) (TIPADO_(Complexo_pt) n);

double TIPADO_(anguloComplexo) (TIPADO_(Complexo_pt) n);

void TIPADO_(atribuirParteReal)(TIPADO_(Complexo_pt) n, DESTE_TIPO_ x);

void TIPADO_(atribuirParteImaginaria)(TIPADO_(Complexo_pt) n, DESTE_TIPO_ x);

void TIPADO_(atribuiNovoModulo)(TIPADO_(Complexo_pt) n, double escalar);

void TIPADO_(atribuiNovoAngulo)(TIPADO_(Complexo_pt) n, double angulo);

TIPADO_(Complexo_pt) TIPADO_(conjugadoComplexo)(TIPADO_(Complexo_pt) n);

TIPADO_(Complexo_pt) TIPADO_(somaComplexos) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b);

TIPADO_(Complexo_pt) TIPADO_(subtraiComplexos) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b);

TIPADO_(Complexo_pt) TIPADO_(multiplicaComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2);

TIPADO_(Complexo_pt) TIPADO_(divideComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2);

void TIPADO_(acumulaComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2);

void TIPADO_(multiplicaAtribuiComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2);

TIPADO_(Complexo_pt) TIPADO_(OperacaoComplexo) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2, char* operacao);

void TIPADO_(imprimeCSV) (FILE *fp, TIPADO_(Complexo_pt) n);

TIPADO_(Complexo_pt) TIPADO_(leCSV)(FILE *fp, int posicao);

void TIPADO_(imprimeComplexo)(TIPADO_(Complexo_pt) n);

void TIPADO_(tiraEspaco)(char *s);

#endif