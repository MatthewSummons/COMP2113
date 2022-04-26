#include <stdio.h>

double sum(double a, double b){
    return a+b;
}

int main(){
     double a = 12;
     double b = 14.5;
     printf("The sum is %g \n", sum(a,b));
     printf("The sum is %g \n", sum(5.5,4.5));
     return 0;
}
