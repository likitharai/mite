`1. Employee Database using Structures`  
`Problem Statement:`  
Create a structure `Employee` with the following fields:  
- `ID` (integer)  
- `Name` (string)  
- `Salary` (float)  
- `Department` (string)  

Write a program that:  
1. Reads `N employees` and stores them in an array of structures.  
2. Displays all employee details.  
3. Finds and displays the employee with the `highest salary`.  

`Function Prototypes:`  
```c
void readEmployees(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
Employee findHighestSalary(Employee emp[], int n);
```

`Sample Test Case:`  
`Input:`  
```plaintext
Enter number of employees: 3  
Enter details (ID, Name, Salary, Department):  
1 John 50000 IT  
2 Alice 60000 HR  
3 Bob 55000 Sales  
```
`Output:`  
```plaintext
Employee with Highest Salary: Alice, 60000 (HR)  
```
