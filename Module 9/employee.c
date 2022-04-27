#include <stdio.h>      // For printf() & scanf()
#include <string.h>       // For C-string methods
#include <stdlib.h>     // For malloc(), free() & NULL

struct Employee {
  char Name[100];
  char Position[100];
  int Salary;

};

typedef struct Employee Employee;

void constructEmployee(char[], char[], int, Employee*);
void printEmployee(Employee*);

int main() {
  // Determine the number of workers
  int numOfEmployees;
  scanf("%d", &numOfEmployees);

  // Dynamic Array storing the employees
  Employee * Staff;
  Staff = (Employee *) malloc(numOfEmployees * sizeof(Employee));

  // Read employee information
  char n[100], p[100];
  int sal;
  for (int i = 0; i < numOfEmployees; i++) {
    scanf("%s%s%d", n, p, &sal);
    constructEmployee(n, p, sal, &Staff[i]);
  }
  
  // Show employee information
  for (int i = 0; i < numOfEmployees; i++) {
    printEmployee(&Staff[i]);
  }


  // Free space
  free(Staff);


  return 0;
}

void constructEmployee(char name[], char position[], int salary, Employee *employee) {
  strcpy(employee->Name, name);
  strcpy(employee->Position, position);
  employee->Salary = salary;
}

void printEmployee(Employee *employee) {
  printf("Name: %s\n", employee->Name);
  printf("Position: %s\n", employee->Position);
  printf("Salary: %d\n", employee->Salary);
}
