#include<stdio.h>

void salary_increase(int sal[]){
    for (int i=0; i<4 ; i++){
        sal[i]*=1.1;
    }
}

void print(int sal[]){
    for (int i=0; i<4 ; i++){
        printf("%d ",sal[i]);
    }    
    printf("\n");
}

int main(){
    int salary[]={15000,22000,36000,24000};
    print(salary);
    salary_increase(salary);
    print(salary);
    return 0;
}
