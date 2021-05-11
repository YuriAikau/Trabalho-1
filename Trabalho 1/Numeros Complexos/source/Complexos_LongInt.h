#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_ 
#undef COMPLEXOS_H_INCLUDED

#define DESTE_TIPO_ long int
#define DESTE_FORMATO_ "%ld"
#define TIPADO_(THING) LI_ ## THING
#include "Complexos.h"