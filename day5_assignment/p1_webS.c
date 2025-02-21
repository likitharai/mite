#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct Stack {
    char* pages[max]; 
    int top;                   
} Stack;


void initStack(Stack* stack) {
    stack->top = -1;
}

void push(Stack* stack, const char* url) {
    if (stack->top < max - 1) {
        stack->pages[++(stack->top)] = strdup(url);  
    } else {
        printf("History stack is full!\n");
    }
}


char* pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->pages[(stack->top)--];
    } else {
        printf("Stack is empty!\n");
        return NULL;
    }
}


char* currentPage(Stack* stack) {
    if (stack->top >= 0) {
        return stack->pages[stack->top];
    } else {
        return NULL;
    }
}

int main() {
    Stack historyStack;
    Stack forwardStack;
    char* currentURL;

    
    initStack(&historyStack);
    initStack(&forwardStack);

    
    push(&historyStack, "google.com");
    push(&historyStack, "github.com");
    push(&historyStack, "stackoverflow.com");

   
    currentURL = currentPage(&historyStack);
    printf("Current Page: %s\n", currentURL);

    
    printf("Action: Go Back\n");
    char* previousPage = pop(&historyStack);  
    push(&forwardStack, previousPage);  
    currentURL = currentPage(&historyStack);  
    printf("Current Page: %s\n", currentURL);

    
    printf("Action: Go Forward\n");
    if ((currentURL = pop(&forwardStack)) != NULL) {
        push(&historyStack, currentURL);  
        printf("Current Page: %s\n", currentURL);
    } else {
        printf("No more pages to go forward to.\n");
    }

    return 0;
}