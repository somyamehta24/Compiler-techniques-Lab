// 190001058
//  Somya Mehta
#include <stdio.h>
#include <string.h>
int ch, character = 0, line = 1, space = 0;
void display() {
    printf("\nNumber of lines = %d", line);
    printf("\nNumber of spaces = %d", space);
    printf("\nNumber of character = %d", character);
}
void main() {
    char str[80];
    FILE* fptr = fopen("input3.txt", "r");
    if (fptr == NULL) {
        printf("Error opening file \n");
        return;
    }
    // read from file
    fscanf(fptr, "%s", str);
    ch = fgetc(fptr);
    while (ch != EOF) {
        character++;
        // count spaces
        if (ch == ' ')
            space++;
        // count lines
        if (ch == '\n')
            line++;
        ch = fgetc(fptr);
    }
    fclose(fptr);
    display();
}