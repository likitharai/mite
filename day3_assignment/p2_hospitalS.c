#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient {
    char name[100];
    int level;
};
typedef struct patient patients;

void readData(patients patientList[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d. ", i + 1);
        printf("Enter name (single word): ");
        scanf("%s", patientList[i].name); 
        printf("Enter emergency level (1-5): ");
        scanf("%d", &patientList[i].level);
    }
}

void sortPatients(patients patientList[], int N) {
    patients temp;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (patientList[i].level < patientList[j].level) {
                temp = patientList[i];
                patientList[i] = patientList[j];
                patientList[j] = temp;
            }
        }
    }
}

void displayTop3(patients patientList[], int N) {
    printf("\nTop 3 Critical Patients:\n");
    for (int i = 0; i < (N < 3 ? N : 3); i++) {
        printf("%d. %s\n", i + 1, patientList[i].name);
    }
}

int main() {
    int N;
    printf("Enter number of patients: ");
    scanf("%d", &N);
    
    patients patientList[N];
    printf("Patient Data:\n");
    
    
    readData(patientList, N);

    sortPatients(patientList, N);

    printf("\nSorted by Emergency Level:\n");
    for (int i = 0; i < N; i++) {
        printf("%d. %s - Level %d\n", i + 1, patientList[i].name, patientList[i].level);
    }

    displayTop3(patientList, N);

    return 0;
}
