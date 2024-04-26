%{
#include <stdio.h>
#include <stdlib.h>
//#include "st.c"
#include "at.c"

FILE *asm_file;
%}

%code provides{
  int yylex (void);
  void yyerror (const char *);
  }

%union {int nb; char s [40];}

%token tVOID tINT tELSE tWHILE tPRINT tRETURN tADD tSUB tMUL tDIV tLT tGT tNE tEQ tGE tLE tASSIGN tAND tOR tNOT tSEMI tCOMMA tLPAR tRPAR tLBRACE tRBRACE tERROR
%token <s> tID
%token <nb> tNB tIF
%type <nb> Expr 
%type <nb> Cond
%type <nb> DebutIf 

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
  | Fonc {add_instruction ("NOP",0, 0, 0);} 
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
    tID tASSIGN Expr tSEMI { printf("Assignement de %d à %s\n", $3, $1); add_instruction ("COP",get_index($1), size()-1, 0); pop();} //fprintf(asm_file, "%s %d %d %d\n", "COP", get_index($1), size()-1, 0); pop(); } //On a assigné la valeur de Expr à tID donc on peut pop la mémoire de Expr
    ;



Declaration : 
    tINT tID tASSIGN {push($2);} Expr tSEMI {add_instruction("COP", get_index($2), size()-1, 0); pop();}               //int a=x;
  | tINT tID MultiDeclaration tSEMI   {;push($2);}        //int a,b = 1, z = 3;
  
  
MultiDeclaration : %empty {}| tCOMMA tID MultiDeclaration {push($2);} | tCOMMA tID tASSIGN {push($2);} Expr MultiDeclaration {add_instruction("COP", get_index($2), size()-1, 0); pop();}

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
While : tWHILE tLPAR Cond tRPAR tLBRACE PopStack IncrDepth Body tRBRACE DecrDepth ; // ATTENTION à quand faire le PopStack //TODO les jmps / asm

DebutIf : 
    tIF tLPAR Cond tRPAR {add_instruction("JMF", size()-1, -1, 0); pop(); $<nb>$ = at_top - 1;} 
    tLBRACE IncrDepth Body tRBRACE DecrDepth {modify_jmp($<nb>5); $$ = $<nb>5;}JMF

//FinIf : %empty {modify_jmp($0);}

 //On pop le stack pour enlever le tmp du if, puis on incrémente la profondeur parce que on rentre dans un nouveau bloc. 
If : 
    DebutIf   //If sans else
  | DebutIf tELSE {add_instruction("JMP", 0, -1, 0);modify_jmp($<nb>1);$<nb>$ = at_top -1;} 
    tLBRACE IncrDepth Body tRBRACE DecrDepth {modify_jmp($<nb>3);}//if else
  ;



PopStack : %empty {pop();} 

IncrDepth : %empty  {incr_depth();}

DecrDepth : %empty  {decr_depth();}

Expr : 
    tID {push_tmp(); add_instruction ("COP",size()-1, get_index($1), 0); }
  | tNB  {push_tmp(); add_instruction ("AFC",size()-1, $1, 0);} //fprintf(asm_file, "%s %d %d %d\n", "AFC", size()-1, $1, 0);}
  | tSUB tNB {printf("-%d\n", $2);} %prec tMUL
  | tID tLPAR Args tRPAR {printf ("Appel de la fonction %s\n", $1); }
  | Expr tMUL Expr { add_instruction ("MUL",size()-2, size()-2, size()-1); pop();} //fprintf(asm_file, "%s %d %d %d\n", "MUL", size()-2, size()-2, size()-1); pop();} 
  | Expr tDIV Expr { add_instruction ("DIV",size()-2, size()-2, size()-1); pop();} //fprintf(asm_file, "%s %d %d %d\n", "DIV", size()-2, size()-2, size()-1); pop();}
  | Expr tADD Expr { add_instruction ("MUL",size()-2, size()-2, size()-1); pop();} //fprintf(asm_file, "%s %d %d %d\n", "ADD", size()-2, size()-2, size()-1); pop();}
  | Expr tSUB Expr { add_instruction ("MUL",size()-2, size()-2, size()-1); pop();} //fprintf(asm_file, "%s %d %d %d\n", "SUB", size()-2, size()-2, size()-1); pop();}
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

  to_asm_file(asm_file);

  fclose(asm_file);
}
