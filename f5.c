#include <stdio.h>
#include <stdlib.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

// Function prototypes
void addStudent(struct Student **students, int *count, int *capacity);
void displayStudents(const struct Student *students, int count);
void searchStudent(const struct Student *students, int count);
void updateStudent(struct Student *students, int count);

int main() {
    struct Student *students = NULL;
    int count = 0;
    int capacity = 0;
    int choice;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    do {
        printf("\n====== STUDENT MANAGEMENT SYSTEM ======\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Update Student Details\n");
        printf("5. Exit\n");
        printf("---------------------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&students, &count, &capacity);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateStudent(students, count);
                break;
            case 5:
                printf("\nReleasing allocated memory and exiting...\n");
                free(students);
                students = NULL;
                printf("Memory cleanup successful. Program terminated.\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to add a student record dynamically
void addStudent(struct Student **students, int *count, int *capacity) {
    if (*count == *capacity) {
        int newCapacity = (*capacity == 0) ? 2 : (*capacity * 2);
        struct Student *temp = (struct Student *)realloc(*students, newCapacity * sizeof(struct Student));
        if (temp == NULL) {
            printf("Memory allocation failed!\n");
            return;
        }
        *students = temp;
        *capacity = newCapacity;
    }

    struct Student *newEntry = *students + *count;

    printf("\nEnter Roll Number: ");
    scanf("%d", &newEntry->rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", newEntry->name);

    printf("Enter Marks: ");
    scanf("%f", &newEntry->marks);

    (*count)++;
    printf("Record added successfully!\n");
}

// Function to display all student records
void displayStudents(const struct Student *students, int count) {
    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n================ ALL STUDENT RECORDS ================\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-10.2f\n", (students + i)->rollNo, (students + i)->name, (students + i)->marks);
    }
}

// Function to search a record by roll number
void searchStudent(const struct Student *students, int count) {
    if (count == 0) {
        printf("\nNo student records to search.\n");
        return;
    }

    int targetRoll, found = 0;
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if ((students + i)->rollNo == targetRoll) {
            printf("\n--- Match Found ---\n");
            printf("Roll No : %d\n", (students + i)->rollNo);
            printf("Name    : %s\n", (students + i)->name);
            printf("Marks   : %.2f\n", (students + i)->marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRoll);
    }
}

// Function to update an existing student record
void updateStudent(struct Student *students, int count) {
    if (count == 0) {
        printf("\nNo student records available to update.\n");
        return;
    }

    int targetRoll, found = 0;
    printf("\nEnter Roll Number of student to update: ");
    scanf("%d", &targetRoll);

    for (int i = 0; i < count; i++) {
        if ((students + i)->rollNo == targetRoll) {
            printf("\nCurrent Record: Roll No: %d, Name: %s, Marks: %.2f\n",
                   (students + i)->rollNo, (students + i)->name, (students + i)->marks);

            printf("Enter Updated Name: ");
            scanf(" %[^\n]", (students + i)->name);

            printf("Enter Updated Marks: ");
            scanf("%f", &(students + i)->marks);

            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with Roll Number %d not found.\n", targetRoll);
    }
}
