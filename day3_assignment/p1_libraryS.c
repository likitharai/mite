#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readbook(char** str, int N) {
    getchar();
    for (int i = 0; i < N; i++) {
        printf("Enter book %d: ", i + 1);
        fgets(str[i], 100, stdin);
        str[i][strcspn(str[i], "\n")] = '\0';
    }
}

void sortBook(char** str, int N) {
    char* temp;  
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

void searchBook(char** str, int N, char* searchTitle) {
    if (N == 0) {
        printf("No books in the library.\n");
        return;
    }

    for (int i = 0; i < N; i++) {
        if (strcmp(str[i], searchTitle) == 0) { 
            printf("Book found in the library.\n");
            return;
        }
    }
    printf("Book not found in the library.\n");
}

int main() {
    int N;
    printf("Enter the number of books: ");
    scanf("%d", &N);

    char** str = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        str[i] = (char*)malloc(100 * sizeof(char));
    }

    readbook(str, N);
    sortBook(str, N);

    printf("\nThe books in sorted order are:\n");
    for (int i = 0; i < N; i++) {
        printf("Book %d: %s\n", i + 1, str[i]);
    }

    char searchTitle[100];
    printf("\nEnter book title to search: ");
    getchar();
    fgets(searchTitle, 100, stdin);
    searchTitle[strcspn(searchTitle, "\n")] = '\0';

    searchBook(str, N, searchTitle);

    for (int i = 0; i < N; i++) {
        free(str[i]);
    }

    free(str);
    return 0;
}
