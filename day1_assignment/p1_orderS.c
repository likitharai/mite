#include <stdio.h>
void main() 
{
    int status;
    printf("Enter order status (1-4): ");
    scanf("%d", &status);
    switch (status) {
        case 1:
            printf("Your order has been placed.\n");
            break;
        case 2:
            printf("Your food is being prepared.\n");
            break;
        case 3:
            printf("Your order is out for delivery.\n");
            break;
        case 4:
            printf("Your order has been delivered.\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}