
#include <stdio.h>
struct Employee_t{
    int id;
    char name[230];
    float salary;
    char department[23];
};
typedef struct Employee_t Employee;
void readEmployee(Employee emp[],int n);
void displayEmployee(Employee emp[],int n);
Employee findHighestSalary(Employee emp[],int n);
int main() {
    int Employeecount;
    printf("enter number of Employee\n");
    scanf("%d",&Employeecount);
    Employee Employees[1000];
    readEmployee(Employees,Employeecount);
    displayEmployee(Employees,Employeecount);
    Employee HighestSalariedEmployee=findHighestSalary(Employees,Employeecount);
    printf("Employee with highiest salary:%s,%0.2f(%s)\n",
        HighestSalariedEmployee.name,
        HighestSalariedEmployee.salary,
        HighestSalariedEmployee.department);
    return 0;
}
void readEmployee(Employee emp[],int n){
    printf("enter the employee details\n",n);
    for(int i=0;i<n;i++){
        printf("enter the %d employee details\n",i+1);
        scanf("%d%s%f%s",&emp[i].id,emp[i].name,&emp[i].salary,emp[i].department);
    }
    
}
void displayEmployee(Employee emp[],int n){
    printf("the employee details are\n",n);
    printf("id\tname\tsalary\tdepartment\n");
    for(int i=0;i<n;i++){
        printf("%d\t%s\t%0.2f\t%s\n",emp[i].id,emp[i].name,emp[i].salary,emp[i].department);
    }
}
Employee findHighestSalary(Employee emp[],int n){
    Employee highestSalaried=emp[0];
    for(int i=1;i<n;i++){
            if(emp[i].salary>highestSalaried.salary){
               highestSalaried=emp[i];
                
            }
        }
        return highestSalaried;
}
