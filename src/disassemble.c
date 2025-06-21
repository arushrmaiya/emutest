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

    while(pc < fsize){
        
    }
    return 0;

}

void disassemble(unsigned char* buffer, int pc){

    return;
}

