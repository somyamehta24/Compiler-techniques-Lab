#include <stdio.h>
#include <string.h>
int main() {
    char ch[10000];
    scanf("%s", ch);
    int n = strlen(ch);
    // counters for maintaing the count of vowels and consonents
    int no_of_vowels = 0, no_of_consonants = 0;
    for (int i = 0; i < n; i++) {
        if (ch[i] == 'A' || ch[i] == 'E' || ch[i] == 'I' || ch[i] == 'O' || ch[i] == 'U' || ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
            no_of_vowels++;
        else if ((ch[i] >= 'A' && ch[i] <= 'Z') || (ch[i] >= 'a' && ch[i] <= 'z'))
            no_of_consonants++;
    }
    printf("No of Vowels are: %d\n", no_of_vowels);
    printf("No of Consonents are: %d\n", no_of_consonants);
    return 0;
}
