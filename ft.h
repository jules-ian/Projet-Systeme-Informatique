#ifndef FT_H
#define FT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FT_SIZE  1024
#define F_SIZE   sizeof(Function)

// Structure of a function to be stored in an array
typedef struct Function {
    char name[40];
    int index;
} Function;

// Function table array
extern Function function_table[FT_SIZE];

// Index of the next element to be inserted
extern int ft_top;
extern int current_depth;

// Returns the size of the function table
int function_table_size();

// Checks if the function table is empty
bool function_table_isEmpty();

// Checks if the function table is full
bool function_table_isFull();

// Clears the function table
void function_table_clear();

// Pushes a function onto the function table
void function_table_push(char name[40]);

// Returns the Function at given index
Function function_table_get_function(int index);

// Returns the address of a given function name, -1 if the function is not found
int function_table_get_address(char name[40]);

#endif /* FT_H */
