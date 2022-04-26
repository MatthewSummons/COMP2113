#include <iostream>
using namespace std;

void swap1(double a, double b){
    double temp = a;
    a=b;
    b=temp;
}

void swap2(double & a, double & b){
    double temp = a;
    a=b;
    b=temp;
}

void swap3(double *a, double *b){
    double temp = *a;
    *a=*b;
    *b=temp;
}

void print(double a, double b){
    cout << "a = " << a << ", b = " << b << endl;
}

int main(){
    double a = 5.5;
    double b = 10.5;
    print(a,b);
    swap1(a,b);
    print(a,b);
    swap2(a,b);
    print(a,b);
    swap3(&a,&b);
    print(a,b);    
    return 0;
}
