#include <stdio.h>
#include<string.h>
int main()
{
    char name[100];
    int id;
    float salary;
    int attendence;

    printf("enter id\n");
    scanf("%d",&id);

    printf("enter  name\n");
    scanf("%s",name);

    printf("enter salary\n");
    scanf("%f",&salary);

    printf("enter the attendence\n");
    scanf("%d",&attendence);
    // procees of payroll
    float bonus=0.0f;
    float gross_salary=0.0f;
    char catogary[50]="Good";
//bonus calculation
    if (attendence>25){
        bonus=(bonus/100.0f)*5.0f;
    }
    else if (attendence<10){
        bonus=(-1.0f*(bonus/100.0f)*50.0f);
    }
    //final salary
    gross_salary=(bonus+salary);
    
    if(attendence>25){
        strcpy(catogary,"Excellent");
    }
    else if(attendence<15){
        strcpy(catogary,"Need improvement");
    }
    printf("\t payroll category\n");
    printf("\tID=%d\n",id);
    printf("\tname=%s\n",name);
    printf("\tsalary=%f\n",salary);
    if (bonus>0){
        printf("%0.2f\n",bonus);
    }
    printf("\tfinal salary:%0.2f\n",gross_salary);
    printf("\temploy performance catagory:%s\n",catogary);
    return 0;
}
