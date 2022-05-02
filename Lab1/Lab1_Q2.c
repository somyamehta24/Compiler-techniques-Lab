#include <stdio.h>
#include <string.h>
int main() {
    // input string
    char ch[10000];
    scanf("%s", ch);
    int n = strlen(ch);
    // keywords in C language
    char keywords[32][20] = {
        "auto", "double", "int", "struct", "break", "else", "long",
        "switch", "case", "enum", "register", "typedef", "char",
        "extern", "return", "union", "const", "float", "short",
        "unsigned", "continue", "for", "signed", "void", "default",
        "goto", "sizeof", "voltile", "do", "if", "static", "while"};
    // Comparing the string with all the keywords
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], ch) == 0) {
            printf("Yes it's same as the keyword- %s\n", keywords[i]);
            return 0;
        }
    }
    printf("No The string is not any keyword\n");
    return 0;
}