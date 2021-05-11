#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_ 
#undef COMPLEXOS_H_INCLUDED

#define DESTE_TIPO_ Racional_pt
#define DESTE_FORMATO_ "%ld/%ld"
#define TIPADO_(THING) R_ ## THING
#include "Complexos.h"