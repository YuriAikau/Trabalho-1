#ifdef CMPLX_
#ifdef DESTE_TIPO_
#ifdef DESTE_FORMATO_

#define eps 0.00001

CMPLX_(Complexo_pt) CMPLX_(criaComplexo) (DESTE_TIPO_ re, DESTE_TIPO_ im){
    CMPLX_(Complexo_pt) numC = (CMPLX_(Complexo_pt))malloc(sizeof(CMPLX_(Complexo_t)));

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

void CMPLX_(destroiComplexo) (CMPLX_(Complexo_pt) n){
    free(n->real);
    free(n->imag);
    free(n);
}

void CMPLX_(atrbuiComplexos) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b){
    *b->real = *a->real;
    *b->imag = *a->imag;
}

CMPLX_(Complexo_pt) CMPLX_(copiaComplexo) (CMPLX_(Complexo_pt) n){
    CMPLX_(Complexo_pt) cpy = CMPLX_(criaComplexo)(0,0);

    if (cpy == NULL) {
		printf("Memória insuficiente!\n");
		exit(1);
	}

    *cpy->real = *n->real;
    *cpy->imag = *n->imag;

    return cpy;
}

/*
void CMPLX_(mudaTipo) (char* tipo){

}*/

int CMPLX_(verificaModuloZero) (CMPLX_(Complexo_pt) n){
    if(CMPLX_(moduloComplexo)(n) <= eps){
        return 1;
    }else{
        return 0;
    }
}

int CMPLX_(verificaApenasReal) (CMPLX_(Complexo_pt) n){
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

int CMPLX_(verificaApenasImag) (CMPLX_(Complexo_pt) n){
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

int CMPLX_(comparaComplexosModulo) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b){
    double modA, modB;

    modA = CMPLX_(moduloComplexo)(a);
    modB = CMPLX_(moduloComplexo)(b);

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

int CMPLX_(comparaComplexosAngulo) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b){
    double angA, angB;

    angA = CMPLX_(anguloComplexo)(a);
    angB = CMPLX_(anguloComplexo)(b);

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

DESTE_TIPO_ CMPLX_(retornaParteReal)(CMPLX_(Complexo_pt) n){
    return *n->real;
}

DESTE_TIPO_ CMPLX_(retornaParteImaginaria)(CMPLX_(Complexo_pt) n){
    return *n->imag;
}

double CMPLX_(moduloComplexo) (CMPLX_(Complexo_pt) n){
    double tempA, tempB, moDulo;
    
    tempA = (double)*n->real;
    tempB = (double)*n->imag;

    moDulo = sqrt((tempA*tempA)+(tempB*tempB));

    return moDulo;

}

double CMPLX_(anguloComplexo) (CMPLX_(Complexo_pt) n){
    double temp, razao;

    temp = (double)*n->real;
    
    razao = (temp)/(CMPLX_(moduloComplexo)(n));

    return acos(razao);
}

void CMPLX_(atribuirParteReal)(CMPLX_(Complexo_pt) n, DESTE_TIPO_ x){
    *n->real = x;
}

void CMPLX_(atribuirParteImaginaria)(CMPLX_(Complexo_pt) n, DESTE_TIPO_ x){
    *n->imag = x;
}

void CMPLX_(atribuiNovoModulo)(CMPLX_(Complexo_pt) n, double escalar){
    DESTE_TIPO_ temp;

    temp = (DESTE_TIPO_)escalar;

    *n->real = (*n->real)*(temp);
    *n->imag = (*n->imag)*(temp);
}

void CMPLX_(atribuiNovoAngulo)(CMPLX_(Complexo_pt) n, double angulo){
    double tempR, tempI;


    tempR = (((double)(*n->real))*(cos(angulo)))-(((double)(*n->imag))*(sin(angulo)));
    tempI = (((double)(*n->real))*(sin(angulo)))+(((double)(*n->imag))*(cos(angulo)));

    *n->real = (DESTE_TIPO_)tempR;
    *n->imag = (DESTE_TIPO_)tempI;
}

CMPLX_(Complexo_pt) CMPLX_(conjugadoComplexo)(CMPLX_(Complexo_pt) n){
    CMPLX_(Complexo_pt) temp = CMPLX_(copiaComplexo)(n);

    *temp->imag *= (DESTE_TIPO_)(-1);

    return temp;
}

CMPLX_(Complexo_pt) CMPLX_(somaComplexos) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b){
    CMPLX_(Complexo_pt) soma = CMPLX_(criaComplexo)(1,1);

    *soma->real = (*a->real)+(*b->real);
    *soma->imag = (*a->imag)+(*b->imag);

    return soma;
}

CMPLX_(Complexo_pt) CMPLX_(subtraiComplexos) (CMPLX_(Complexo_pt) a, CMPLX_(Complexo_pt) b){
    CMPLX_(Complexo_pt) subtracao = CMPLX_(criaComplexo)(1,1);

    *subtracao->real = (*a->real)-(*b->real);
    *subtracao->imag = (*a->imag)-(*b->imag);

    return subtracao;
}

CMPLX_(Complexo_pt) CMPLX_(multiplicaComplexos) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2){
    CMPLX_(Complexo_pt) produto = CMPLX_(criaComplexo)(1,1);
    DESTE_TIPO_ a, b, c, d;

    a = *n1->real;
    b = *n1->imag; 
    c = *n2->real;
    d = *n2->imag;

    *produto->real = ((a*c)-(b*d));
    *produto->imag = ((a*d)+(b*c));

    return produto;
}

