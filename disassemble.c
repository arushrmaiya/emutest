#include "disassemble.h"
#include <stdio.h>
#include <stdlib.h>

int openbuffer(int argc, char ** argv){
    FILE* f = fopen(argv[1], "rb");
    if(!f){
        printf("INVALID FILE");
        exit(1);
    }

    fseek(f, 0L, SEEK_END);
    int fsize = ftell(f);
    fseek(f, 0L, SEEK_SET);

    unsigned char* buffer = (char *)malloc(fsize);
    fread(buffer, fsize, 1, f);

    fclose(f);

    disassemble(buffer, 0);

    // int pc = 0;

    // while(pc < fsize){

    // }

}

void disassemble(unsigned char* buffer, int pc){
    unsigned char* code = &buffer;

    switch(*code){
        case 0x00: printf("NOP\n"); break;

    }
}

