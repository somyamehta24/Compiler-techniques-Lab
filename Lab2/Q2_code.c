// Somya Mehta
// 190001058

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// check for operator
int checkOperator(char *charArr) {
    if (*charArr == '+' || *charArr == '-' || *charArr == '*' || *charArr == '/' || *charArr == '>' || *charArr == '<' || *charArr == '=')
        return 1;
    return 0;
}
// keywords
char keywords[32][10] = {
    "auto", "double", "int", "struct", "break", "else", "long",
    "switch", "case", "enum", "register", "typedef", "char",
    "extern", "return", "union", "const", "float", "short",
    "unsigned", "continue", "for", "signed", "void", "default",
    "goto", "sizeof", "voltile", "do", "if", "static", "while"};
int checkIdentifier(char *charArr) {
    int i, marker = 0;
    for (i = 0; i < 32; i++) {
        // for each keyword we check whether the name of the given string matches it or not
        if ((strcmp(keywords[i], charArr) == 0)) {
            marker = 1;
        }
    }
    if (marker == 1) {
        return 0;
    } else {
        marker = 0;
        // we check whether the first character is either _ or alphabet
        if ((charArr[0] == '_') || (isalpha(charArr[0]) != 0)) {
            for (i = 1; charArr[i] != '\0'; i++) {
                // if non alphabet and non number and non underscore is there
                if ((isalnum(charArr[i]) == 0) && (charArr[i] != '_')) {
                    marker = 1;
                }
            }
        } else {
            marker = 1;
        }
    }
    if (marker == 0) {
        return 1;
    } else {
        return 0;
    }
}

int checkKeyword(char *charArr) {
    // compare with each keyword
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], charArr) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // open the file where our input resides
    FILE *fptr = fopen("input2.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file\n");
        return 0;
    }
    char charArr[100], ch;
    while (fscanf(fptr, "%s", charArr) != EOF) {
        if (checkKeyword(charArr)) {
            printf("\n%s is a Keyword", charArr);
        } else if (checkIdentifier(charArr)) {
            printf("\n%s is an Identifier", charArr);
        } else if (checkOperator(charArr)) {
            printf("\n%s is an Operator", charArr);
        } else {
            printf("\n%s invalid token", charArr);
        }
    }
    fclose(fptr);
    return 0;
}