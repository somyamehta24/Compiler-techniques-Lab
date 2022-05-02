/*Somya Mehta*/
/*190001058*/


%{
#include<stdio.h>
int sum,singleComment,multiComment,mark=0;
%}


/*For single line comment: // */
%%
"//".*         {if(mark==0)singleComment++;}
"/*"           {if(mark==0)mark=1;}
.              {}
"\n"           {}
"*/"           {if(mark==1){mark=0,multiComment++;}}
%%

int yywrap(void){
    return 1;
}

int main(){
    yyin= fopen("input.txt","r");
    yyout=fopen("output.txt","w");
    yylex();
    sum=singleComment+multiComment;
    printf("Number of Comments:");
    printf("%d\n",sum);
    return 0;
}