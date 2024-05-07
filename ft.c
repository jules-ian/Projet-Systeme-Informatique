#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define FT_SIZE  128
#define F_SIZE   sizeof(Function)

//Structure d'une fonction qu'on stockera dans un tableau
typedef struct Function {
    char name[40];
    int index;
} Function;

Function function_table[FT_SIZE] = {"", 0};

/*Donne l'index du prochain element a inserer*/
int ft_top = 0;

int function_table_size(){
    return ft_top;
}

bool function_table_isEmpty() {
    return (ft_top == 0);
}

bool function_table_isFull() {
    return (ft_top == FT_SIZE);
}

void function_table_clear(){
    ft_top = 0;
}

void function_table_push(char name[40], int index) {
    Function function;
    strncpy(function.name, name, 40);
    function.index = index;
    if(function_table_isFull()){
        printf("[ERROR] - Full stack");
        exit(1);
    }else{
        function_table[ft_top] = function;
        ft_top++;
    }
}

Function function_table_get_function(int index) {
    if(index >= ft_top){
        printf("[ERROR] - No element at specified index");
        exit(1);
    }else{
        return function_table[index];
    }
}

int function_table_get_address(char name[40]){
    for(int i = function_table_size()-1; i >= 0; i--){
        if(strcmp(function_table_get_function(i).name, name) == 0){
            return function_table_get_function(i).index;
        }
    }
    return -1;
}

