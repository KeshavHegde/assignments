#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createUser();
void readUsers();
void updateUser();
void deleteUser();
void ensureFileExists();

#define FILE_PATH "user.txt"

typedef struct {
    int id;
    char name[50];
    int age;
} User;

int main() {
    int choice;
    ensureFileExists();
    do {
        printf("\n--- User Management System ---\n");
        printf("1. Add a new user\n");
        printf("2. Display all users\n");
        printf("3. Update a user by ID\n");
        printf("4. Delete a user by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createUser();
                break;
            case 2:
                readUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

void ensureFileExists() {
    FILE *file = fopen(FILE_PATH, "r");
    if (!file) {
        file = fopen(FILE_PATH, "w");
        if (file) {
            fclose(file);
        } else {
            perror("Error creating file");
            exit(EXIT_FAILURE);
        }
    } else {
        fclose(file);
    }
}

int getValidInteger(const char *prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1) {
            while (getchar() != '\n');
            return value;
        }
        printf("Invalid input. Please enter a valid integer.\n");
        while (getchar() != '\n');
    }
}

void createUser() {
    FILE *file = fopen(FILE_PATH, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    User user;
    user.id = getValidInteger("Enter User ID: ");
    User existingUser;
    while (fscanf(file, "%d,%49[^,],%d\n", &existingUser.id, existingUser.name, &existingUser.age) != EOF) {
        if (existingUser.id == user.id) {
            printf("Error: User with ID %d already exists.\n", user.id);
            fclose(file);
            return;
        }
    }
    fclose(file);
    file = fopen(FILE_PATH, "a");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    printf("Enter User Name: ");
    scanf(" %49s", user.name);
    user.age = getValidInteger("Enter User Age: ");
    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);
    printf("User added successfully.\n");
}

void readUsers() {
    FILE *file = fopen(FILE_PATH, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    User user;
    int found = 0;
    printf("\n--- User List ---\n");
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
        found = 1;
    }
    if (!found) {
        printf("No users found.\n");
    }
    fclose(file);
}

void updateUser() {
    FILE *file = fopen(FILE_PATH, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    int id, found = 0;
    id = getValidInteger("Enter the ID of the user to update: ");

    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }
    User user;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            printf("Enter new Name: ");
            scanf(" %49s", user.name);
            user.age = getValidInteger("Enter new Age: ");
        }
        fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
    }
    fclose(file);
    fclose(tempFile);
    if (found) {
        remove(FILE_PATH);
        rename("temp.txt", FILE_PATH);
        printf("User updated successfully.\n");
    } else {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}

void deleteUser() {
    FILE *file = fopen(FILE_PATH, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    int id, found = 0;
    id = getValidInteger("Enter the ID of the user to delete: ");
    FILE *tempFile = fopen("temp.txt", "w");
    if (!tempFile) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }
    User user;
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id != id) {
            fprintf(tempFile, "%d,%s,%d\n", user.id, user.name, user.age);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_PATH);
        rename("temp.txt", FILE_PATH);
        printf("User deleted successfully.\n");
    } else {
        remove("temp.txt");
        printf("User with ID %d not found.\n", id);
    }
}
