#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    int n, i, j;
    struct Student temp;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Reading student records
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Sorting in descending order using Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].marks < s[j + 1].marks) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    // Displaying sorted records
    printf("\n================ SORTED RECORDS (DESCENDING) ================\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("-------------------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-10d %-25s %-10.2f\n", s[i].rollNo, s[i].name, s[i].marks);
    }

    return 0;
}