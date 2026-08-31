#include <stdio.h>
#include <stdlib.h>

// Defining Student structure
struct Student {
    int rollNo;
    char name[30];
    int numSubjects;
    float *marks;
};

// Function to input student details
void inputStudent(struct Student *s) {
    int i;
    printf("Enter Roll Number: ");
    scanf("%d", &s->rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter Number of Subjects: ");
    scanf("%d", &s->numSubjects);

    s->marks = (float *)malloc(s->numSubjects * sizeof(float));
    if (s->marks == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter marks for %d subjects:\n", s->numSubjects);
    for (i = 0; i < s->numSubjects; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%f", &s->marks[i]);
    }
}

// Function to display details
void displayStudent(struct Student *s) {
    int i;
    printf("\n--- Student Details ---\n");
    printf("Roll No : %d\n", s->rollNo);
    printf("Name    : %s\n", s->name);
    printf("Marks   : ");
    for (i = 0; i < s->numSubjects; i++) {
        printf("%.2f ", s->marks[i]);
    }
    printf("\n");
}

// Function to calculate total marks
float calculateTotal(struct Student *s) {
    float total = 0.0;
    int i;
    for (i = 0; i < s->numSubjects; i++) {
        total += s->marks[i];
    }
    return total;
}

// Function to calculate average marks
float calculateAverage(struct Student *s) {
    return calculateTotal(s) / s->numSubjects;
}

// Function to find highest mark
float findHighest(struct Student *s) {
    float max = s->marks[0];
    int i;
    for (i = 1; i < s->numSubjects; i++) {
        if (s->marks[i] > max) {
            max = s->marks[i];
        }
    }
    return max;
}

int main() {
    struct Student s;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Perform operations
    inputStudent(&s);
    displayStudent(&s);

    printf("Total Marks   : %.2f\n", calculateTotal(&s));
    printf("Average Marks : %.2f\n", calculateAverage(&s));
    printf("Highest Mark  : %.2f\n", findHighest(&s));

    // Release memory
    free(s.marks);

    return 0;
}