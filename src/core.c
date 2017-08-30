#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "types.h"
#include "ram.h"
#include "core.h"











//ISA Subject to Change Radically at any time
void updateCore(CORE* c, RAM* r){
  WORD instruction = r->data[c->ip];   //Until there's a proper instruction cache, etc.

  int regA =  instruction.u64 & 0x07;
  int regB = (instruction.u64 & 0x38) >> 3;
  int op   =  instruction.u64 >> 6;

  c->ip++;

  switch(op){
    case 0x00: //NOP
    break;

    case 0x01: //MOV
    c->registers[regA] = c->registers[regB];
    break;

    case 0x02: //LOD
    //Add later
    break;

    case 0x03: //STR
    //Add later
    break;

    case 0x04: //IADD
    c->registers[regA].i64 += c->registers[regB].i64;
    break;

    case 0x05: //ISUB
    c->registers[regA].i64 -= c->registers[regB].i64;
    break;

    case 0x06: //IMUL
    c->registers[regA].i64 *= c->registers[regB].i64;
    break;

    case 0x07:{ //IDIV / IMOD
      WORD ia = c->registers[regA];
      WORD ib = c->registers[regB];
      c->registers[regA].i64 = ia.i64 / ib.i64;
      c->registers[regB].i64 = ia.i64 % ib.i64;
    }break;

    case 0x08: //UADD
    c->registers[regA].u64 += c->registers[regB].u64;
    break;

    case 0x09: //USUB
    c->registers[regA].u64 -= c->registers[regB].u64;
    break;

    case 0x0A: //UMUL
    c->registers[regA].u64 *= c->registers[regB].u64;
    break;

    case 0x0B:{ //UDIV / UMOD
      WORD ua = c->registers[regA];
      WORD ub = c->registers[regB];
      c->registers[regA].u64 = ua.u64 / ub.u64;
      c->registers[regB].u64 = ua.u64 % ub.u64;
    }break;

    case 0x0C: //FADD
    c->registers[regA].f64 += c->registers[regB].f64;
    break;

    case 0x0D: //FSUB
    c->registers[regA].f64 -= c->registers[regB].f64;
    break;

    case 0x0E: //FMUL
    c->registers[regA].f64 *= c->registers[regB].f64;
    break;

    case 0x0F:{ //FDIV / FMOD
      WORD fa = c->registers[regA];
      WORD fb = c->registers[regB];
      c->registers[regA].f64 = fa.f64 / fb.f64;
      c->registers[regB].f64 = fmod(fa.f64, fb.f64);
    }break;

    case 0x10:  //JNGF
      c->ip = (c->registers[regA].i64 <  0)? c->registers[regB].i64 : c->ip;
    break;

    case 0x11:  //JPSF
      c->ip = (c->registers[regA].i64 >  0)? c->registers[regB].i64 : c->ip;
    break;

    case 0x12:  //JZRF
      c->ip = (c->registers[regA].i64 == 0)? c->registers[regB].i64 : c->ip;
    break;

    case 0x13:  //JNZF
      c->ip = (c->registers[regA].i64 != 0)? c->registers[regB].i64 : c->ip;
    break;

    case 0x14:  //JNGF
      c->ip = (c->registers[regA].i64 <  0)? c->registers[regB].i64 : c->ip;
    break;

    case 0x15:  //JPSF
      c->ip = (c->registers[regA].i64 >  0)? c->registers[regB].i64 : c->ip;
    break;

    case 0x16:  //JZRF
      c->ip = (c->registers[regA].i64 == 0)? c->registers[regB].i64 : c->ip;
    break;

    case 0x17:  //JNZF
      c->ip = (c->registers[regA].i64 != 0)? c->registers[regB].i64 : c->ip;
    break;

    case 0x18:  //J
      c->ip = c->registers[regA].i64;
    break;

    case 0x19:  //IINC
      c->registers[regA].i64++;
    break;

    case 0x1A:  //UINC
      c->registers[regA].u64++;
    break;

    case 0x1B:  //FINC
      c->registers[regA].f64++;
    break;


    case 0xFE:  //Print Char
      printf("%c", (char)c->registers[regA].i64);
    break;

    case 0xFF:  //Print Int
      printf("%i", (int) c->registers[regA].i64);
    break;

    default: {
      printf("Invalid Opcode: %i\n", (int)op);
      exit(-1);
    }
  }
}
