#ifndef __RAM_HEADER__
#define __RAM_HEADER__
#include <stdint.h>
#include "types.h"










// More will be added in the future, like a way to simulate arbitrary RAM latency
typedef struct{
  WORD addr, in, out;
  int rw;     // 0 : read, 1 : write
  WORD data[33554432];  //32 MB RAM
}RAM;










#endif
