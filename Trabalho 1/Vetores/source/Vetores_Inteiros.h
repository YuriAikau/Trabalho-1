#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_ 
#undef VETORES_H_INCLUDED

#define DESTE_TIPO_ int
#define DESTE_FORMATO_ "%d"
#define TIPADO_(THING) VI_ ## THING
#include "Vetores.h"