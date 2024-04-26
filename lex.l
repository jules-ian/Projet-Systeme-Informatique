/*
Jules-Ian Barnavon
Matis Ramara
*/

%{
#include "parser.tab.h"
#include <stdio.h>
#include <stdlib.h>
%}

%option noyywrap
%option noinput
%option nounput

%%

[ \t\n] ;
[/][*](.|\n)*[*][/] ;
"//".*[\n] ;


void {return tVOID;}
int {return tINT;}
if {return tIF;}
else {return tELSE;}
while {return tWHILE;}
print {return tPRINT;}
return {return tRETURN;}

[+] {return tADD;}
[-] {return tSUB;}
[*] {return tMUL;}
[/] {return tDIV;}
[<] {return tLT;}
[>] {return tGT;}
"!=" {return tNE;}
"==" {return tEQ;}
">=" {return tGE;}
"<=" {return tLE;}
[=] {return tASSIGN;}
"&&" {return tAND;}
"||" {return tOR;}
[!] {return tNOT;}
[;] {return tSEMI;}
[,] {return tCOMMA;}
[(] {return tLPAR;}  
[)] {return tRPAR;}
[{] {return tLBRACE;}
[}] {return tRBRACE;}


[a-zA-Z][a-zA-Z0-9]*  {strncpy(yylval.s, yytext, strlen(yytext)+1);  return tID;} //mettre longueur maximale

0x[0-9a-f]+ {yylval.nb = strtol((yytext+2),NULL,16); return tNB;}
[0-9]+ {yylval.nb = atoi(yytext); return tNB;}

  /*
  [a-zA-Z][a-zA-Z0-9]* printf("tID: '%s'\n",yytext);

  0x[0-9a-f]+ printf("tNB: '%ld[%s]'\n", strtol((yytext+2),NULL,16),yytext );
  [0-9]+ printf("tNB: '%s[0x%x]'\n",yytext ,(unsigned int) strtol(yytext,NULL,10) );
  */

. {return tERROR;}

%%

 /*int main(int argc, char **argv) {
  if (argc != 2) {
    fprintf(stderr, "usage: %s filename\n", argv[0]);
    exit(1);
  } 
  yyin = fopen(argv[1], "r");
  if (!yyin) {
    fprintf(stderr, "invalid filename: %s\n", argv[1]);
    exit(2);
  }
  yylex();
  fclose(yyin);
  return 0;
} */
