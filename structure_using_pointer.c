#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[50];
  int age;
  float salary;
} Employee;

int main() {
  Employee emp1, emp2;
  Employee *ptr;  // declare a pointer to an Employee structure

  // store values in emp1
  strcpy(emp1.name, "Vishesh jat");
  emp1.age = 30;
  emp1.salary = 50000.0;

  // store values in emp2
  strcpy(emp2.name, "Smith Patel");
  emp2.age = 35;
  emp2.salary = 60000.0;

  // assign the address of emp1 to ptr
  ptr = &emp1;

  // access the fields of emp1 using ptr
  printf("Name: %s\n", ptr->name);
  printf("Age: %d\n", ptr->age);
  printf("Salary: %.2f\n", ptr->salary);

  // assign the address of emp2 to ptr
  ptr = &emp2;

  // access the fields of emp2 using ptr
  printf("\nName: %s\n", ptr->name);
  printf("Age: %d\n", ptr->age);
  printf("Salary: %.2f\n", ptr->salary);

  return 0;
}
