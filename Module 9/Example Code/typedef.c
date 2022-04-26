#include<stdio.h>
#include<string.h>
struct student{
     char name[20];
     int uid;
};
typedef struct student Student;
int main(){
     Student a;
     strcpy(a.name,"Kit");
     a.uid = 2012111111;
     printf("%s has uid %d.\n",a.name,a.uid);
     return 0;
}
