#include <stdio.h>
#include <stdlib.h>
#include "disassemble.h"

int openbuffer(int argc, char* fname){

    printf("hi\n");
    FILE* f = fopen(fname, "rb");
    if(!f){
        printf("INVALID FILE");
        exit(1);
    }
    return 0;

}

void disassemble(unsigned char* buffer, int pc){
    // unsigned char* code = &buffer;

    // switch(*code){
    //     case 0x00: printf("NOP\n"); break;

    // }
    return;
}

