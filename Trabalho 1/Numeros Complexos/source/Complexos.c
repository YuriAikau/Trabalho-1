#ifdef TIPADO_
#ifdef DESTE_TIPO_
#ifdef DESTE_FORMATO_

#define eps 0.00001

TIPADO_(Complexo_pt) TIPADO_(criaComplexo) (DESTE_TIPO_ re, DESTE_TIPO_ im){
    TIPADO_(Complexo_pt) numC = (TIPADO_(Complexo_pt))malloc(sizeof(TIPADO_(Complexo_t)));

    if (numC == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}

    numC->real = (DESTE_TIPO_ *)malloc(sizeof(DESTE_TIPO_));
    numC->imag = (DESTE_TIPO_ *)malloc(sizeof(DESTE_TIPO_));

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
    TIPADO_(Complexo_pt) cpy = TIPADO_(criaComplexo)(0,0);

    if (cpy == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}

    *cpy->real = *n->real;
    *cpy->imag = *n->imag;

    return cpy;
}

int TIPADO_(verificaModuloZero) (TIPADO_(Complexo_pt) n){
    if(TIPADO_(moduloComplexo)(n) <= eps){
        return 1;
    }else{
        return 0;
    }
}

int TIPADO_(verificaApenasReal) (TIPADO_(Complexo_pt) n){
    if (*n->imag < 0.0){
        if (*n->imag >= ((-1)*(DESTE_TIPO_)eps)){
            return 1;
        }else{
            return 0;
        }
    }else if(*n->imag > 0.0){
        if (*n->imag <= (DESTE_TIPO_)eps){
            return 1;
        }else{
            return 0;
        }
    }
}

int TIPADO_(verificaApenasImag) (TIPADO_(Complexo_pt) n){
    if (*n->real < 0.0){
        if (*n->real >= ((-1)*(DESTE_TIPO_)eps)){
            return 1;
        }else{
            return 0;
        }
    }else if(*n->real > 0.0){
        if (*n->real <= (DESTE_TIPO_)eps){
            return 1;
        }else{
            return 0;
        }
    }
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
    
    tempA = (double)*n->real;
    tempB = (double)*n->imag;

    moDulo = sqrt((tempA*tempA)+(tempB*tempB));

    return moDulo;

}

double TIPADO_(anguloComplexo) (TIPADO_(Complexo_pt) n){
    double temp, razao;

    temp = (double)*n->real;
    
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

    temp = (DESTE_TIPO_)escalar;

    *n->real = (*n->real)*(temp);
    *n->imag = (*n->imag)*(temp);
}

void TIPADO_(atribuiNovoAngulo)(TIPADO_(Complexo_pt) n, double angulo){
    double tempR, tempI;


    tempR = (((double)(*n->real))*(cos(angulo)))-(((double)(*n->imag))*(sin(angulo)));
    tempI = (((double)(*n->real))*(sin(angulo)))+(((double)(*n->imag))*(cos(angulo)));

    *n->real = (DESTE_TIPO_)tempR;
    *n->imag = (DESTE_TIPO_)tempI;
}

TIPADO_(Complexo_pt) TIPADO_(conjugadoComplexo)(TIPADO_(Complexo_pt) n){
    TIPADO_(Complexo_pt) temp = TIPADO_(copiaComplexo)(n);

    *temp->imag *= (DESTE_TIPO_)(-1);

    return temp;
}

TIPADO_(Complexo_pt) TIPADO_(somaComplexos) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b){
    TIPADO_(Complexo_pt) soma = TIPADO_(criaComplexo)(1,1);

    *soma->real = (*a->real)+(*b->real);
    *soma->imag = (*a->imag)+(*b->imag);

    return soma;
}

TIPADO_(Complexo_pt) TIPADO_(subtraiComplexos) (TIPADO_(Complexo_pt) a, TIPADO_(Complexo_pt) b){
    TIPADO_(Complexo_pt) subtracao = TIPADO_(criaComplexo)(1,1);

    *subtracao->real = (*a->real)-(*b->real);
    *subtracao->imag = (*a->imag)-(*b->imag);

    return subtracao;
}

TIPADO_(Complexo_pt) TIPADO_(multiplicaComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2){
    TIPADO_(Complexo_pt) produto = TIPADO_(criaComplexo)(1,1);
    DESTE_TIPO_ a, b, c, d;

    a = *n1->real;
    b = *n1->imag; 
    c = *n2->real;
    d = *n2->imag;

    *produto->real = ((a*c)-(b*d));
    *produto->imag = ((a*d)+(b*c));

    return produto;
}

