#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMPLOYEES 100
struct Employee
{
  int id;
  char name[MAX_NAME_LEN];
  float salary;
};

void readData(const char *filename, struct Employee *employees, int *numEmployees)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    perror("Error opening file");
    exit(1);
  }

  int count = 0;
  while (fscanf(file, "%d %s %f", &employees[count].id, employees[count].name, &employees[count].salary) == 3)
  {
    count++;
  }

  *numEmployees = count;
  fclose(file);
}

void writeData(const char *filename, struct Employee *employees, int numEmployees)
{
  FILE *file = fopen(filename, "w");
  if (file == NULL)
  {
    perror("Error opening file");
    exit(1);
  }

  for (int i = 0; i < numEmployees; i++)
  {
    fprintf(file, "%d %s %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
  }

  fclose(file);
}

void editData(struct Employee *employees, int numEmployees)
{
  int id;
  printf("Enter the employee ID you want to edit: ");
  scanf("%d", &id);

  int index = -1;
  for (int i = 0; i < numEmployees; i++)
  {
    if (employees[i].id == id)
    {
      index = i;
      break;
    }
  }

  if (index == -1)
  {
    printf("No employee with ID %d was found.\n", id);
    return;
  }

  printf("Enter the new name: ");
  scanf("%s", employees[index].name);
  printf("Enter the new salary: ");
  scanf("%f", &employees[index].salary);
}

void addData(struct Employee *employees, int *numEmployees)
{
  int n;
  printf("Enter the number of employees to be added \n");
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    int j = *numEmployees + i;
    printf("Enter the ID: ");
    scanf("%d", &employees[j].id);
    printf("Enter the Name: ");
    scanf("%s", employees[j].name);
    printf("Enter the salary: ");
    scanf("%f", &employees[j].salary);
  }
  *numEmployees += n;
}

void delData(struct Employee *employees, int *numEmployees)
{
  int id;
  printf("Enter the employee ID you want to delete: ");
  scanf("%d", &id);
  int index = -1;
  for (int i = 0; i < *numEmployees; i++)
  {
    if (employees[i].id == id)
    {
      index = i;
      break;
    }
  }

  if (index == -1)
  {
    printf("No employee with ID %d was found.\n", id);
    return;
  }

  for (int i = index; i < *numEmployees; i++)
  {
    employees[i].id = employees[i + 1].id;
    strcpy(employees[i].name, employees[i + 1].name);
    employees[i].salary = employees[i + 1].salary;
  }
  *numEmployees -= 1;
}

int main()
{
  system("CLS");
  const char *filename = "employees.txt";

  struct Employee employees[MAX_EMPLOYEES];
  int numEmployees;

  readData(filename, employees, &numEmployees);

  for (int i = 0; i < numEmployees; i++)
  {
    printf("%d %s %.2f \n", employees[i].id, employees[i].name, employees[i].salary);
  }

  int ch;
  while (1)
  {
    printf("1. Add new employee \n");
    printf("2. Delete employee \n");
    printf("3. Edit employee \n");
    printf("4. Save to file \n");
    printf(" Enter your choice \n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      addData(employees, &numEmployees);
      break;

    case 2:
      delData(employees, &numEmployees);
      break;

    case 3:
      editData(employees, numEmployees);
      break;

    case 4:
      writeData(filename, employees, numEmployees);
      return 0;
    default:
      printf("Invalid choice \n");
      break;
    }
  }
}
