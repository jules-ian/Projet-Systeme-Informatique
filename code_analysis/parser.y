%{
#include <stdio.h>
#include <stdlib.h>
//#include "st.c"
#include "at.c"
#include "ft.c"

FILE *asm_file;
char ADRname[40] = "@ADR";
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
%type <nb> While 

%left tSEMI
%left tCOMMA
%left tADD tSUB
%left tMUL tDIV
%left tLT tGT tNE tEQ tGE tLE
%left tAND tOR tNOT



%start Programme
%%

Programme : 
    Fonc Programme
  | Fonc {add_instruction ("NOP",0, 0, 0);} 
  ;

Fonc : 
     tINT  tID {function_table_push($2, at_top); $<nb>1 = atoi(pop_symbol().name);} IncrDepth PushAdr PushVal tLPAR Params tRPAR tLBRACE IncrDepth Body Return DecrDepth tRBRACE DecrDepth {pop();  add_instruction("JMP", $<nb>1, 0, 0);pop();}
  |  tVOID tID {function_table_push($2, at_top);} IncrDepth PushAdr         tLPAR Params tRPAR tLBRACE IncrDepth Body        DecrDepth tRBRACE DecrDepth
  ;

PushAdr : %empty {push_ADR();} 

PushVal : %empty {push_VAL();}

IncrDepth : %empty  {incr_depth();}

DecrDepth : %empty  {decr_depth();}


Params : 
    %empty 
  | tVOID
  | Param
  ;


Param : 
    tINT tID {push($2);}
  | tINT tID tCOMMA Param {push($2);}
  ;


Body :
    %empty
  | Instruction Body
  ;
Instruction :
    Affectation
  | Declaration
  | While
  | If
  | Print
  ;



Affectation : 
    tID tASSIGN Expr tSEMI { printf("Assignement de %d à %s\n", $3, $1); add_instruction ("COP",get_index($1), size()-1, 0); pop();} //fprintf(asm_file, "%s %d %d %d\n", "COP", get_index($1), size()-1, 0); pop(); } //On a assigné la valeur de Expr à tID donc on peut pop la mémoire de Expr
    ;

Expr : 
    tID {push_tmp(); add_instruction ("COP",size()-1, get_index($1), 0); }
  | tNB  {push_tmp(); add_instruction ("AFC",size()-1, $1, 0);} 
  //| tSUB tNB {printf("-%d\n", $2);} %prec tMUL 
  //| tID tLPAR {$<nb>2 = size(); push_ADR(); push_VAL();} Args tRPAR {add_instruction("JMP", function_table_get_address($1), 0, 0); push("Adresse de retour");}
  | Expr tMUL Expr { add_instruction ("MUL",size()-2, size()-2, size()-1); pop();} 
  | Expr tDIV Expr { add_instruction ("DIV",size()-2, size()-2, size()-1); pop();} 
  | Expr tADD Expr { add_instruction ("ADD",size()-2, size()-2, size()-1); pop();} 
  | Expr tSUB Expr { add_instruction ("SUB",size()-2, size()-2, size()-1); pop();} 
  ; 

Arg : Expr | Arg tCOMMA Arg ;
Args : %empty | Arg ;

Declaration : 
    tINT tID tASSIGN {push($2);} Expr tSEMI {add_instruction("COP", get_index($2), size()-1, 0); pop();}               //int a=x;
  | tINT tID MultiDeclaration tSEMI   {;push($2);}        //int a,b = 1, z = 3;
  
  
MultiDeclaration : %empty {}| tCOMMA tID MultiDeclaration {push($2);} | tCOMMA tID tASSIGN {push($2);} Expr MultiDeclaration {add_instruction("COP", get_index($2), size()-1, 0); pop();}

//On autorise pas while()
While : 
  tWHILE tLPAR {$<nb>$ = at_top;} Cond tRPAR {add_instruction("JMF", size()-1, -1, 0); pop(); $<nb>$ = at_top - 1;} 
  tLBRACE IncrDepth Body tRBRACE DecrDepth {add_instruction("JMP", $<nb>3, 0, 0); modify_jmf($<nb>6); $$ = $<nb>6;} ; 

DebutIf : 
    tIF tLPAR Cond tRPAR {add_instruction("JMF", size()-1, -1, 0); pop(); $<nb>$ = at_top - 1;} 
    tLBRACE IncrDepth Body tRBRACE DecrDepth {modify_jmf($<nb>5); $$ = $<nb>5;}


//On pop le stack pour enlever le tmp du if, puis on incrémente la profondeur parce que on rentre dans un nouveau bloc. 
If : 
    DebutIf   //If sans else
  | DebutIf tELSE {add_instruction("JMP", -1, 0, 0);modify_jmf($<nb>1);$<nb>$ = at_top -1;} 
    tLBRACE IncrDepth Body tRBRACE DecrDepth {modify_jmp($<nb>3);}//if else
  ;
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










  // print(variable);
Print : tPRINT tLPAR tID tRPAR tSEMI;


Return : tRETURN Expr tSEMI {add_instruction ("COP",size()-1, get_index(ADRname), 0); pop(); add_instruction ("RET",0, 0, 0);};

  // Error : tERROR {printf("ERREUR : Caractere inattendu");};






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
