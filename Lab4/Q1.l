/*
	190001058
	Somya Mehta
*/
/*lex program to change the name of the string of characters*/
/* Definition Section */
%{
    #include<stdio.h>
	#include <stdlib.h> 
	#include<math.h> 
	#include <time.h> 
    int random_no=1;
	void modify(char*word)
	{
		printf("\t\tInput stream:-%s\n\n\t\tOutput stream:-",word);
		int length=strlen(word);
		for(int i=0;i<length;i++)
		{
			if(random_no==25)random_no=1;
			if(word[i]>='a'&& word[i]<='z')
			{
				char ch=(word[i]-'a'+random_no)%26+'a';
				printf("%c",ch);
			}
			else
			{
				char ch=(word[i]-'A'+random_no)%26+'A';
				printf("%c",ch);
			}
			random_no++;
		}
	}
%}

/* Rules Section*/
%%
([a-zA-Z]*) {modify(yytext);}
%%

int yywrap(void){return 1;}

int main()
{   
    extern FILE* yyin;
	 srand( time(0)); 
	random_no=rand()%5+1;
	printf("Random No: -> %d\n",random_no);
    yyin = fopen("input1.txt","r");
    yylex();
	printf("\n\n");
    return 0;
}