%{
#include <stdio.h>
#include <stdlib.h>
#include "st.c"

FILE *asm_file;
%}

%code provides{
  int yylex (void);
  void yyerror (const char *);
  }

%union {int nb; char s [40];}

%token tVOID tINT tIF tELSE tWHILE tPRINT tRETURN tADD tSUB tMUL tDIV tLT tGT tNE tEQ tGE tLE tASSIGN tAND tOR tNOT tSEMI tCOMMA tLPAR tRPAR tLBRACE tRBRACE tERROR
%token <s> tID
%token <nb> tNB
%type <nb> Expr 
%type <nb> Cond

%left tSEMI
%left tCOMMA
%left tADD tSUB
%left tMUL tDIV
%left tLT tGT tNE tEQ tGE tLE
%left tAND tOR tNOT



%start Programme
%%
  /* Est-ce qu'on doit gérer le tERROR */ 
Programme : 
    Fonc Programme
  | Fonc {fprintf(asm_file, "%s", "NOP 0 0 0\n");} // TODO : Ajouter instruction ASM NOP ??
  ;

Param : 
    tINT tID {push($2);}
  | tINT tID tCOMMA Param {push($2);}
  ;

Params : 
    %empty 
  | tVOID
  | Param
  ;

Arg : Expr | Arg tCOMMA Arg ;
Args : %empty | Arg ;

Instruction :
    Affectation
  | Declaration
  | While
  | If
  | Print
  | tRETURN Expr tSEMI

  ;



Affectation : 
    tID tASSIGN Expr tSEMI { printf("Assignement de %d à %s\n", $3, $1); print_stack(); fprintf(asm_file, "%s %d %d %d\n", "COP", get_index($1), size()-1, 0); pop(); } //On a assigné la valeur de Expr à tID donc on peut pop la mémoire de Expr
    ;



Declaration : 
    tINT tID tASSIGN Expr tSEMI {push($2); }               //int a=x;
  | tINT tID MultiDeclaration tSEMI   {;push($2);}        //int a,b = 1, z = 3;
  
  
MultiDeclaration : %empty {}| tCOMMA tID MultiDeclaration {push($2);} | tCOMMA tID tASSIGN Expr MultiDeclaration //TODO{}

  // print(variable);
Print : tPRINT tLPAR tID tRPAR tSEMI;

  // si c'est 0 c'est false si c'est autre chose c'est true
Cond : Expr {$$ = $1;} 
  | Expr tLT Expr   {$$ = $1 < $3;  pop();}
  | Expr tGT Expr   {$$ = $1 > $3;  pop();}
  | Expr tNE Expr   {$$ = $1 != $3; pop();}
  | Expr tEQ Expr   {$$ = $1 == $3; pop();}
  | Expr tGE Expr   {$$ = $1 >= $3; pop();}
  | Expr tLE Expr   {$$ = $1 <= $3; pop();}
  | Expr tAND Expr  {$$ = $1 && $3; pop();}
  | Expr tOR Expr   {$$ = $1 || $3; pop();}
  | tNOT Expr       {$$ = !$2;      pop();}
  ;





  //On autorise pas while()
While : tWHILE tLPAR Cond tRPAR tLBRACE PopStack IncrDepth Body tRBRACE DecrDepth ; // ATTENTION à quand faire le PopStack


 //On pop le stack pour enlever le tmp du if, puis on incrémente la profondeur parce que on rentre dans un nouveau bloc. 
If : 
    tIF tLPAR Cond tRPAR tLBRACE PopStack IncrDepth Body tRBRACE DecrDepth  //If sans else
  | tIF tLPAR Cond tRPAR tLBRACE PopStack IncrDepth Body tRBRACE DecrDepth  tELSE tLBRACE Body tRBRACE //if else
  | tIF tLPAR Cond tRPAR tLBRACE PopStack IncrDepth Body tRBRACE DecrDepth  tELSE If //if else if 
  ;

PopStack : %empty {pop();} 

IncrDepth : %empty  {incr_depth();}

DecrDepth : %empty  {decr_depth();}

Expr : 
    tID {push_tmp(); fprintf(asm_file, "%s %d %d %d\n", "COP", size()-1, get_index($1), 0);}
  | tNB  {push_tmp(); fprintf(asm_file, "%s %d %d %d\n", "AFC", size()-1, $1, 0);}
  | tSUB tNB {printf("-%d\n", $2);} %prec tMUL
  | tID tLPAR Args tRPAR {printf ("Appel de la fonction %s\n", $1); }
  | Expr tMUL Expr { printf("Mul : %d\n", $1 * $3); pop();} // TODO : Faire les instructions ASM pour Mul et autres OP
  | Expr tDIV Expr { printf("Div : %d\n", $1 / $3); pop();}
  | Expr tADD Expr { printf("Add : %d\n", $1 + $3); pop();}
  | Expr tSUB Expr { printf("Sub : %d\n", $1 - $3); pop();}
  ; 


  //On autorise de mettre un return dans une fonction void()
Body :
    %empty
  | Instruction Body
  ;

Fonc : 
     tINT  tID IncrDepth PushAdr PushVal tLPAR Params tRPAR tLBRACE IncrDepth Body DecrDepth tRBRACE DecrDepth
  |  tVOID tID IncrDepth PushAdr         tLPAR Params tRPAR tLBRACE IncrDepth Body DecrDepth tRBRACE DecrDepth
  ;

  // Error : tERROR {printf("ERREUR : Caractere inattendu");};

PushAdr : %empty {push_ADR();} 

PushVal : %empty {push_VAL();}

%%


void yyerror(const char *msg) {
  fprintf(stderr, "error: %s\n", msg);
  exit(1);
} 


int main(void) {
  asm_file = fopen("assembly.asm", "w");
    
  if (asm_file == NULL) {
      printf("Unable to create file.\n");
      exit(1);
  }

  print_stack();
  yyparse();
  print_stack();

  fclose(asm_file);
}
