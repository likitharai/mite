#include <stdio.h>
#include <string.h>
#define FIXED_CHARGE 100.0f


float calculate_base_bill(float units) {
    if (units <= 100)
     return units * 5;
    if (units <= 300) return (100 * 5) + ((units - 100) * 7);
    return (100 * 5) + (200 * 7) + ((units - 300) * 10);
}

float calculate_total_bill(float base_bill) {
    float total_bill = base_bill + FIXED_CHARGE;
    if (total_bill > 1000) total_bill += total_bill * 0.05;  
    return total_bill;
}


void read_customer_details(char *name, int *id, float *units_consumed) {
    printf("Enter Customer Name: ");
    scanf("%s", name);  
    
    printf("Enter Customer ID: ");
    scanf("%d", id);

    printf("Enter Total Units Consumed: ");
    scanf("%f", units_consumed);
}

int main() {
    char customer_name[100];
    int customer_id;
    float units_consumed;

   
    read_customer_details(customer_name, &customer_id, &units_consumed);
    float base_bill = calculate_base_bill(units_consumed);
    float total_bill = calculate_total_bill(base_bill);

    
    printf("\nCustomer Name: %s\nCustomer ID: %d\nUnits Consumed: %.2f\nBase Bill: ₹%.2f\nTotal Bill: ₹%.2f\n",
           customer_name, customer_id, units_consumed, base_bill, total_bill);

    return 0;
}
