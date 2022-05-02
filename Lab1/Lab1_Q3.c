#include <stdio.h>
#include <string.h>
int main() {
    char line[100000];
    // for taking input of line with spaces
    fgets(line, 100000, stdin);
    int n = strlen(line);
    int p = 0;
    n--;
    // if spaces are there in starting then we need to remove them
    for (int i = 0; i < n; i++) {
        if (line[i] == ' ') {
            p++;
            continue;
        } else
            break;
    }

    // if spaces are there in ending then we need to remove them
    while (line[n - 1] == ' ')
        n--;
    // printf("\n");
    // if initial characters are / & / then it's a comment
    if ((line[p] == '/' && line[p + 1] == '/')) {
        printf("Yes the line  is a comment\n");
        return 0;
    }
    // when initial characters are / & * and end characters are * & / then it is a comment
    if ((line[p] == '/' && line[p + 1] == '*' && line[n - 2] == '*' && line[n - 1] == '/')) {
        printf("Yes the line  is a comment\n");
        return 0;
    }
    printf("No The string is not any comment\n");
    return 0;
}