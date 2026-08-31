#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

// Function that receives a pointer to the Student structure and updates marks
void updateMarks(struct Student *s, float newMarks) {
    s->marks = newMarks;
}

int main() {
    struct Student s;
    float newMarks;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading initial student details
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Initial Marks: ");
    scanf("%f", &s.marks);

    // Displaying details before function call
    printf("\n--- Before Function Call ---\n");
    printf("Roll No : %d\n", s.rollNo);
    printf("Name    : %s\n", s.name);
    printf("Marks   : %.2f\n", s.marks);

    // Reading new marks to update
    printf("\nEnter New Marks to Update: ");
    scanf("%f", &newMarks);

    // Calling the function by passing the address
    updateMarks(&s, newMarks);

    // Displaying details after function call
    printf("\n--- After Function Call ---\n");
    printf("Roll No : %d\n", s.rollNo);
    printf("Name    : %s\n", s.name);
    printf("Marks   : %.2f\n", s.marks);

    return 0;
}
