



%{
#include<stdio.h>
int nwords = 0;
%}

%%
[ \n]              ;
([a-zA-Z0-9]*[^a-zA-Z0-9 \n]+[^ \n]*)  ;
([a-zA-Z0-9])* {nwords++;} 
%%

int yywrap(void){
    return 1;
}
    
int main(){
    yyin= fopen("input.txt","r");
    /*To taken from input streams*/
    yylex();
    printf("Number of Words:");
    printf("%d\n",nwords);
    return 0;
}