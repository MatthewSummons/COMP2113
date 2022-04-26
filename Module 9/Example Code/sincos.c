#include <stdio.h>
#include <math.h>

#define PI 3.14159265

// Task 2. Build the GetSinCos() function
double GetSinCos(const double degrees, double *dSin, double *dCos)) {
    *dSin = sin(degrees * PI / 180);
    *dCos = cos(degrees * PI / 180);
}



int main(){
    double dSin;
    double dCos;
    int degree;

    // Task 1. Read in user input to variable degree
    scanf("%d", &degree);


    // Task 3. Call the GetSinCos() function
    GetSinCos(degree, &dSin, &dCos);

    printf( "The sin is %g \n",dSin );
    printf( "The cos is %g \n",dCos );
    
    return 0;
}
