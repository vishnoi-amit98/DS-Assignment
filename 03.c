#include <stdio.h>

// Defining the Book structure
struct Book {
    char isbn[20];
    char title[50];
    char author[50];
    float price;
};

int main() {
    struct Book b;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading book details
    printf("Enter ISBN: ");
    scanf("%s", b.isbn);

    printf("Enter Book Title: ");
    scanf(" %[^\n]", b.title);

    printf("Enter Author Name: ");
    scanf(" %[^\n]", b.author);

    printf("Enter Price: ");
    scanf("%f", &b.price);

    // Displaying book details
    printf("\n--- Book Details ---\n");
    printf("ISBN   : %s\n", b.isbn);
    printf("Title  : %s\n", b.title);
    printf("Author : %s\n", b.author);
    printf("Price  : %.2f\n", b.price);

    return 0;
}
