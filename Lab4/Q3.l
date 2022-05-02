/*
	190001058
	Somya Mehta
	Write a LEX program to count the number of
	(a) Positive and Negative integers
	(b) Positive and Negative fractions i.e. whether the given number is positive
		integer, negative integer, positive fraction or negative fraction.
*/
/* Definition Section */
%{
    #include<stdio.h>
	#include <stdlib.h> 
    int pos_int=0,neg_int=0,pos_fract=0,neg_fract=0;  
%}

/* Rules Section*/
%%
[+]?[0-9]+ {pos_int++;}
[-][0-9]+ {neg_int++;}
[+]?[0-9]+[\/|\.][0-9]+ {pos_fract++;}
[-][0-9]+[\/|\.][0-9]+ {neg_fract++;}
. {}
%%

int yywrap(void){return 1;}

int main()
{   
    extern FILE* yyin;
    yyin = fopen("input3.txt","r");
    yylex();
    printf("No. of Positive integers: %d\n\n No. of Negative integers: %d\n\n No. of Positive fractions: %d\n No. of Negative fractions: %d\n",pos_int,neg_int,pos_fract,neg_fract);
	printf("\n\n");
    return 0;
}