#ifndef __CORE_HEADER__
#define __CORE_HEADER__
#include <stdint.h>
#include "types.h"
#include "ram.h"










// More will be added as I add more features to this thing.
typedef struct{
  WORD registers [8];
  int ip;
}CORE;










void updateCore(CORE*, RAM*);









#endif
