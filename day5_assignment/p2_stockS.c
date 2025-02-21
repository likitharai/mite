#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100


typedef struct Stack {
    char* items[max]; 
    int top;                  
} Stack;


void initStack(Stack* stack) {
    stack->top = -1;
}


void push(Stack* stack, const char* item) {
    if (stack->top < max - 1) {
        stack->items[++(stack->top)] = strdup(item);  
        printf("Stock Added: %s\n", item);
    } else {
        printf("Warehouse is full!\n");
    }
}

char* pop(Stack* stack) {
    if (stack->top >= 0) {
        return stack->items[(stack->top)--];
    } else {
        return NULL;
    }
}


void displayStock(Stack* stack) {
    if (stack->top == -1) {
        printf("No remaining stock.\n");
    } else {
        printf("Remaining Stock: ");
        for (int i = stack->top; i >= 0; i--) {
            printf("%s", stack->items[i]);
            if (i != 0) {
                printf(", ");
            }
        }
        printf("\n");
    }
}


int main() {
    Stack warehouse;
    initStack(&warehouse);

    
    push(&warehouse, "Item A");
    push(&warehouse, "Item B");
    push(&warehouse, "Item C");


    char* dispatchedItem = pop(&warehouse);
    if (dispatchedItem != NULL) {
        printf("Dispatching Item: %s\n", dispatchedItem);
        free(dispatchedItem); 
    }

   
    displayStock(&warehouse);

    return 0;
}
