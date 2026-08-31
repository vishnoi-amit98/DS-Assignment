#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    struct Student s[10];
    int i;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n");

    // Reading details of 10 students
    printf("Enter details of 10 students:\n");
    for (i = 0; i < 10; i++) {
        printf("Student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Displaying all 10 student records
    printf("\n================ ALL STUDENT RECORDS ================\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("----------------------------------------------------\n");
    for (i = 0; i < 10; i++) {
        printf("%-10d %-25s %-10.2f\n", s[i].rollNo, s[i].name, s[i].marks);
    }

    return 0;
}