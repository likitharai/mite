#include <stdio.h>
#include<string.h>
void read_employ(int* p_id,char* name,float* p_salary,int* p_attendence){
 printf("enter id\n");
    scanf("%d",p_id);

    printf("enter  name\n");
    scanf("%s",name);

    printf("enter salary\n");
    scanf("%f",p_salary);

    printf("enter the attendence\n");
    scanf("%d",p_attendence);
}
float calculate_bonus(float salary,int attendence){
    float bonus=0.0f;
    if (attendence>25){
        bonus=(salary/100.0f)*5.0f;
    }
    else if (attendence<10){
        bonus=(-1.0f*(salary/100.0f)*50.0f);
    }
    return bonus;
}
void catogarize_employ(char* catogary,int attendence){
     if(attendence>25){
        strcpy(catogary,"Excellent");
    }
    else if(attendence<15){
        strcpy(catogary,"Need improvement");
    }
}
void print_payroll(int id,char* name,float salary,float bonus,float gross_salary,char* catogary){
    printf("\t payroll category\n");
    printf("\tID=%d\n",id);
    printf("\tname=%s\n",name);
    printf("\tsalary=%f\n",salary);
    if (bonus>0){
        printf("\tbonus:%0.2f\n",bonus);
    }
    printf("\tfinal salary:%0.2f\n",gross_salary);
    printf("\temploy performance catagory:%s\n",catogary);
    
}
int main()
{
    char name[100];
    int id;
    float salary;
    int attendence;
    read_employ(&id,name,&salary,&attendence);
   
    // procees of payroll
    float bonus=0.0f;
    float gross_salary=0.0f;
    char catogary[50]="Good";
//bonus calculation
    bonus=calculate_bonus(salary,attendence);
    //final salary
    gross_salary=(bonus+salary);
    catogarize_employ(catogary,attendence);
    print_payroll(id,name,salary,bonus,gross_salary,catogary);
    return 0;
}