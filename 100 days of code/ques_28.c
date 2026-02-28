/*Problem: Circular Linked List Creation and Traversal - Implement using linked list 
with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the circular linked list elements starting from head, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, value;

    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    // Read number of nodes
    scanf("%d", &n);

    if (n <= 0)
        return 0;

    // Create circular linked list
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        // Allocate memory for new node
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    // Make it circular
    temp->next = head;

    // Traverse and print circular linked list
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    return 0;
}