#include <stdio.h>

// Defining the Rectangle structure
struct Rectangle {
    float length;
    float breadth;
};

int main() {
    struct Rectangle rect;
    float area, perimeter;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading rectangle dimensions
    printf("Enter Length: ");
    scanf("%f", &rect.length);

    printf("Enter Breadth: ");
    scanf("%f", &rect.breadth);

    // Calculating area and perimeter
    area = rect.length * rect.breadth;
    perimeter = 2 * (rect.length + rect.breadth);

    // Displaying results
    printf("\n--- Rectangle Details ---\n");
    printf("Length    : %.2f\n", rect.length);
    printf("Breadth   : %.2f\n", rect.breadth);
    printf("Area      : %.2f\n", area);
    printf("Perimeter : %.2f\n", perimeter);

    return 0;
}