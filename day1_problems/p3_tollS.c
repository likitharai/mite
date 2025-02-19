#include<stdio.h>
#include<string.h>
int main(){
    int vehicle_count;
    char vehicle_type[40];
   
    
    printf("enter the number of vehicle\n");
    scanf("%d",& vehicle_count);
    
    float collection=0;
   
    for(int i=1;i<= vehicle_count;i++){
         printf("enter the vehicle type\n");
        scanf("%s",vehicle_type);
        if(strcmp(vehicle_type,"car")==0){
            collection+=50;
        }
        else if(strcmp(vehicle_type,"truck")==0){
           collection+=100;
        }
        else if(strcmp(vehicle_type,"bike")==0){
             collection+=20;
        }
    }
    printf("total toll collection; %0.2f\n",collection);
    
    return 0;
}