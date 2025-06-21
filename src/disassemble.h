#ifndef DISASSEMBLE_H

#define DISASSEMBLE_H

int openbuffer(int argc, char* fname);

void disassemble(unsigned char* codebuffer, int pc);

#endif