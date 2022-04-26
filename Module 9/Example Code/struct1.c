#include<stdio.h>
#include<string.h>
struct student{
     char name[20];
     int uid;
};

int main(){
     struct student a;
     strcpy(a.name,"Kit");
     a.uid = 2012111111;
     printf("%s has uid %d.\n",a.name,a.uid);
     return 0;
}
