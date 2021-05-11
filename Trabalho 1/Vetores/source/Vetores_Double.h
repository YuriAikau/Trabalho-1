#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_ 
#undef VETORES_H_INCLUDED

#define DESTE_TIPO_ double
#define DESTE_FORMATO_ "%.2f"
#define TIPADO_(THING) VD_ ## THING
#include "Vetores.h"