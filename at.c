#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "st.c"
#define AT_SIZE 100

char* asm_table[AT_SIZE][4];
int at_top =0;

void add_instruction(char* a, int b, int c, int d) {
    print_stack();
    char *b_chaine;
    char *c_chaine;
    char *d_chaine;
    b_chaine = (char *)malloc(5 * sizeof(char));
    c_chaine = (char *)malloc(5 * sizeof(char));
    d_chaine = (char *)malloc(5 * sizeof(char));

    sprintf(b_chaine, "%d", b);
    sprintf(c_chaine, "%d", c);
    sprintf(d_chaine, "%d", d);
    asm_table[at_top][0] = a;
    asm_table[at_top][1] = b_chaine;
    asm_table[at_top][2] = c_chaine;
    asm_table[at_top][3] = d_chaine;
    at_top += 1;

    
}

void to_asm_file(FILE *asm_file){
    for(int i = 0; i < at_top; i++){
        for(int j = 0; j < 4; j++){
            fprintf(asm_file, "%s ", asm_table[i][j]);
        }
      fprintf(asm_file, "\n");
  }
}

void modify_jmp(int index) {
    char *at_chaine;
    at_chaine = (char *)malloc(5 * sizeof(char));
    sprintf(at_chaine, "%d", at_top);
    asm_table[index][2] = at_chaine;
    //free(at_chaine);
}