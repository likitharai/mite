#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

int isPalindrome(char str[]);

int main() {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    if (isPalindrome(str)) {
        printf("Yes, it's a palindrome.\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }

    return 0;
}

int isPalindrome(char str[]) {
    int len = strlen(str);
    char reversed[MAX_LENGTH];

   
    for (int i = 0; i < len; i++) {
        reversed[i] = str[len - 1 - i];
    }
    reversed[len] = '\0';

   
    for (int i = 0; i < len; i++) {
        if (tolower(str[i]) != tolower(reversed[i])) {
            return 0;
        }
    }
    return 1;
}
