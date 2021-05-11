#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Complexos_Racionais.h"

#define eps 0.00001

TIPADO_(Complexo_pt) TIPADO_(criaComplexo) (DESTE_TIPO_ re, DESTE_TIPO_ im){
    TIPADO_(Complexo_pt) numC = (TIPADO_(Complexo_pt))malloc(sizeof(TIPADO_(Complexo_t)));
    if (numC == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}

    numC->real = (Racional_pt *)malloc(sizeof(Racional_t));
    numC->imag = (Racional_pt *)malloc(sizeof(Racional_t));

    *numC->real = re;
    *numC->imag = im;

    return numC;
}

void TIPADO_(destroiComplexo) (TIPADO_(Complexo_pt) n){
    free(n->real);
    free(n->imag);
    free(n);
}

void TIPADO_(atrbuiComplexos) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b){
    *b->real = *a->real;
    *b->imag = *a->imag;
}

TIPADO_(Complexo_pt) TIPADO_(copiaComplexo) (TIPADO_(Complexo_pt) n){
    TIPADO_(Complexo_pt) cpy = (TIPADO_(Complexo_pt))malloc(sizeof(TIPADO_(Complexo_t)));
    if (cpy == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}

    *cpy->real = (Racional_pt)malloc(sizeof(Racional_t));
    *cpy->imag = (Racional_pt)malloc(sizeof(Racional_t));

    *cpy->real = *n->real;
    *cpy->imag = *n->imag;

    return cpy;
}

int TIPADO_(verificaModuloZero) (TIPADO_(Complexo_pt) n){
    DESTE_TIPO_ epsComp = dbleParaRacional(eps,1048576);
    
    if((comparaRacional(*n->real,epsComp) < 0) && (comparaRacional(*n->imag, epsComp) < 0)){
        return 1;
    }else{
        return 0;
    }
}

int TIPADO_(verificaApenasReal) (TIPADO_(Complexo_pt) n){
    Racional_pt zero = criaRacional(0,1);
    arrumaSinal(*n->imag);

    if(verificaZeroOverZero(*n->imag) || verificaNumZero(*n->imag) || verificaDenZero(*n->imag)){
        return 1;
    }
    if(comparaRacional(*n->imag,zero) < 0){
        Racional_pt epsComp = criaRacional(-1,10000);
        if(comparaRacional(*n->imag,epsComp) > 0){
            destroiRacional(zero);
            destroiRacional(epsComp);
            return 1;
        }else{
            destroiRacional(zero);
            destroiRacional(epsComp);
            return 0;
        }
    }else if(comparaRacional(*n->imag,zero) > 0){
        Racional_pt epsComp = criaRacional(1,10000);
        if(comparaRacional(*n->imag,epsComp) < 0){
            destroiRacional(zero);
            destroiRacional(epsComp);
            return 1;
        }else{
            destroiRacional(zero);
            destroiRacional(epsComp);
            return 0;
        }
    }
    destroiRacional(zero);
    return 0;
}

int TIPADO_(verificaApenasImag) (TIPADO_(Complexo_pt) n){
    Racional_pt zero = criaRacional(0,1);
    arrumaSinal(*n->real);

    if(verificaZeroOverZero(*n->real) || verificaNumZero(*n->real) || verificaDenZero(*n->imag)){
        destroiRacional(zero);
        return 1;
    }
    if(comparaRacional(*n->real,zero) < 0){
        Racional_pt epsComp = criaRacional(-1,10000);
        if(comparaRacional(*n->real,epsComp) > 0){
            destroiRacional(zero);
            destroiRacional(epsComp);
            return 1;
        }else{
            destroiRacional(zero);
            destroiRacional(epsComp);
            return 0;
        }
    }else if(comparaRacional(*n->real,zero) > 0){
        Racional_pt epsComp = criaRacional(1,10000);
        if(comparaRacional(*n->real,epsComp) < 0){
            destroiRacional(zero);
            destroiRacional(epsComp);
            return 1;
        }else{
            destroiRacional(zero);
            destroiRacional(epsComp);
            return 0;
        }
    }
    destroiRacional(zero);
    return 0;
}

int TIPADO_(comparaComplexosModulo) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b){
    double modA, modB;

    modA = TIPADO_(moduloComplexo)(a);
    modB = TIPADO_(moduloComplexo)(b);

    if (modA > modB){
        if(modA-modB <= eps){
            return 0;
        }else{
            return 1;
        }
    }else if(modB > modA){
        if(modB-modA <= eps){
            return 0;
        }else{
            return -1;
        }
    }
}

