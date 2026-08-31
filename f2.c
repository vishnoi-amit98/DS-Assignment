#include <stdio.h>
#include <stdlib.h>

// Defining the Employee structure
struct Employee {
    int empId;
    char name[30];
    int numProjects;
    float *scores;
};

// Function to input employee details and allocate dynamic memory
void inputEmployee(struct Employee *e) {
    int i;
    printf("Enter Employee ID: ");
    scanf("%d", &e->empId);

    printf("Enter Name: ");
    scanf(" %[^\n]", e->name);

    printf("Enter Number of Projects: ");
    scanf("%d", &e->numProjects);

    e->scores = (float *)malloc(e->numProjects * sizeof(float));
    if (e->scores == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter scores for %d projects:\n", e->numProjects);
    for (i = 0; i < e->numProjects; i++) {
        printf("Project %d Score: ", i + 1);
        scanf("%f", &e->scores[i]);
    }
}

// Function to calculate average project score
float calculateAverageScore(struct Employee *e) {
    float sum = 0.0;
    int i;
    for (i = 0; i < e->numProjects; i++) {
        sum += e->scores[i];
    }
    return (e->numProjects > 0) ? (sum / e->numProjects) : 0.0;
}

// Function to display employee details
void displayEmployee(struct Employee *e) {
    int i;
    printf("\n--- Employee Performance Details ---\n");
    printf("Employee ID    : %d\n", e->empId);
    printf("Name           : %s\n", e->name);
    printf("Projects Count : %d\n", e->numProjects);
    printf("Project Scores : ");
    for (i = 0; i < e->numProjects; i++) {
        printf("%.2f ", e->scores[i]);
    }
    printf("\nAverage Score  : %.2f\n", calculateAverageScore(e));
}

int main() {
    struct Employee emp;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    inputEmployee(&emp);
    displayEmployee(&emp);

    // Free dynamic memory
    free(emp.scores);

    return 0;
}