#ifndef ST_H
#define ST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ST_SIZE  1024
#define S_SIZE   sizeof(Symbol)

// Structure of a symbol to be stored in an array
typedef struct Symbol {
    char name[40];
    int depth;
} Symbol;

// Symbol table array
extern Symbol symbol_table[ST_SIZE];

// Index of the next element to be inserted
extern int top;
extern int current_depth;

// Returns the size of the symbol table
int size();

// Checks if the symbol table is empty
bool isEmpty();

// Checks if the symbol table is full
bool isFull();

// Clears the symbol table
void clear();

// Pushes a symbol onto the symbol table
void push(char name[40]);

// Pushes a symbol onto the symbol table
void push_symbol(Symbol symbol);

// Pushes a temporary symbol onto the symbol table
void push_tmp();

// Pushes an address symbol onto the symbol table
void push_ADR();

// Pushes a value symbol onto the symbol table
void push_VAL();

// Pops a symbol from the symbol table
char* pop();

// Pops a symbol from the symbol table
Symbol pop_symbol();

// Peeks at the top symbol of the symbol table
char* peek();

// Gets a symbol from the symbol table at the specified index
char* get(int index);

// Gets a symbol from the symbol table at the specified index
Symbol get_symbol(int index);

// Returns the index of a given Symbol name, -1 if the Symbol is not found
int get_index(char name[40]);

// Increments the current depth
void incr_depth();

// Decrements the current depth
void decr_depth();

// Prints a symbol
void print_symbol(Symbol s);

// Prints the symbol table
void print_stack();

#endif /* ST_H */
