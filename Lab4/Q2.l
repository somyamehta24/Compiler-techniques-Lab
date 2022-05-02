/*190001058
Somya Mehta*/

/*lex program to count scanf and printf*/
/* Definition Section */
%{
	#include<stdio.h>
	int sc = 0,pt=0;
%}

/* Rules Section*/
%%
"scanf"    {sc++;}
"printf"    {pt++;}
%%

int yywrap(void){}

int main(){
    yyin= fopen("input2.txt","r");
    yylex();
    printf("Number of scanf  %d\n",sc);
    printf("Number of printf  %d\n",pt);
    return 0;
}