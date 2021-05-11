#ifdef TIPADO_
#ifdef CMPLX_
#ifdef DESTE_TIPO_
#ifdef DESTE_FORMATO_

TIPADO_(Vetor_pt) TIPADO_(criaVetor) (){
    TIPADO_(Vetor_pt) vetor = (TIPADO_(Vetor_pt))malloc(sizeof(TIPADO_(Vetor_t)));
    if (vetor == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}

    vetor->nAtual = 0;
    vetor->nMax = 100;
    vetor->indice = 0;

    vetor->vet = (CMPLX_(Complexo_pt)*)calloc(100, sizeof(CMPLX_(Complexo_t)));
    if (vetor->vet == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}

    return vetor;
}

void TIPADO_(destroiVetor)(TIPADO_(Vetor_pt) v){
    free(v->vet);
    free(v);
}

void TIPADO_(copiaVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2){
    memcpy(v1,v2,(sizeof(TIPADO_(Vetor_t)))+1);
    memcpy(v1->vet,v2->vet,(v1->nMax)*(sizeof(CMPLX_(Complexo_t)))+1);
}

TIPADO_(Vetor_pt) TIPADO_(criaCopiaVetor)(TIPADO_(Vetor_pt) v){
    TIPADO_(Vetor_pt) vetcpy = TIPADO_(criaVetor)();

    TIPADO_(copiaVetores)(vetcpy,v);

    return vetcpy;
}

int TIPADO_(devolveNumeroAtual)(TIPADO_(Vetor_pt) v){
    return v->nAtual;
}

int TIPADO_(devolveNumeroMaximo)(TIPADO_(Vetor_pt) v){
    return v->nMax;
}

int TIPADO_(devolveIndiceAtual)(TIPADO_(Vetor_pt) v){
    return v->indice;
}

CMPLX_(Complexo_pt) TIPADO_(retornaPrimeiroElemento)(TIPADO_(Vetor_pt) v){
    v->indice = 0;

    return v->vet[(v->indice)];
}

CMPLX_(Complexo_pt) TIPADO_(retornaProxElemento)(TIPADO_(Vetor_pt) v){
    v->indice += 1;

    return v->vet[(v->indice)];
}

CMPLX_(Complexo_pt) TIPADO_(retornaElementoAnterior)(TIPADO_(Vetor_pt) v){
    v->indice -= 1;

    return v->vet[(v->indice)];
}

CMPLX_(Complexo_pt) TIPADO_(retornaUltimoElemento)(TIPADO_(Vetor_pt) v){
    v->indice = (v->nAtual)-1;

    return v->vet[(v->indice)];
}

CMPLX_(Complexo_pt) TIPADO_(retornaIesimoElemento)(TIPADO_(Vetor_pt) v, int i){
    v->indice = i;

    return v->vet[(v->indice)];
}

void TIPADO_(atribuiValorIesimaPosicao)(TIPADO_(Vetor_pt) v, CMPLX_(Complexo_pt) n, int i){
    v->indice = i;
    v->vet[i] = n;

    TIPADO_(realocaVetor)(v);
}

void TIPADO_(atribuiValorDepoisUltima)(TIPADO_(Vetor_pt) v, CMPLX_(Complexo_pt) n){
    v->indice = (v->nAtual);
    v->vet[v->indice] = n;

    v->nAtual += 1;

    TIPADO_(realocaVetor)(v);
}

CMPLX_(Complexo_pt) TIPADO_(eliminaIesimaPosicao)(TIPADO_(Vetor_pt) v, int i){
    CMPLX_(Complexo_pt) temp = v->vet[i];

    for (i; i+1 < (v->nAtual); i++){
        v->vet[i] = v->vet[i+1];
    }
    v->vet[i] = 0;

    TIPADO_(realocaVetor)(v);

    v->nAtual -= 1;

    TIPADO_(realocaVetor)(v);

    return temp;
}

void TIPADO_(eliminaTodosElementos)(TIPADO_(Vetor_pt) v){
    int i;

    for(i = 0; i < (v->nAtual); i++){
        v->vet[i] = 0;
    }

    v->indice = 0;
    v->nAtual = 0;

    TIPADO_(realocaVetor)(v);
}

CMPLX_(Complexo_pt) TIPADO_(obtemMaiorModulo)(TIPADO_(Vetor_pt) v){
    CMPLX_(Complexo_pt) maiorModulo = CMPLX_(criaComplexo)(0,0);
    int i;

    for(i = 0; i < (v->nAtual); i++){
        if(CMPLX_(comparaComplexosModulo)(v->vet[i],maiorModulo) > 0){
            maiorModulo = v->vet[i];
            v->indice = i;
        }
    }

    return maiorModulo;
}

