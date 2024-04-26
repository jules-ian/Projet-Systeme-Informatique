#ifndef ASSEMBLY_H
#define ASSEMBLY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define AT_SIZE 100

extern char* asm_table[AT_SIZE][4];
extern int at_top;

void add_instruction(char* a, int b, int c, int d);
void to_asm_file(FILE *asm_file);
void modify_jmp(int index, int modifier);
#endif /* ASSEMBLY_H */
