#include <stdio.h>

// Defining the Employee structure
struct Employee {
    int empId;
    char name[30];
    char department[30];
    float salary;
};

int main() {
    int n, i, count = 0;
    float minSalary;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Employee emp[n];

    // Reading employee records
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Employee %d:\n", i + 1);
        printf("Enter Employee ID: ");
        scanf("%d", &emp[i].empId);

        printf("Enter Name: ");
        scanf(" %[^\n]", emp[i].name);

        printf("Enter Department: ");
        scanf(" %[^\n]", emp[i].department);

        printf("Enter Monthly Salary: ");
        scanf("%f", &emp[i].salary);
    }

    // Input salary threshold
    printf("\nEnter Salary threshold: ");
    scanf("%f", &minSalary);

    // Displaying employees earning more than the threshold
    printf("\n--- Employees with Salary > %.2f ---\n", minSalary);
    for (i = 0; i < n; i++) {
        if (emp[i].salary > minSalary) {
            printf("\nID        : %d\n", emp[i].empId);
            printf("Name      : %s\n", emp[i].name);
            printf("Department: %s\n", emp[i].department);
            printf("Salary    : %.2f\n", emp[i].salary);
            count++;
        }
    }

    if (count == 0) {
        printf("No employee found with salary greater than %.2f.\n", minSalary);
    }

    return 0;
}