int TIPADO_(comparaComplexosAngulo) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b){
    double angA, angB;

    angA = TIPADO_(anguloComplexo)(a);
    angB = TIPADO_(anguloComplexo)(b);

    if (angA > angA){
        if(angA-angB <= eps){
            return 0;
        }else{
            return 1;
        }
    }else if(angB > angB){
        if(angB-angA <= eps){
            return 0;
        }else{
            return -1;
        }
    }
}

DESTE_TIPO_ TIPADO_(retornaParteReal)(TIPADO_(Complexo_pt) n){
    return *n->real;
}

DESTE_TIPO_ TIPADO_(retornaParteImaginaria)(TIPADO_(Complexo_pt) n){
    return *n->imag;
}

double TIPADO_(moduloComplexo) (TIPADO_(Complexo_pt) n){
    double tempA, tempB, moDulo;
    
    tempA = racionalParaDble(*n->real);
    tempB = racionalParaDble(*n->imag);

    moDulo = sqrt((tempA*tempA)+(tempB*tempB));

    return moDulo;
}

double TIPADO_(anguloComplexo) (TIPADO_(Complexo_pt) n){
    double temp, razao;
    
    temp = racionalParaDble(*n->real);
    razao = (temp)/(TIPADO_(moduloComplexo)(n));

    return acos(razao);
}

void TIPADO_(atribuirParteReal)(TIPADO_(Complexo_pt) n, DESTE_TIPO_ x){
    *n->real = x;
}

void TIPADO_(atribuirParteImaginaria)(TIPADO_(Complexo_pt) n, DESTE_TIPO_ x){
    *n->imag = x;
}

void TIPADO_(atribuiNovoModulo)(TIPADO_(Complexo_pt) n, double escalar){
    DESTE_TIPO_ temp;


    temp = dbleParaRacional(escalar,1048576);

    multiplicaRacional(*n->real, temp);
    multiplicaRacional(*n->imag, temp);
}

void TIPADO_(atribuiNovoAngulo)(TIPADO_(Complexo_pt) n, double angulo){
    double tempR, tempI;

    double dbleReal, dbleImag;

    dbleReal = racionalParaDble(*n->real);
    dbleImag = racionalParaDble(*n->imag);

    tempR = ((dbleReal)*(cos(angulo)))-((dbleImag)*(sin(angulo)));
    tempI = ((dbleReal)*(sin(angulo)))+((dbleImag)*(cos(angulo)));

    *n->real = dbleParaRacional(tempR, 1048576);
    *n->imag = dbleParaRacional(tempI, 1048576);
}

TIPADO_(Complexo_pt) TIPADO_(conjugadoComplexo)(TIPADO_(Complexo_pt) n){
    TIPADO_(Complexo_pt) temp = TIPADO_(copiaComplexo)(n);

    DESTE_TIPO_ conj = criaRacional(-1, 1);
    
    multiplicaRacional(*temp->imag,conj);
    destroiRacional(conj);

    return temp;
}

TIPADO_(Complexo_pt) TIPADO_(somaComplexos) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b){
    DESTE_TIPO_ re = criaRacional(1,1);
    DESTE_TIPO_ im = criaRacional(1,1);

    TIPADO_(Complexo_pt) soma = TIPADO_(criaComplexo)(re,im);
    destroiRacional(re);
    destroiRacional(im);

    *soma->real = somaRacionais(*a->real,*b->real);
    *soma->imag = somaRacionais(*a->imag,*b->imag);

    return soma;
}

TIPADO_(Complexo_pt) TIPADO_(subtraiComplexos) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b){
    DESTE_TIPO_ re = criaRacional(1,1);
    DESTE_TIPO_ im = criaRacional(1,1);

    TIPADO_(Complexo_pt) subtracao = TIPADO_(criaComplexo)(re,im);
    destroiRacional(re);
    destroiRacional(im);

    *subtracao->real = subtraiRacionais(*a->real,*b->real);
    *subtracao->imag = subtraiRacionais(*a->imag,*b->imag);
    
    return subtracao;

}

TIPADO_(Complexo_pt) TIPADO_(multiplicaComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2){
    arrumaSinal(*n1->real);
    arrumaSinal(*n1->imag);
    arrumaSinal(*n2->real);
    arrumaSinal(*n2->imag);

    DESTE_TIPO_ gene = criaRacional(1,1);
    TIPADO_(Complexo_pt) produto = TIPADO_(criaComplexo)(gene,gene);
    DESTE_TIPO_ a, b, c, d;

    a = copiaRacional(*n1->real);
    b = copiaRacional(*n1->imag); 
    c = copiaRacional(*n2->real);
    d = copiaRacional(*n2->imag);

    DESTE_TIPO_ prod1, prod2;

    prod1 = copiaRacional(a);
    prod2 = copiaRacional(b);
    multiplicaRacional(prod1,c);
    multiplicaRacional(prod2,d);
    *produto->real = copiaRacional(subtraiRacionais(prod1,prod2));

    destroiRacional(prod1);
    destroiRacional(prod2);

    prod1 = copiaRacional(a);
    prod2 = copiaRacional(b);
    multiplicaRacional(prod1,d);
    multiplicaRacional(prod2,c);
    *produto->imag = copiaRacional(somaRacionais(prod1,prod2));

    destroiRacional(prod1);
    destroiRacional(prod2);
    destroiRacional(gene);

    destroiRacional(a);
    destroiRacional(b);
    destroiRacional(c);
    destroiRacional(d);

    return produto;
}

