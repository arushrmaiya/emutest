#ifndef DISASSEMBLE_H

#define DISASSEMBLE_H

int openbuffer(int argc, char* fname);

int disassemble(unsigned char* codebuffer, int pc);

#endif