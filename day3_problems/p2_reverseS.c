#include <stdio.h>
#include <string.h>
void reverse(char word[], int length)
{
    for (int i=0;i<length/2;i++) {
        char temp=word[i];
        word[i]=word[length-i-1];
        word[length-i-1]=temp;
    }
}

void reverseword(char str[]) {
    char word[100];
    int i;
    int wordIndex=0;
    int length=strlen(str);

    for (i=0;i<=length;i++) {
        if (str[i]!=' ' && str[i]!='\0') {
            word[wordIndex++]=str[i];
        } else {
            if (wordIndex>0) {
                word[wordIndex]='\0';
                reverse(word,wordIndex);
                for (int k=0;k<wordIndex;k++) {
                    str[i-wordIndex+k]=word[k];
                }
                wordIndex=0;
            }
            str[i]=' ';
        }
    }
}

int main() {
    char str[100];

    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")]=0;

    reverseword(str);
    printf("Reversed Sentence: %s\n",str);

    return 0;
}
