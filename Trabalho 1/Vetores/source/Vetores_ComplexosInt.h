#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_
#undef CMPLX_
#undef VETORESC_H_INCLUDED
#undef VCOMPLEXOS_H_INCLUDED

#define DESTE_TIPO_ int
#define DESTE_FORMATO_ "%ld"
#define TIPADO_(TIPO) VC_I_ ## TIPO
#define CMPLX_(FUNCAO) I_ ## FUNCAO
#include "Vetores_Complexos.h"
#include "Complexos.h"