#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_ 
#undef COMPLEXOS_H_INCLUDED

#define DESTE_TIPO_ double
#define DESTE_FORMATO_ "%.2f"
#define TIPADO_(THING) D_ ## THING
#include "Complexos.h"