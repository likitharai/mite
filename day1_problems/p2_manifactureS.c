#include<stdio.h>
int main(){
    int productcount;
    int weight;
   
    
    printf("enter the number of product\n");
    scanf("%d",&productcount);
    
    int acceptable_c=0;
    int rejected_c=0;
    for(int i=1;i<=productcount;i++){
         printf("enter the weight\n");
        scanf("%d",&weight);
        if((weight>=950)&&(weight<=1050)){
            acceptable_c++;
        }
        else{
           rejected_c++;
        }
    }
    printf("acceptet count; %d\n",acceptable_c);
    printf("rejected count:%d\n",rejected_c);
    return 0;
}