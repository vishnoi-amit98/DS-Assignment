#include <stdio.h>
#include <stdlib.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    int numSubjects;
    float *marks;
};

int main() {
    struct Student s;
    int extra, i, totalSubjects;
    float *temp;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading initial details
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Initial Number of Subjects: ");
    scanf("%d", &s.numSubjects);

    // Initial allocation using malloc
    s.marks = (float *)malloc(s.numSubjects * sizeof(float));
    if (s.marks == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input initial marks
    printf("Enter marks for initial %d subjects:\n", s.numSubjects);
    for (i = 0; i < s.numSubjects; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
    }

    // Input extra subjects to add
    printf("\nEnter number of additional subjects to add: ");
    scanf("%d", &extra);

    totalSubjects = s.numSubjects + extra;

    // Resizing dynamic memory using realloc
    temp = (float *)realloc(s.marks, totalSubjects * sizeof(float));
    if (temp == NULL) {
        printf("Memory reallocation failed!\n");
        free(s.marks);
        return 1;
    }
    s.marks = temp;

    // Input marks for newly added subjects
    printf("Enter marks for %d additional subjects:\n", extra);
    for (i = s.numSubjects; i < totalSubjects; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
    }
    s.numSubjects = totalSubjects;

    // Displaying complete updated record
    printf("\n--- Updated Student Profile ---\n");
    printf("Roll No         : %d\n", s.rollNo);
    printf("Name            : %s\n", s.name);
    printf("Total Subjects  : %d\n", s.numSubjects);
    printf("All Marks       : ");
    for (i = 0; i < s.numSubjects; i++) {
        printf("%.2f ", s.marks[i]);
    }
    printf("\n");

    // Freeing memory
    free(s.marks);

    return 0;
}