TIPADO_(Complexo_pt) TIPADO_(divideComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2){
    arrumaSinal(*n1->real);
    arrumaSinal(*n1->imag);
    arrumaSinal(*n2->real);
    arrumaSinal(*n2->imag);

    DESTE_TIPO_ gene = criaRacional(1,1);
    TIPADO_(Complexo_pt) quociente = TIPADO_(criaComplexo)(gene,gene);
    DESTE_TIPO_ a, b, c, d, quadC, quadD;

    a = copiaRacional(*n1->real);
    b = copiaRacional(*n1->imag); 
    c = copiaRacional(*n2->real);
    d = copiaRacional(*n2->imag);

    quadC = copiaRacional(c);
    quadD = copiaRacional(d);

    quadradoRacional(quadC);
    quadradoRacional(quadD);

    DESTE_TIPO_ prod1, prod2, sub, soma, somaQuad;
    somaQuad = somaRacionais(quadC,quadD);

    prod1 = copiaRacional(a);
    prod2 = copiaRacional(b);
    multiplicaRacional(prod1,c);
    multiplicaRacional(prod2,d);
    soma = somaRacionais(prod1,prod2);
    *quociente->real = divideRacionais(soma,somaQuad);
    reduzNumeroRacional(*quociente->real);

    destroiRacional(prod1);
    destroiRacional(prod2);

    prod1 = copiaRacional(a);
    prod2 = copiaRacional(b);
    multiplicaRacional(prod2,c);
    multiplicaRacional(prod1,d);
    sub = subtraiRacionais(prod1,prod2);
    *quociente->imag = divideRacionais(sub,somaQuad);

    destroiRacional(prod1);
    destroiRacional(prod2);

    destroiRacional(soma);
    destroiRacional(sub);
    destroiRacional(quadC);
    destroiRacional(quadD);
    destroiRacional(somaQuad);
    
    destroiRacional(a);
    destroiRacional(b);
    destroiRacional(c);
    destroiRacional(d);

    destroiRacional(gene);

    return quociente;
}

void TIPADO_(acumulaComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2){
    n1 = TIPADO_(somaComplexos)(n1,n2);
}

void TIPADO_(multiplicaAtribuiComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2){
    n1 = TIPADO_(multiplicaComplexos)(n1,n2);
}

TIPADO_(Complexo_pt) TIPADO_(OperacaoComplexo) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2, char* operacao){
    TIPADO_(Complexo_pt) result;

    if(strcmp(operacao,"+") == 0){
        result = TIPADO_(somaComplexos)(n1,n2);
        return result;
    }
    
    if(strcmp(operacao,"-") == 0){
        result = TIPADO_(subtraiComplexos)(n1,n2);
        return result;
    }

    if(strcmp(operacao,"*") == 0){
        result = TIPADO_(multiplicaComplexos)(n1,n2);
        return result;
    }
        
    if(strcmp(operacao,"/") == 0){
        result = TIPADO_(divideComplexos)(n1,n2);
        return result;
    }
        
    if(strcmp(operacao,"+=") == 0){
        TIPADO_(acumulaComplexos)(n1,n2);
        return n1;
    }

    if(strcmp(operacao,"*=") == 0){
        TIPADO_(multiplicaAtribuiComplexos)(n1,n2);
        return n1;
    }
}

