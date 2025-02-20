#include <stdio.h>

void readEmployee(int salaries[], int N) {
    printf("Enter salaries of %d employees: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &salaries[i]);
    }
}

void sortSalaries(int salaries[], int N) {
    int temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (salaries[i] > salaries[j]) {
                temp = salaries[i];
                salaries[i] = salaries[j];
                salaries[j] = temp;
            }
        }
    }
}

int calculatePayroll(int salaries[], int N) {
    int totalPayroll = 0;
    for (int i = 0; i < N; i++) {
        totalPayroll += salaries[i];
    }
    return totalPayroll;
}

int main() {
    int N;

    printf("Enter the number of employees: ");
    scanf("%d", &N);
    
    int salaries[N];

    readEmployee(salaries, N);
    sortSalaries(salaries, N);

    int secondHighestSalary = salaries[N - 2];
    int totalPayroll = calculatePayroll(salaries, N);

    printf("\nSorted Salaries: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", salaries[i]);
    }

    printf("\nSecond Highest Salary: %d", secondHighestSalary);
    printf("\nTotal Payroll: ₹%d\n", totalPayroll);

    return 0;
}
