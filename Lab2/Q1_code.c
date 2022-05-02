// 190001058
//  Somya Mehta
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// keywords in C language
char keywords[32][20] = {
    "auto", "double", "int", "struct", "break", "else", "long",
    "switch", "case", "enum", "register", "typedef", "char",
    "extern", "return", "union", "const", "float", "short",
    "unsigned", "continue", "for", "signed", "void", "default",
    "goto", "sizeof", "voltile", "do", "if", "static", "while"},
     str[100];
void check() {
    // open the file where our input resides
    FILE *fPtr = fopen("input1.txt", "r");
    if (fPtr == NULL) {
        printf("Error opening the file\n");
        return;
    }

    char str[100];
    fscanf(fPtr, "%s", str);
    int i, marker = 0;
    for (i = 0; i < 32; i++) {
        // for each keyword we check whether the name of the given string matches it or not
        if ((strcmp(keywords[i], str) == 0)) {
            marker = 1;
        }
    }
    if (marker == 1) {
        printf("\n%s is not a identifier because it's Keyword.", str);
    } else {
        marker = 0;
        // we check whether the first character is either _ or alphabet
        if ((str[0] == '_') || (isalpha(str[0]) != 0)) {
            for (i = 1; str[i] != '\0'; i++) {
                // if non alphabet and non number and non underscore is there
                if ((isalnum(str[i]) == 0) && (str[i] != '_')) {
                    marker = 1;
                }
            }
        } else {
            marker = 1;
        }
    }
    if (marker == 0) {
        printf("\n%s is an Identifier.", str);
    } else {
        printf("\n%s is Not an Identifier.", str);
    }
}
void main() {
    int i = 0, marker = 0;
    check();
}