#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_
#undef CMPLX_
#undef VETORESC_H_INCLUDED
#undef VCOMPLEXOS_H_INCLUDED

#define DESTE_TIPO_ double
#define DESTE_FORMATO_ "%.2f"
#define TIPADO_(TIPO) VC_D_ ## TIPO
#define CMPLX_(FUNCAO) D_ ## FUNCAO
#include "Vetores_Complexos.h"
#include "Complexos.h"