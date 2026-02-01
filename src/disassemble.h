#include <stdint.h>

#ifndef DISASSEMBLE_H

#define DISASSEMBLE_H

int openbuffer(int argc, char* fname);

int disassemble(unsigned char* codebuffer, int pc);

struct ConditionCodes_t {    
    uint8_t    z:1;    
    uint8_t    s:1;    
    uint8_t    p:1;    
    uint8_t    cy:1;    
    uint8_t    ac:1;    
    uint8_t    pad:3;    
   };    

struct regfile_t{
    uint8_t    a;    
    uint8_t    b;    
    uint8_t    c;    
    uint8_t    d;    
    uint8_t    e;    
    uint8_t    h;    
    uint8_t    l;    
   };


struct State8080_t {  
    struct      regfile_t             regfile;  
    uint16_t    sp;    
    uint16_t    pc;    
    uint8_t     *memory;    
    struct      ConditionCodes_t      cc;    
    uint8_t     int_enable;    
   };    

void invalInst(struct State8080_t * state);

#endif