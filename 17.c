#include <stdio.h>
#include <stdlib.h>

// Defining the Employee structure with a dynamic salary pointer member
struct Employee {
    int empId;
    char name[30];
    float *salary; // Pointer member for dynamic salary field
};

int main() {
    struct Employee emp;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Dynamically allocating memory for salary field
    emp.salary = (float *)malloc(sizeof(float));

    if (emp.salary == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Reading employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp.empId);

    printf("Enter Name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Initial Salary: ");
    scanf("%f", emp.salary);

    // Displaying initial details
    printf("\n--- Initial Employee Details ---\n");
    printf("Employee ID : %d\n", emp.empId);
    printf("Name        : %s\n", emp.name);
    printf("Salary      : %.2f\n", *emp.salary);

    // Modifying the salary
    printf("\nEnter Updated Salary: ");
    scanf("%f", emp.salary);

    // Displaying updated details
    printf("\n--- Updated Employee Details ---\n");
    printf("Employee ID : %d\n", emp.empId);
    printf("Name        : %s\n", emp.name);
    printf("Salary      : %.2f\n", *emp.salary);

    // Freeing dynamically allocated memory
    free(emp.salary);

    return 0;
}