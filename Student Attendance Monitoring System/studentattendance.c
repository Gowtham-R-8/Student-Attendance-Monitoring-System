#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure without typedef
struct Attendance {
    int studentID;
    char date[11]; // DD-MM-YYYY
    char status;   // 'P' or 'A'
    struct Attendance* next;
};

// Head of the linked list
struct Attendance* head = NULL;

// Create a new node
struct Attendance* createNode(int id, const char* date, char status) {
    struct Attendance* newNode = (struct Attendance*)malloc(sizeof(struct Attendance));
    newNode->studentID = id;
    strcpy(newNode->date, date);
    newNode->status = status;
    newNode->next = NULL;
    return newNode;
}

// Add attendance
void addAttendance(int id, const char* date, char status) {
    struct Attendance* newNode = createNode(id, date, status);
    newNode->next = head;
    head = newNode;
    printf("Attendance added.\n");
}

// Delete attendance
void deleteAttendance(int id, const char* date) {
    struct Attendance *temp = head, *prev = NULL;
    while (temp != NULL) {
        if (temp->studentID == id && strcmp(temp->date, date) == 0) {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            printf("Attendance deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Record not found.\n");
}

// Search attendance
void searchAttendance(int id, const char* date) {
    struct Attendance* temp = head;
    while (temp != NULL) {
        if (temp->studentID == id && strcmp(temp->date, date) == 0) {
            printf("Found: ID: %d | Date: %s | Status: %c\n", temp->studentID, temp->date, temp->status);
            return;
        }
        temp = temp->next;
    }
    printf("Record not found.\n");
}

// Display by date
void displayByDate(const char* date) {
    struct Attendance* temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->date, date) == 0) {
            printf("ID: %d | Status: %c\n", temp->studentID, temp->status);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No records for date %s.\n", date);
    }
}

// Reverse display (using recursion)
void displayReverseHelper(struct Attendance* node) {
    if (node == NULL) return;
    displayReverseHelper(node->next);
    printf("ID: %d | Date: %s | Status: %c\n", node->studentID, node->date, node->status);
}

void displayReverse() {
    if (head == NULL) {
        printf("No attendance records.\n");
        return;
    }
    printf("Attendance in reverse order:\n");
    displayReverseHelper(head);
}

// Clone list
struct Attendance* cloneList(struct Attendance* src) {
    if (src == NULL) return NULL;

    struct Attendance* clonedHead = createNode(src->studentID, src->date, src->status);
    struct Attendance* currentSrc = src->next;
    struct Attendance* currentClone = clonedHead;

    while (currentSrc != NULL) {
        currentClone->next = createNode(currentSrc->studentID, currentSrc->date, currentSrc->status);
        currentClone = currentClone->next;
        currentSrc = currentSrc->next;
    }

    return clonedHead;
}

// Free memory
void freeList(struct Attendance* node) {
    while (node != NULL) {
        struct Attendance* temp = node;
        node = node->next;
        free(temp);
    }
}

// Menu
void menu() {
    int choice, id;
    char date[11], status;
    struct Attendance* cloned = NULL;

    while (1) {
        printf("\n--- Student Attendance Monitoring System ---\n");
        printf("1. Add Attendance\n");
        printf("2. Delete Attendance\n");
        printf("3. Search Attendance\n");
        printf("4. Display Attendance by Date\n");
        printf("5. Display in Reverse\n");
        printf("6. Clone Attendance List\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Student ID, Date (DD-MM-YYYY), Status (P/A): ");
                scanf("%d %10s %c", &id, date, &status);
                addAttendance(id, date, status);
                break;
            case 2:
                printf("Enter Student ID and Date (DD-MM-YYYY): ");
                scanf("%d %10s", &id, date);
                deleteAttendance(id, date);
                break;
            case 3:
                printf("Enter Student ID and Date (DD-MM-YYYY): ");
                scanf("%d %10s", &id, date);
                searchAttendance(id, date);
                break;
            case 4:
                printf("Enter Date (DD-MM-YYYY): ");
                scanf("%10s", date);
                displayByDate(date);
                break;
            case 5:
                displayReverse();
                break;
            case 6:
                if (cloned != NULL) {
                    freeList(cloned);
                }
                cloned = cloneList(head);
                printf("Attendance list cloned successfully.\n");
                break;
            case 7:
                freeList(head);
                freeList(cloned);
                printf("Exiting program.\n");
                return;
            default:
                printf("Invalid choice.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}
