#include <stdio.h>
#include <stdlib.h>

// Defining Student structure
struct Student {
    int rollNo;
    char name[30];
    int numSubjects;
    float *marks;
};

// Function to calculate average marks of a student
float getAverage(struct Student *s) {
    float sum = 0.0;
    int i;
    for (i = 0; i < s->numSubjects; i++) {
        sum += s->marks[i];
    }
    return (s->numSubjects > 0) ? (sum / s->numSubjects) : 0.0;
}

int main() {
    int n, i, j, topperIndex = 0;
    float highestAvg = -1.0;
    struct Student *students;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic allocation for n students
    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Reading details and calculating topper
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter Number of Subjects: ");
        scanf("%d", &students[i].numSubjects);

        students[i].marks = (float *)malloc(students[i].numSubjects * sizeof(float));
        if (students[i].marks == NULL) {
            printf("Memory allocation failed for student %d!\n", i + 1);
            return 1;
        }

        printf("Enter marks for %d subjects:\n", students[i].numSubjects);
        for (j = 0; j < students[i].numSubjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }

        float avg = getAverage(&students[i]);
        if (avg > highestAvg) {
            highestAvg = avg;
            topperIndex = i;
        }
    }

    // Display topper details
    printf("\n================ CLASS TOPPER ================\n");
    printf("Roll No         : %d\n", students[topperIndex].rollNo);
    printf("Name            : %s\n", students[topperIndex].name);
    printf("Number of Marks : %d\n", students[topperIndex].numSubjects);
    printf("Marks List      : ");
    for (j = 0; j < students[topperIndex].numSubjects; j++) {
        printf("%.2f ", students[topperIndex].marks[j]);
    }
    printf("\nHighest Average : %.2f\n", highestAvg);

    // Freeing memory in correct order
    for (i = 0; i < n; i++) {
        free(students[i].marks);
    }
    free(students);

    return 0;
}