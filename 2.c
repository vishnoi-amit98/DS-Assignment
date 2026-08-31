#include <stdio.h>

// Defining the Employee structure
struct Employee {
    int empId;
    char name[30];
    char department[30];
    float salary;
};

int main() {
    struct Employee emp;
    float annualSalary;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading employee details
    printf("Enter Employee ID: ");
    scanf("%d", &emp.empId);

    printf("Enter Name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Department: ");
    scanf(" %[^\n]", emp.department);

    printf("Enter Monthly Salary: ");
    scanf("%f", &emp.salary);

    // Calculating annual salary
    annualSalary = emp.salary * 12;

    // Displaying stored details and calculated annual salary
    printf("\n--- Employee Details ---\n");
    printf("Employee ID   : %d\n", emp.empId);
    printf("Name          : %s\n", emp.name);
    printf("Department    : %s\n", emp.department);
    printf("Monthly Salary: %.2f\n", emp.salary);
    printf("Annual Salary : %.2f\n", annualSalary);

    return 0;
}