CMPLX_(Complexo_pt) TIPADO_(obtemMenorModulo)(TIPADO_(Vetor_pt) v){
    CMPLX_(Complexo_pt) menorModulo = CMPLX_(criaComplexo)(0,0);
    int i;

    menorModulo = v->vet[0];

    for(i = 0; i < (v->nAtual); i++){
        
        if(CMPLX_(comparaComplexosModulo)(v->vet[i],menorModulo) < 0){
            menorModulo = v->vet[i];
            v->indice = i;
        }
    }

    return menorModulo;
}

int TIPADO_(qntdDeNumerosIguais)(TIPADO_(Vetor_pt) v, CMPLX_(Complexo_pt) n){
    int i, cont = 0;

    for(i = 0; i < (v->nAtual); i++){
        if(CMPLX_(comparaComplexosModulo)(v->vet[i],n) == 0){
            cont++;
        }
    }

    return cont;
}

int* TIPADO_(posicoesNumerosIguais)(TIPADO_(Vetor_pt) v, CMPLX_(Complexo_pt) n){ //lembrar de dar free
    int qnt = TIPADO_(qntdDeNumerosIguais)(v,n);

    int *vet = (int*)malloc((qnt)*(sizeof(int)));

    int i, j=0;

    for(i = 0; i < (v->nAtual); i++){
        if(CMPLX_(comparaComplexosModulo)(v->vet[i],n) == 0){
            vet[j] = i;
            j++;
        }
    }

    return vet;
}

void TIPADO_(ordenaVetor)(TIPADO_(Vetor_pt) v, int n){
    if(n < 1){
        return;
    }

    int i;
    CMPLX_(Complexo_pt) temp = CMPLX_(criaComplexo)(0,0);


    for(i = 0; i < (n-1); i++){
        CMPLX_(Complexo_pt) a = CMPLX_(copiaComplexo)(v->vet[i]);
        CMPLX_(Complexo_pt) b = CMPLX_(copiaComplexo)(v->vet[i+1]);

        if(TIPADO_(criterio)(a,b) > 0){
            temp = CMPLX_(copiaComplexo)(v->vet[i]);
            v->vet[i] = CMPLX_(copiaComplexo)(v->vet[i+1]);
            v->vet[i+1] = CMPLX_(copiaComplexo)(temp);

            CMPLX_(destroiComplexo)(temp);
        }
        CMPLX_(destroiComplexo)(a);
        CMPLX_(destroiComplexo)(b);
    }
    
    TIPADO_(ordenaVetor)(v,n-1);
    
}

TIPADO_(Vetor_pt) TIPADO_(intercalaVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2){
    int i,j = 0;

    TIPADO_(Vetor_pt) vetorOrg = TIPADO_(criaVetor)();
    vetorOrg->nAtual = ((v1->nAtual)+(v2->nAtual));

    for(i = 0; i < (vetorOrg->nAtual); i += 2){
        vetorOrg->vet[i] = v1->vet[j];
        vetorOrg->vet[i+1] = v2->vet[j];
        j++;
    }

    TIPADO_(ordenaVetor)(vetorOrg, vetorOrg->nAtual);

    return vetorOrg;
}

TIPADO_(Vetor_pt) TIPADO_(somaVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2){
    TIPADO_(Vetor_pt) soma = TIPADO_(criaVetor)();

    int i;

    for (i = 0; i < (v1->nAtual); i++){
        soma->vet[i] = CMPLX_(somaComplexos)(v1->vet[i],v2->vet[i]);
        TIPADO_(realocaVetor)(soma);
    }

    soma->indice = i-1;
    soma->nAtual = i;

    return soma;
}

CMPLX_(Complexo_pt) TIPADO_(produtoInternoVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2){
    CMPLX_(Complexo_pt) prod, soma = CMPLX_(criaComplexo)(0,0);

    int i;

    for (i = 0; i < (v1->nAtual); i++){
        prod = CMPLX_(multiplicaComplexos)(v1->vet[i],v2->vet[i]);
        soma = CMPLX_(somaComplexos)(soma,prod);
    }

    return soma;
}

TIPADO_(Vetor_pt) TIPADO_(subtraiVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2){
    TIPADO_(Vetor_pt) sub = TIPADO_(criaVetor)();

    int i;

    for (i = 0; i < (v1->nAtual); i++){
        sub->vet[i] = CMPLX_(subtraiComplexos)(v1->vet[i],v2->vet[i]);
        TIPADO_(realocaVetor)(sub);
    }

    sub->indice = i-1;
    sub->nAtual = i-1;

    return sub;
}

