#include <stdio.h>
int main(){
    char p1[] = "Alan", p2[] = "Ben";
    int a1 = 9, a2 = 30;
    float w1 = 30, w2 = 40.25;
    
    printf( "123456789012345678901234567890\n");
    printf( "%8s %8s %8s\n", "Name", "Age", "Weight");
    printf( "%?? %?? %??\n", p1, a1, w1);
    printf( "%?? %?? %??\n", p2, a2, w2);

    return 0;    
}