CMPLX_(Complexo_pt) CMPLX_(divideComplexos) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2){
    CMPLX_(Complexo_pt) quociente = CMPLX_(criaComplexo)(1,1);
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

void CMPLX_(acumulaComplexos) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2){
    n1 = CMPLX_(somaComplexos)(n1,n2);
}

void CMPLX_(multiplicaAtribuiComplexos) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2){
    n1 = CMPLX_(multiplicaComplexos)(n1,n2);
}

CMPLX_(Complexo_pt) CMPLX_(OperacaoComplexo) (CMPLX_(Complexo_pt) n1, CMPLX_(Complexo_pt) n2, char* operacao){
    CMPLX_(Complexo_pt) result;

    if(strcmp(operacao,"+") == 0){
        result = CMPLX_(somaComplexos)(n1,n2);
        return result;
    }

    if(strcmp(operacao,"-") == 0){
        result = CMPLX_(subtraiComplexos)(n1,n2);
        return result;
    }

    if(strcmp(operacao,"*") == 0){
        result = CMPLX_(multiplicaComplexos)(n1,n2);
        return result;
    }
        
    if(strcmp(operacao,"/") == 0){
        result = CMPLX_(divideComplexos)(n1,n2);
        return result;
    }
        
    if(strcmp(operacao,"+=") == 0){
        CMPLX_(acumulaComplexos)(n1,n2);
        return n1;
    }

    if(strcmp(operacao,"*=") == 0){
        CMPLX_(multiplicaAtribuiComplexos)(n1,n2);
        return n1;
    }
}

void CMPLX_(imprimeCSV) (FILE *fp, CMPLX_(Complexo_pt) n){
    char dir[32];

    printf("Digite o diretorio do destino: ");
    scanf("%s", dir);

    fp = fopen(dir, "a");

    char c[] = " ";
    strcat(c, DESTE_FORMATO_);
    
    if(*n->imag > (DESTE_TIPO_)0){
        if(CMPLX_(verificaApenasReal)(n)){
            strcat(c,",");
            fprintf(fp, c,*n->real);
        }else if(CMPLX_(verificaApenasImag)(n)){
            strcat(c,"i,");
            fprintf(fp, c, *n->imag);
        }else{
            strcat(c,"+");
            strcat(c,DESTE_FORMATO_);
            strcat(c,"i,");
            fprintf(fp,c, *n->real, *n->imag);
        }
    }else{
        if(CMPLX_(verificaApenasReal)(n)){
            strcat(c,",");
            fprintf(fp, c,*n->real);
        }else if(CMPLX_(verificaApenasImag)(n)){
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

CMPLX_(Complexo_pt) CMPLX_(leCSV)(FILE *fp, int posicao){
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
    CMPLX_(tiraEspaco)(vetor);

    char *str1;
    DESTE_TIPO_ n1;
    DESTE_TIPO_ n3, n4;
    int qnt;

    n1 = (DESTE_TIPO_)1;

    CMPLX_(Complexo_pt) n = CMPLX_(criaComplexo)(n1,n1);

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

void CMPLX_(imprimeComplexo)(CMPLX_(Complexo_pt) n){
    char c[] = DESTE_FORMATO_;
    
    if(*n->imag > (DESTE_TIPO_)0){
        if(CMPLX_(verificaApenasReal)(n)){
            strcat(c,"\n");
            printf(c,*n->real);
        }else if(CMPLX_(verificaApenasImag)(n)){
            strcat(c,"i\n");
            printf(c, *n->imag);
        }else{
            strcat(c,"+");
            strcat(c,DESTE_FORMATO_);
            strcat(c,"i\n");
            printf(c,*n->real, *n->imag);
        }
    }else{
        if(CMPLX_(verificaApenasReal)(n)){
            strcat(c,"\n");
            printf(c,*n->real);
        }else if(CMPLX_(verificaApenasImag)(n)){
            strcat(c,"i\n");
            printf(c,*n->imag);
        }else{
            strcat(c,DESTE_FORMATO_);
            strcat(c,"i\n");
            printf(c,*n->real, *n->imag);
        }
    }
}

void CMPLX_(tiraEspaco)(char* s) {
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