TIPADO_(Complexo_pt) TIPADO_(divideComplexos) (TIPADO_(Complexo_pt) n1, TIPADO_(Complexo_pt) n2){
    TIPADO_(Complexo_pt) quociente = TIPADO_(criaComplexo)(1,1);
    DESTE_TIPO_ a, b, c, d, real, imag;

    a = *n1->real;
    b = *n1->imag; 
    c = *n2->real;
    d = *n2->imag;

    real = ((a*c)+(b*d))/((c*c)+(d*d));
    imag = ((b*c)-(a*d))/((c*c)+(d*d));

    if(isnan(real) || isnan(imag)){
        *quociente->real = NAN;
        *quociente->imag = NAN;
        return quociente;
    }
    *quociente->real = real;
    *quociente->imag = imag;
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
    
    if(*n->imag > (DESTE_TIPO_)0){
        if(TIPADO_(verificaApenasReal)(n)){
            strcat(c,",");
            fprintf(fp, c,*n->real);
        }else if(TIPADO_(verificaApenasImag)(n)){
            strcat(c,"i,");
            fprintf(fp, c, *n->imag);
        }else{
            strcat(c,"+");
            strcat(c,DESTE_FORMATO_);
            strcat(c,"i,");
            fprintf(fp,c, *n->real, *n->imag);
        }
    }else{
        if(TIPADO_(verificaApenasReal)(n)){
            strcat(c,",");
            fprintf(fp, c,*n->real);
        }else if(TIPADO_(verificaApenasImag)(n)){
            strcat(c,"i,");
            fprintf(fp, c,*n->imag);
        }else{
            strcat(c,DESTE_FORMATO_);
            strcat(c,"i,");
            fprintf(fp, c,*n->real, *n->imag);
        }
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

    char *str1;
    DESTE_TIPO_ n1;
    DESTE_TIPO_ n3, n4;
    int qnt;

    n1 = (DESTE_TIPO_)1;

    TIPADO_(Complexo_pt) n = TIPADO_(criaComplexo)(n1,n1);

    if(strchr(vetor,'-') != NULL){
        str1 = strchr(vetor,'-');
        if((strchr(str1+1,'+') != NULL) || (strchr(str1+1,'-')) != NULL){
            strcat(c,DESTE_FORMATO_);
            sscanf(vetor, c, *n->real, *n->imag);
        }else{
            sscanf(vetor, c, *n->real);
            *n->imag = (DESTE_TIPO_)0;
        }
    }else{
        strcat(c,DESTE_FORMATO_);
        qnt = sscanf(vetor, c, &n3, &n4);
        if(strchr(vetor, 'i') != NULL){
            if(qnt == 2){
                *n->real = n3;
                *n->imag = n4;
            }else if(qnt == 1){
                *n->real = (DESTE_TIPO_)0;
                *n->imag = n3;
            }else{
                *n->real = (DESTE_TIPO_)0;
                *n->imag = (DESTE_TIPO_)0;
            }
        }else{
            if(qnt == 1){
                *n->real = n3;
                *n->imag = (DESTE_TIPO_)0;
            }else{
                *n->real = (DESTE_TIPO_)0;
                *n->imag = (DESTE_TIPO_)0;
            }
        }
    }
    fclose(fp);

    return n;
}

/*
###############################################
Funcoes Auxiliares
###############################################
*/

void TIPADO_(imprimeComplexo)(TIPADO_(Complexo_pt) n){
    char c[] = DESTE_FORMATO_;
    
    if(*n->imag > (DESTE_TIPO_)0){
        if(TIPADO_(verificaApenasReal)(n)){
            strcat(c,"\n");
            printf(c,*n->real);
        }else if(TIPADO_(verificaApenasImag)(n)){
            strcat(c,"i\n");
            printf(c, *n->imag);
        }else{
            strcat(c,"+");
            strcat(c,DESTE_FORMATO_);
            strcat(c,"i\n");
            printf(c,*n->real, *n->imag);
        }
    }else{
        if(TIPADO_(verificaApenasReal)(n)){
            strcat(c,"\n");
            printf(c,*n->real);
        }else if(TIPADO_(verificaApenasImag)(n)){
            strcat(c,"i\n");
            printf(c,*n->imag);
        }else{
            strcat(c,DESTE_FORMATO_);
            strcat(c,"i\n");
            printf(c,*n->real, *n->imag);
        }
    }
}

void TIPADO_(tiraEspaco)(char* s) {
    const char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}

#endif
#endif
#endif