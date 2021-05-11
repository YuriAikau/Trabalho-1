#ifndef VCOMPLEXOS_H_INCLUDED
#define VCOMPLEXOS_H_INCLUDED

/*
#define DESTE_TIPO_ long int
#define DESTE_FORMATO_ "%ld"
#define CMPLX_(Coisa) LI_ ## Coisa
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

typedef struct CMPLX_(Complexo_st){
    DESTE_TIPO_ *real;
    DESTE_TIPO_ *imag;
}CMPLX_(Complexo_t);

typedef struct CMPLX_(Complexo_st) * CMPLX_(Complexo_pt);


CMPLX_(Complexo_pt) CMPLX_(criaComplexo) (DESTE_TIPO_ re, DESTE_TIPO_ im);

void CMPLX_(destroiComplexo) (CMPLX_(Complexo_pt) n);

void CMPLX_(atrbuiComplexos) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b);

CMPLX_(Complexo_pt) CMPLX_(copiaComplexo) (CMPLX_(Complexo_pt) n);

int CMPLX_(verificaModuloZero) (CMPLX_(Complexo_pt) n);

int CMPLX_(verificaModuloZero) (CMPLX_(Complexo_pt) n);

int CMPLX_(verificaApenasReal) (CMPLX_(Complexo_pt) n);

int CMPLX_(verificaApenasImag) (CMPLX_(Complexo_pt) n);

int CMPLX_(comparaComplexosModulo) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b);

int CMPLX_(comparaComplexosAngulo) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b);

DESTE_TIPO_ CMPLX_(retornaParteReal)(CMPLX_(Complexo_pt) n);

DESTE_TIPO_ CMPLX_(retornaParteImaginaria)(CMPLX_(Complexo_pt) n);

double CMPLX_(moduloComplexo) (CMPLX_(Complexo_pt) n);

double CMPLX_(anguloComplexo) (CMPLX_(Complexo_pt) n);

void CMPLX_(atribuirParteReal)(CMPLX_(Complexo_pt) n, DESTE_TIPO_ x);

void CMPLX_(atribuirParteImaginaria)(CMPLX_(Complexo_pt) n, DESTE_TIPO_ x);

void CMPLX_(atribuiNovoModulo)(CMPLX_(Complexo_pt) n, double escalar);

void CMPLX_(atribuiNovoAngulo)(CMPLX_(Complexo_pt) n, double angulo);

CMPLX_(Complexo_pt) CMPLX_(conjugadoComplexo)(CMPLX_(Complexo_pt) n);

CMPLX_(Complexo_pt) CMPLX_(somaComplexos) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b);

CMPLX_(Complexo_pt) CMPLX_(subtraiComplexos) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b);

CMPLX_(Complexo_pt) CMPLX_(multiplicaComplexos) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2);

CMPLX_(Complexo_pt) CMPLX_(divideComplexos) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2);

void CMPLX_(acumulaComplexos) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2);

void CMPLX_(multiplicaAtribuiComplexos) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2);

CMPLX_(Complexo_pt) CMPLX_(OperacaoComplexo) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2, char* operacao);

void CMPLX_(imprimeCSV) (FILE *fp, CMPLX_(Complexo_pt) n);

CMPLX_(Complexo_pt) CMPLX_(leCSV)(FILE *fp, int posicao);

void CMPLX_(imprimeComplexo)(CMPLX_(Complexo_pt) n);

void CMPLX_(tiraEspaco)(char *s);

#endif