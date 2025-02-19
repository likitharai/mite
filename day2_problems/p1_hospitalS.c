#include <stdio.h>
#include <string.h>

void read_details(char* patientName, char* wardType, int* p_days) {
    printf("Enter Patient Name: ");
    scanf("%s", patientName);

    printf("Enter Ward Type (G/S/P): ");
    scanf(" %c", wardType);

    printf("Enter Number of Days: ");
    scanf("%d", p_days);
}

float calculateBill(char wardType, int days) {
    float chargePerDay;
    switch (wardType) {
        case 'G':
        case 'g':
            chargePerDay = 1000;
            break;
        case 'S':
        case 's':
            chargePerDay = 2000;
            break;
        case 'P':
        case 'p':
            chargePerDay = 5000;
            break;
        default:
            printf("Invalid Ward Type! Defaulting to General Ward.\n");
            chargePerDay = 1000;
            break;
    }

    return chargePerDay * days;
}

float finalbill(float totalBill, int days) {
    float discount = 0;
    if (days > 7) {
        discount = totalBill * 0.05; 
    }
    return totalBill - discount;
}

int main() {
    char patientName[100];
    char wardType;
    int days;
    float totalBill, discount, final_Bill;

    
    read_details(patientName, &wardType, &days);

    
    totalBill = calculateBill(wardType, days);

    
    final_Bill = finalbill(totalBill, days);

    // Output the results
    printf("\nPatient Name: %s\n", patientName);
    printf("Total Bill Before Discount: ₹%.2f\n", totalBill);
    if (final_Bill < totalBill) {
        discount = totalBill - final_Bill;
        printf("Discount Applied: ₹%.2f\n", discount);
    } else {
        printf("Discount Applied: ₹0.00\n");
    }
    printf("Final Bill Amount: ₹%.2f\n", final_Bill);

    return 0;
}
