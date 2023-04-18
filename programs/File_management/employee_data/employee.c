#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMPLOYEES 100

struct Employee {
  int id;
  char name[MAX_NAME_LEN];
  float salary;
};

void readData(const char *filename, struct Employee *employees, int *numEmployees) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  int count = 0;
  while (fscanf(file, "%d %s %f", &employees[count].id, employees[count].name, &employees[count].salary) == 3) {
    count++;
  }

  *numEmployees = count;
  fclose(file);
}

void writeData(const char *filename, struct Employee *employees, int numEmployees) {
  FILE *file = fopen(filename, "w");
  if (file == NULL) {
    perror("Error opening file");
    exit(1);
  }

  for (int i = 0; i < numEmployees; i++) {
    fprintf(file, "%d %s %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
  }

  fclose(file);
}

void editData(struct Employee *employees, int numEmployees) {
  int id;
  printf("Enter the employee ID you want to edit: ");
  scanf("%d", &id);

  int index = -1;
  for (int i = 0; i < numEmployees; i++) {
    if (employees[i].id == id) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    printf("No employee with ID %d was found.\n", id);
    return;
  }

  printf("Enter the new name: ");
  scanf("%s", employees[index].name);
  printf("Enter the new salary: ");
  scanf("%f", &employees[index].salary);
}

int main() {
  const char *filename = "employees.txt";
  struct Employee employees[MAX_EMPLOYEES];
  int numEmployees;

  readData(filename, employees, &numEmployees);
  editData(employees, numEmployees);
  writeData(filename, employees, numEmployees);

  return 0;
}
