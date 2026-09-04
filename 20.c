#include <stdio.h>
#include <stdlib.h>

struct Student {
    int rollNo;
    int numSubjects;
    float *marks; // Dynamic array of marks
};

int main() {
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    struct Student s;
    s.rollNo = 101;
    s.numSubjects = 3;

    // Allocate memory for 3 subjects
    s.marks = (float *)malloc(s.numSubjects * sizeof(float));

    if (s.marks == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    s.marks[0] = 85.5f;
    s.marks[1] = 90.0f;
    s.marks[2] = 94.5f;

    printf("Roll No: %d\n", s.rollNo);
    for (int i = 0; i < s.numSubjects; i++) {
        printf("Subject %d Marks: %.2f\n", i + 1, s.marks[i]);
    }

    // Free the dynamically allocated array
    free(s.marks);
    s.marks = NULL;

    printf("\nMemory successfully freed.\n");

    return 0;
}
