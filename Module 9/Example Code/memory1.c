#include <stdio.h>
#include <stdlib.h>
int main(){
     int size;
     int *a;
     
     printf("How many slots in the array?");    
     scanf("%d", &size);
     printf("%d\n",size);    
     
     a = (int*) malloc ( size * sizeof(int) );
     for( int i = 0; i < size ; i++ )
          a[i] = i;
     for( int i = 0; i < size ; i++ )
          printf( "%d ",a[i]);

     return 0;
}
