#include <stdio.h>
#include <stdlib.h>

// Defining Student structure with a pointer member
struct Student {
    int rollNo;
    char name[30];
    int numSubjects;
    float *marks; // Pointer member for dynamic marks array
};

int main() {
    struct Student s;
    int i;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading basic details
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Number of Subjects: ");
    scanf("%d", &s.numSubjects);

    // Dynamically allocating memory for marks
    s.marks = (float *)malloc(s.numSubjects * sizeof(float));

    if (s.marks == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Reading marks for each subject
    printf("Enter marks for %d subjects:\n", s.numSubjects);
    for (i = 0; i < s.numSubjects; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s.marks[i]);
    }

    // Displaying details
    printf("\n--- Student Details ---\n");
    printf("Roll No            : %d\n", s.rollNo);
    printf("Name               : %s\n", s.name);
    printf("Number of Subjects : %d\n", s.numSubjects);
    printf("Marks Obtained     : ");
    for (i = 0; i < s.numSubjects; i++) {
        printf("%.2f ", s.marks[i]);
    }
    printf("\n");

    // Deallocating dynamic memory
    free(s.marks);

    return 0;
}