void TIPADO_(imprimeCSV) (FILE *fp, TIPADO_(Complexo_pt) n){
    char dir[32];

    printf("Digite o diretorio do destino: ");
    scanf("%s", dir);

    fp = fopen(dir, "a");

    char c[] = " ";
    strcat(c, DESTE_FORMATO_);

    arrumaSinal(*n->real);
    arrumaSinal(*n->imag);

    Racional_pt zero = criaRacional(0,1);

    if(comparaRacional(*n->imag,zero) > 0){
        if(TIPADO_(verificaApenasReal)(n)){
            Racional_pt real = copiaRacional(*n->real);

            strcat(c,",");

            fprintf(fp, c, real->num, real->den);

            destroiRacional(real);

        }else if(TIPADO_(verificaApenasImag)(n)){
            Racional_pt imag = copiaRacional(*n->imag);

            strcat(c,"i,");

            fprintf(fp, c, imag->num, imag->den);

            destroiRacional(imag);

        }else{
            Racional_pt real = copiaRacional(*n->real);
            Racional_pt imag = copiaRacional(*n->imag);

            strcat(c,"+");
            strcat(c,DESTE_FORMATO_);
            strcat(c,"i,");

            fprintf(fp, c, real->num, real->den, imag->num, imag->den);

            destroiRacional(real);
            destroiRacional(imag);
        }
        destroiRacional(zero);
    }else{
        if(TIPADO_(verificaApenasReal)(n)){
            Racional_pt real = copiaRacional(*n->real);

            strcat(c,",");

            fprintf(fp, c, real->num, real->den);

            destroiRacional(real);

        }else if(TIPADO_(verificaApenasImag)(n)){
            Racional_pt imag = copiaRacional(*n->imag);

            strcat(c,"i,");

            fprintf(fp, c, imag->num, imag->den);

            destroiRacional(imag);

        }else{
            Racional_pt real = copiaRacional(*n->real);
            Racional_pt imag = copiaRacional(*n->imag);

            strcat(c,DESTE_FORMATO_);
            strcat(c,"i,");

            fprintf(fp, c, real->num, real->den, imag->num, imag->den);

            destroiRacional(real);
            destroiRacional(imag);
        }
        destroiRacional(zero);
    }

    fclose(fp);
}

TIPADO_(Complexo_pt) TIPADO_(leCSV)(FILE *fp, int posicao){
    char arq[32];
    char vetor[32];
    char c[] = DESTE_FORMATO_;
    int i = 0;

    printf("Digite o diretorio do arquivo: ");
    scanf("%s", arq);

    fp = fopen(arq, "r");

    while (!(feof(fp)) && (i < posicao)){
        fscanf(fp, "%*[^,],");
        i++;
    }
    
    fscanf(fp, "%[^,],", vetor);
    TIPADO_(tiraEspaco)(vetor);

    char *str2;
    DESTE_TIPO_ n1 = criaRacional(1,1);

    TIPADO_(Complexo_pt) n = TIPADO_(criaComplexo)(n1,n1);

    if(strchr(vetor,'/') != NULL){
        str2 = strchr(vetor,'/');
        if(strchr(str2+1,'/') != NULL){
            Racional_pt r1 = criaRacional(1,1);
            Racional_pt r2 = criaRacional(1,1);

            strcat(c, DESTE_FORMATO_);
            sscanf(vetor, c, r1->num, r1->den, r2->num, r2->den);

            *n->real = copiaRacional(r1);
            *n->imag = copiaRacional(r2);

            destroiRacional(r1);
            destroiRacional(r2);

        }else{
            if(strchr(vetor,'i') != NULL){
                Racional_pt r1 = criaRacional(1,1);
                Racional_pt r2 = criaRacional(0,1);

                sscanf(vetor, c, r1->num, r1->den);

                *n->imag = copiaRacional(r1);
                *n->real = copiaRacional(r2);

                destroiRacional(r1);
                destroiRacional(r2);

            }else{
                Racional_pt r1 = criaRacional(1,1);
                Racional_pt r2 = criaRacional(0,1);

                sscanf(vetor, c, r1->num, r1->den);

                *n->real = copiaRacional(r1);
                *n->imag = copiaRacional(r2);

                destroiRacional(r1);
                destroiRacional(r2);
            }
        }
    }else{
        Racional_pt r1 = criaRacional(0,1);
        Racional_pt r2 = criaRacional(0,1);

        *n->real = copiaRacional(r1);
        *n->imag = copiaRacional(r2);

        destroiRacional(r1);
        destroiRacional(r2);
    }
    
    destroiRacional(n1);

    fclose(fp);

    return n;
}

/*
###############################################
Funcoes Auxiliares
###############################################
*/

void TIPADO_(imprimeComplexo)(TIPADO_(Complexo_pt) n){
    Racional_pt zero = criaRacional(0,1);

    if(TIPADO_(verificaApenasReal)(n)){
        arrumaSinal(*n->real);
        imprimeRacional(*n->real);
        printf("\n");
    }else if(TIPADO_(verificaApenasImag)(n)){
        arrumaSinal(*n->imag);
        imprimeRacional(*n->imag);
        printf("i\n");
    }else if(comparaRacional(*n->imag,zero) < 0){
        arrumaSinal(*n->real);
        arrumaSinal(*n->imag);
        imprimeRacional(*n->real);
        imprimeRacional(*n->imag);
        printf("i\n");
    }else{
        arrumaSinal(*n->real);
        arrumaSinal(*n->imag);
        imprimeRacional(*n->real);
        printf("+");
        imprimeRacional(*n->imag);
        printf("i\n");
    }
    destroiRacional(zero);
}

void TIPADO_(tiraEspaco)(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}