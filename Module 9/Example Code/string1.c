#include<stdio.h>
#include<string.h>
int main(){
     char a[]="Kit";
     char b[]="Kit";
     if (strcmp(a,b)==0){
         printf("a b are the same\n");
     }
     strcpy (b,"David");
     printf("The value of b is: %s.\n", b);

     strcat (a,b);
     printf("a: %s, b: %s\n",a, b);
     return 0;
}
