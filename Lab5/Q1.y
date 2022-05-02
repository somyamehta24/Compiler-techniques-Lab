/* Yacc part*/
%{

    #include<stdio.h>
int yyerror();
    int valid=1;   

%}

%token A B NL

%%
S : a b NL {printf("\n\n\t\tvalid string\n");
              exit(0); }
;

a :   {}
    | A a    {}
    ;
b :  {}
    | B b    {}
    ;

%%

int yyerror()

{

    valid=0;

    printf("\nInvalid expression!\n");

    return 0;

}

int main()

{

    printf("\nEnter the expression:\n");

    yyparse();

    if(valid)

    {

        printf("\nValid expression!\n");

    }

}
/* S:- AB NL 
    A->aA 
    A->Eps
    B->bB 
    B->Eps
*/