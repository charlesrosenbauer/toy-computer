#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "core.h"
#include "types.h"
#include "ram.h"










int main(){
  RAM*  ramunit = malloc(sizeof(RAM ));
  CORE* core    = malloc(sizeof(CORE));

  for(int i = 0; i < 33554432; i++)
    ramunit->data[i].u64 = 0;

  for(int i = 0; i < 8; i++)
    core->registers[i].i64 = 0;

  char* c = (char*)(&(ramunit->data));
  //Simple Hardcoded Program For Now
  c[ 0] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[ 1] = " \x00\x00\x00\x00\x00\x00\x04\x80";
  c[ 2] = " \x00\x00\x00\x00\x00\x00\x04\x80";
  c[ 3] = " \x00\x00\x00\x00\x00\x00\x03\x00";
  c[ 4] = " \x00\x00\x00\x00\x00\x00\x03\x00";
  c[ 5] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[ 6] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[ 7] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[ 8] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[ 9] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[10] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[11] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[12] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[13] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[14] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[15] = " \x00\x00\x00\x00\x00\x00\x00\x00";
  c[16] = " \x00\x00\x00\x00\x00\x00\x04\x81";
  c[17] = " \x00\x00\x00\x00\x00\x00\x7F\x81";
  c[18] = " \x00\x00\x00\x00\x00\x00\x77\x80";
  c[19] = " \x00\x00\x00\x00\x00\x00\x00\x90";
  c[20] = " \x00\x00\x00\x00\x00\x00\x02\x91";
  c[21] = " \x00\x00\x00\x00\x00\x00\x08\x0A";
  c[22] = " \x00\x00\x00\x00\x00\x00\x99\x99";
  c[23] = " \x00\x00\x00\x00\x00\x00\x00\x00";

  core->ip = 1;

  while(1){
    updateCore(core, ramunit);
    updateRAM (ramunit);
  }
  return 0;
}