void TIPADO_(multiplicaEscalarVetor)(TIPADO_(Vetor_pt) v, double escalar){
    int i;

    for (i = 0; i < (v->nAtual); i++){
        CMPLX_(atribuiNovoModulo)(v->vet[i],escalar);
    }
}

void TIPADO_(acumulaVetores)(TIPADO_(Vetor_pt) v1, TIPADO_(Vetor_pt) v2){
    int i;

    for (i = 0; i < (v1->nAtual); i++){
        v1->vet[i] = CMPLX_(somaComplexos)(v1->vet[i],v2->vet[i]);
        TIPADO_(realocaVetor)(v1);
    }
}

double TIPADO_(mediaAritmeticaVetor)(TIPADO_(Vetor_pt) v){
    int i;
    int n = v->nAtual;

    double soma = (DESTE_TIPO_)0;
    double media;

    for(i = 0; i < n; i++){
        soma += CMPLX_(moduloComplexo)(v->vet[i]);
    }

    media = soma/n;

    return media;
}

double TIPADO_(varianciaVetor)(TIPADO_(Vetor_pt) v){
    double media = TIPADO_(mediaAritmeticaVetor)(v);
    double somaVar = 0.0;
    double variancia;
    int i;

    int n = (v->nAtual)-1;

    for (i = 0; i < (v->nAtual); i++){
        double x = CMPLX_(moduloComplexo)(v->vet[i]);
        somaVar += pow(x-media,2);
    }

    variancia = somaVar/n;

    return variancia;
}

double TIPADO_(dpVetor)(TIPADO_(Vetor_pt) v){
    double variancia = TIPADO_(varianciaVetor)(v);
    double dp;

    dp = sqrt(variancia);

    return dp;
}

float TIPADO_(medianaVetor)(TIPADO_(Vetor_pt) v){
    int i, menor, maior, igual;
    float min, max, chute, maxltchute, mingtchute;

    int n = (v->nAtual);

    min = max = ((float)CMPLX_(moduloComplexo)(v->vet[0]));
    for (i=1 ; i<n ; i++){
        if (((float)CMPLX_(moduloComplexo)(v->vet[i]))<min){
            min = (float)CMPLX_(moduloComplexo)(v->vet[i]);
        }
        if (((float)CMPLX_(moduloComplexo)(v->vet[i]))>max){
            max = ((float)CMPLX_(moduloComplexo)(v->vet[i]));
        }
    }

    while (1) {
        chute = (min+max)/2;
        menor = 0; maior = 0; igual = 0;
        maxltchute = min ;
        mingtchute = max ;
        for (i=0; i<n; i++){
            if (((float)CMPLX_(moduloComplexo)(v->vet[i]))<chute){
                menor++;
                if (((float)CMPLX_(moduloComplexo)(v->vet[i]))>maxltchute){
                    maxltchute = ((float)CMPLX_(moduloComplexo)(v->vet[i]));
                }
            }else if (((float)CMPLX_(moduloComplexo)(v->vet[i]))>chute){
                maior++;
                if (((float)CMPLX_(moduloComplexo)(v->vet[i]))<mingtchute){
                    mingtchute = ((float)CMPLX_(moduloComplexo)(v->vet[i]));
                }
            }else{
                igual++;
            }
        }
        if (menor <= (n+1)/2 && maior <= (n+1)/2){
            break;
        }else if (menor>maior){
            max = maxltchute;
        }else{
            min = mingtchute;
        }
    }
    if (menor > (n+1)/2){
        return maxltchute;
    }else if (menor+igual >= (n+1)/2){
        return chute;
    }else{
        return mingtchute;
    }
}

/*
###############################################
Funcoes Auxiliares
###############################################
*/


//colocar essa funcao no final de funçoes que altera o tamanho do vetor
void TIPADO_(realocaVetor)(TIPADO_(Vetor_pt) v){
    int novoValor;

    if((v->nMax)-1 == (v->nAtual)){
        novoValor = (v->nMax)*2;
        realloc(v->vet, novoValor * sizeof(CMPLX_(Complexo_t)));
        v->nMax = novoValor;
    }else if((v->nAtual) < (v->nMax)/4){
        novoValor = (v->nMax)/2;
        realloc(v->vet, novoValor * sizeof(CMPLX_(Complexo_t)));
        v->nMax = novoValor;
    }
}

int TIPADO_(criterio)(CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b){
    if(CMPLX_(comparaComplexosModulo)(a,b) > 0){
        return 1;
    }else if(CMPLX_(comparaComplexosModulo)(a,b) < 0){
        return -1;
    }else{
        return 0;
    }
}

#endif
#endif
#endif
#endif