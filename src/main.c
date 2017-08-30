#include <stdlib.h>
#include <stdint.h>
#include "core.h"
#include "types.h"
#include "ram.h"










int main(){
  RAM*  ramunit = malloc(sizeof(RAM ));
  CORE* core    = malloc(sizeof(CORE));

  char* c = (char*)(&(ramunit->data));
  *c = "\x00\x00";

  while(1){
    updateCore(core, ramunit);
    updateRAM (ramunit);
  }

}
