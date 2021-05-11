#include "Racionais.h"

long int maiorDivisor (long int n1, long int n2){
    if (n2 == 0){
        return n1;
    }
    return maiorDivisor(n2, n1%n2);
}

void reduzNumeroRacional (Racional_pt n){
    long int temp= maiorDivisor(n->num, n->den);
    n->num /= temp;
    n->den /= temp;
}

Racional_pt criaRacional (long int a, long int b){
    Racional_pt numR = (Racional_pt)(malloc(sizeof(Racional_t)));
    if (numR == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
    numR->num = a;
    numR->den = b;

    return numR;
}

void destroiRacional(Racional_pt n){
    free(n);
}

Racional_pt copiaRacional (Racional_pt n){
    Racional_pt cpy = (Racional_pt)(malloc(sizeof(Racional_t)));
    if (cpy == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
    cpy->num = n->num;
    cpy->den = n->den;

    return cpy;
}

int comparaRacional (Racional_pt a, Racional_pt b){
    arrumaSinal(a);
    arrumaSinal(b);

    if (a->den == b->den){
        if (a->num > b->num){
            return 1;
        }else if (a->num < b->num){
            return -1;
        }else{
            return 0;
        }
    }
    if (a->num == b->num){
        if (a->num > 0 && b->num > 0){
            if (a->den > b->den){
                return -1;
            }else if (a->den < b->den){
                return 1;
            }else{
                return 0;
            }
        }else if(a->num < 0 && b->num < 0){
            if (a->den > b->den){
                return 1;
            }else if (a->den < b->den){
                return -1;
            }else{
                return 0;
            }
        }
    }
    if (((a->num)*(b->den)) > ((b->num)*(a->den))){
        return 1;
    }else{
        return -1;
    }
}

int verificaEquivalencia (Racional_pt a, Racional_pt b){
    reduzNumeroRacional(a);
    reduzNumeroRacional(b);
    if ((a->num == b->num) && (a->den == b->den)){
        return 1;
    }else{
        return 0;
    }
}

int verificaDenZero (Racional_pt n){
    if (n->den == 0){
        return 1;
    }else{
        return 0;
    }
}

int verificaNumZero (Racional_pt n){
    if (n->num == 0){
        return 1;
    }else{
        return 0;
    }
}

int verificaZeroOverZero (Racional_pt n){
    if (verificaDenZero(n) && verificaNumZero(n)){
        return 1;
    }else{
        return 0;
    }
}

Racional_pt somaRacionais (Racional_pt a, Racional_pt b){
    long int mmc;
    Racional_pt sum = (Racional_pt)(malloc(sizeof(Racional_t)));
    if (sum == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
    if (a->den == b->den){
        sum->den = a->den;
        sum->num = a->num + b->num;
    }else{
        mmc = menorMultiplo(a->den, b->den);
        sum->den = mmc;
        sum->num = ((a->num)*(mmc/(a->den))) + ((b->num)*(mmc/(b->den)));
    }

    return sum;
}

void acumulaRacional (Racional_pt a, Racional_pt b){
    long int mmc;
    if (a->den == b->den){
        a->num += b->num;
    }else{
        mmc = menorMultiplo(a->den, b->den);
        a->den = mmc;
        a->num = ((a->num)*(mmc/(a->den))) + ((b->num)*(mmc/(b->den)));
    }
}

Racional_pt subtraiRacionais (Racional_pt a, Racional_pt b){
    long int mmc;
    Racional_pt sum = (Racional_pt)(malloc(sizeof(Racional_t)));
    if (sum == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
    if (a->den == b->den){
        sum->den = a->den;
        sum->num = a->num - b->num;
    }else{
        mmc = menorMultiplo(a->den, b->den);
        sum->den = mmc;
        sum->num = ((a->num)*(mmc/(a->den))) - ((b->num)*(mmc/(b->den)));
    }

    return sum;
}

void multiplicaRacional (Racional_pt a, Racional_pt b){
    a->num *= b->num;
    a->den *= b->den;
}

Racional_pt divideRacionais (Racional_pt a, Racional_pt b){
    Racional_pt quociente = (Racional_pt)(malloc(sizeof(Racional_t)));
    if (quociente == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
    quociente->num = (a->num)*(b->den);
    quociente->den = (a->den)*(b->num);

    return quociente; 
}

void quadradoRacional (Racional_pt n){
    n->num *= n->num;
    n->den *= n->den;
}

void raizquadradaRacional (Racional_pt n, double eps){
    
}

double racionalParaDouble (Racional_pt n){
    double resultado;

    resultado = ((double)(n->num))/((n->den));

    return resultado;
}

Racional_pt dbleParaRacional (double f, int precisao){ // precisao razoavel: 1048576
    int64_t a, b;
    Racional_pt temp = (Racional_pt)(malloc(sizeof(Racional_t)));

    if (temp == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}
    approx_racional(f, precisao, &a, &b);
    temp->num = (long int)a;
    temp->den = (long int)b;

    return temp;
}

int verificaRacionalParaInteiro (Racional_pt n, double eps){
    double temp;

    temp = racionalParaDouble(n);

    if (distInteiro(temp) < eps){
        return 1;
    }else{
        return 0;
    }
}

void imprimeEmCSV (FILE* fp, Racional_pt n){
    char dir[32];

    printf("Digite o diretorio do destino: ");
    scanf("%s", dir);

    fp = fopen(dir, "a");

    fprintf(fp, "%d/%d,", n->num, n->den);

    fclose(fp);
}

Racional_pt leCSV (FILE* fp, int posicao){
    int i = 0, j;
    char arq[32];
    char vetor[32];

    Racional_pt temp = criaRacional(0,0);

    printf("Digite o diretorio arquivo: ");
    scanf("%s", arq);

    fp = fopen(arq, "r");

    while (!(feof(fp)) && i < posicao){
        fscanf(fp,"%*[^,],");
        i++;
    }

    fscanf(fp,"%[^,],", vetor);

    if(strchr(vetor,'/') != NULL){
        sscanf(vetor,"%ld/%ld", &temp->num, &temp->den);
    }else{
        sscanf(vetor,"%ld", &temp->num);
        temp->den = 1;
    }

    fclose(fp);

    return temp;
}

/*
###############################################
Funcoes Auxiliares
###############################################
*/

long int menorMultiplo (long int n1, long int n2){
    if (n1 > n2){
        if (n1%n2 == 0){
            return (n1/n2)*n2;
        }else{
            return n1*n2;
        }
    }else if (n1 < n2){
        if(n2%n1 == 0){
            return (n2/n1)*n1;
        }else{
            return n2*n1;
        }
    }
}

void approx_racional(double f, int64_t md, int64_t *num, int64_t *denom)
{
	int64_t a, h[3] = { 0, 1, 0 }, k[3] = { 1, 0, 0 };
	int64_t x, d, n = 1;
	int i, neg = 0;
 
	if (md <= 1) { 
        *denom = 1; 
        *num = (int64_t) f; 
        return; 
    }
 
	if (f < 0) { 
        neg = 1; 
        f = -f; 
    }
 
	while (f != floor(f)) { 
        n <<= 1; 
        f *= 2; 
    }

	d = f;
 
	for (i = 0; i < 64; i++) {
		a = n ? d / n : 0;
		if (i && !a){ 
            break;
        }
 
		x = d; 
        d = n; 
        n = x % n;
		x = a;

		if (k[1] * a + k[0] >= md) {
			x = (md - k[0]) / k[1];
			if (x * 2 >= a || k[1] >= md)
				i = 65;
			else
				break;
		}
		
        h[2] = x * h[1] + h[0]; 
        h[0] = h[1]; 
        h[1] = h[2];
		k[2] = x * k[1] + k[0]; 
        k[0] = k[1]; 
        k[1] = k[2];
	}
	*denom = k[1];
	*num = neg ? -h[1] : h[1];
}

int menorDistFloorCeil (double n){ // floor = 0, ceil = 1, inteiro = 2;
	if (n < ceil(n)){
		if ((double)(ceil(n)) - n < n - ((double)floor(n))){
			return 1;
		}else{
			return 0;
		}
	}
	return 2;
}

double distInteiro (double n){
	double dist;
	int caso;

	caso = menorDistFloorCeil(n);

	switch (caso)
	{
	case 0:
		dist = n - ((double)floor(n));
		break;

	case 1:
		dist = (double)(ceil(n)) - n;
		break;

	case 2:
		dist = 0;
		break;

	default:
		break;

	}
	return dist;
}

void imprimeRacional(Racional_pt n){
    printf("%ld/%ld", n->num, n->den);
}

void arrumaSinal(Racional_pt n){
    if (n->num < 0 && n->den < 0){
        n->num *= -1;
        n->den *= -1;
    }else if (n->den < 0 && n->num > 0){
        n->num *= -1;
        n->den *= -1;
    }
}