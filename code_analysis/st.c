#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ST_SIZE  1024
#define S_SIZE   sizeof(Symbol)

//Structure d'un symbole qu'on stockera dans un tableau
typedef struct Symbol {
    char name[40];
    //char type[20];
    int depth;
} Symbol;

Symbol symbol_table[ST_SIZE] = {"", 0};

/*Donne l'index du prochain element a inserer*/
int top = 0;
int current_depth = 0;

int size(){
    return top;
}

bool isEmpty() {
    return (top == 0);
}

bool isFull() {
    return (top == ST_SIZE);
}

void clear(){
    top = 0;
}

void push(char name[40]) {
    //printf("push   %s\n", name);
    Symbol symbol;
    symbol.depth = current_depth;
    strncpy(symbol.name, name, 40);
    
    if(isFull()){
        printf("[ERROR] - Full stack");
        exit(1);
    }else{
        symbol_table[top] = symbol;
        top++;
    }
}

void push_symbol(Symbol symbol) {    
    //printf("push symb\n");
    if(isFull()){
        printf("[ERROR] - Full stack");
        exit(1);
    }else{
        symbol_table[top] = symbol;
        top++;
    }
}

void push_tmp() {
    //printf("push tmp\n");
    char num[5];
    char nameTmp[40] = "@TMP";
    sprintf(num, "%d", top);
    strncat(nameTmp, num, sizeof(num));
    push(nameTmp);
}



void push_ADR() {
    char name[40] = "@ADR";
    push(name);
}

void push_VAL() {
    char name[40] = "@VAL";
    push(name);
}


char* pop() {
    if(isEmpty()){
        printf("[ERROR] - Empty stack");
        exit(1);
    }else{
        return symbol_table[--top].name;
    }
}

Symbol pop_symbol() {
    if(isEmpty()){
        printf("[ERROR] - Empty stack");
        exit(1);
    }else{
        return symbol_table[--top];
    }
}

char* peek() {
    return symbol_table[top-1].name;
}

char* get(int index) {
    if(index >= top){
        printf("[ERROR] - No element at specified index");
        exit(1);
    }else{
        return symbol_table[index].name;
    }
}

Symbol get_symbol(int index) {
    if(index >= top){
        printf("[ERROR] - No element at specified index");
        exit(1);
    }else{
        return symbol_table[index];
    }
}

int get_index(char name[40]){
    for(int i = size()-1; i >= 0; i--){
        if(strcmp(get_symbol(i).name, name) == 0){
            return i;
        }
    }
    return -1;
}

void incr_depth(){
    current_depth++;
}

void decr_depth(){ // removes all the symbols of the current depth before decrementing the depth
    if(isEmpty() || current_depth == 0){
        printf("[ERROR] - Depth is already 0");
        exit(1);
    }

    Symbol symbol;
    do {
        symbol = pop_symbol();
    } while (!isEmpty() && (symbol.depth == current_depth));
    
    push_symbol(symbol);
    current_depth--;
}

void print_symbol(Symbol s){
    printf("%s : %d\n", s.name, s.depth);
}

void print_stack(){
    int stack_top = top;
    printf("========== Printing Symbol Table [%d] elements ==========\n", size());
    while(stack_top > 0){
        print_symbol(get_symbol(--stack_top));
    }
    printf("========== END ==========\n");
}