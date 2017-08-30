#include "types.h"
#include "ram.h"
#include <stdio.h>










void updateRAM (RAM* r){
  WORD addr = r->addr;
  WORD in   = r->in;
  int  rw   = r->rw;
  r->addr.u64 = 0;
  r->in.u64   = 0;
  r->rw       = 0;
  r->out.u64  = 0;

  if(addr.u64 > 33554432){
    printf("Invalid RAM Address!! %i\n", (int)addr.u64);
    return;
  }

  if(addr.u64 == 0){
    if(rw == 0) return;
    printf("NULL Write to RAM!!\n");
    return;
  }

  if(rw == 0)
    r->data[addr.u64] = in;     //Read Mode
  else
    r->out = r->data[addr.u64]; //Write Mode

}
