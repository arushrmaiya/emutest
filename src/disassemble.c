#include <stdio.h>
#include <stdlib.h>
#include "disassemble.h"

int openbuffer(int argc, char* fname){

    FILE* f = fopen(fname, "rb");
    if(!f){
        printf("INVALID FILE");
        exit(1);
    }

    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    unsigned char* buffer = (unsigned char *)malloc(fsize*sizeof(unsigned char));
    
    int pc = 0;

    fread(buffer, fsize, 1, f);

    while(pc <fsize){
        pc += disassemble(buffer, pc);

    }

    // disassemble(buffer, 0);

    // free((void *)buffer);

    return 0;

}

int disassemble(unsigned char* buffer, int pc){
    // printf("%c\n", buffer[pc]);

    unsigned char hx = buffer[pc];

    int opbytes = 1;

    switch(hx){
        case 0x00: printf("NOP\n"); break;
        case 0x01: printf("LXI B,D16\n"); opbytes = 3; break;
        case 0x02: printf("STAX B\n"); break;
        case 0x03: printf("INX B\n"); break;
        case 0x04: printf("INR B\n"); break;
        case 0x05: printf("DCR B\n"); break;
        case 0x06: printf("MVI B, D8\n"); opbytes = 2; break;
        case 0x07: printf("RLC\n"); break;
        case 0x09: printf("DAD B\n"); break;
        case 0x0a: printf("LDAX B\n"); break;
        case 0x0b: printf("DCX B\n"); break;
        case 0x0c: printf("INR C\n"); break;
        case 0x0d: printf("DCR C\n"); break;
        case 0x0e: printf("MVI C, D8\n"); opbytes = 2; break;
        case 0x0f: printf("RRC\n"); break;

        case 0x11: printf("LXI D, D16\n"); opbytes = 3; break;
        case 0x12: printf("STAX D\n"); break;
        case 0x13: printf("INX D\n"); break;
        case 0x14: printf("INR D\n"); break;
        case 0x15: printf("DCR D\n"); break;
        case 0x16: printf("MVI D, D8 n"); opbytes = 2; break;
        case 0x17: printf("RAL \n"); break;
        case 0x19: printf("DAD D\n"); break;
        case 0x1a: printf("LDAX D\n"); break;
        case 0x1b: printf("DCX D\n"); break;
        case 0x1c: printf("INR E\n"); break;
        case 0x1d: printf("DCR E\n"); break;
        case 0x1e: printf("MVI E, D8\n"); opbytes = 2; break;
        case 0x1f: printf("RAR\n"); break;

        case 0x21: printf("LXI H, D16\n"); opbytes = 3; break;
        case 0x22: printf("SHLD adr\n"); opbytes = 3; break;
        case 0x23: printf("INX H\n"); break;
        case 0x24: printf("INR H\n"); break;
        case 0x25: printf("DCR H\n"); break;
        case 0x26: printf("MVI H, D8\n"); opbytes = 2; break;
        case 0x27: printf("DAA\n"); break;
        case 0x29: printf("DAD H\n"); break;
        case 0x2a: printf("LHLD adr\n"); opbytes = 3; break;
        case 0x2b: printf("DCX H\n"); break;
        case 0x2c: printf("INR L\n"); break;
        case 0x2d: printf("DCR L\n"); break;
        case 0x2e: printf("MVI L, D8\n"); opbytes = 2; break;
        case 0x2f: printf("CMA\n"); break;

        case 0x31: printf("LXI SP, D16\n"); opbytes = 3; break;
        case 0x32: printf("STA adr\n"); opbytes = 3; break;
        case 0x33: printf("INX SP\n"); break;
        case 0x34: printf("INR M\n"); break;
        case 0x35: printf("DCR M\n"); break;
        case 0x36: printf("MVI M, D8\n"); opbytes = 2; break;
        case 0x37: printf("STC\n"); break;
        case 0x39: printf("DAD SP\n"); break;
        case 0x3a: printf("LDA adr\n"); opbytes = 3; break;
        case 0x3b: printf("DCX SP\n"); break;
        case 0x3c: printf("INR A\n"); break;
        case 0x3d: printf("DCR A\n"); break;
        case 0x3e: printf("MVI A, D8\n"); opbytes = 2; break;
        case 0x3f: printf("CMC\n"); break;

        default: printf("Invalid\n"); break;
    }
    return opbytes;
}

