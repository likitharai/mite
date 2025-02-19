#include <stdio.h>
void readdetails(float* p_salary,int* p_score,int* p_experience){
    printf("enter the salary");
    scanf("%f",p_salary);
   
    printf("enter the credit score\n");
    scanf("%d",p_score);
   
    printf("enter the experience\n");
    scanf("%d",p_experience);
}
int is_eligible(float salary,int score,int exprience){
    return((salary>=30000)&&(score>=750)&&(exprience>=2));
}
int main()
{
    float salary;
    int score;
    int experience;
    readdetails(&salary,&score,&experience);
    if(is_eligible(salary,score,experience)){
        printf("loan approved");
    }
    else{
        printf("loan not approved");
    }
    return 0;
}