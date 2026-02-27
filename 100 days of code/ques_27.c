/*Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic
memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
}

// Function to find intersection point
void findIntersection(struct Node* head1, struct Node* head2) {
    struct Node* temp1 = head1;
    
    while (temp1 != NULL) {
        struct Node* temp2 = head2;
        
        while (temp2 != NULL) {
            if (temp1->data == temp2->data) {
                printf("%d\n", temp1->data);
                return;
            }
            temp2 = temp2->next;
        }
        
        temp1 = temp1->next;
    }
    
    printf("No Intersection\n");
}

int main() {
    int n, m, value;
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    
    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }
    
    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }
    
    // Find intersection
    findIntersection(head1, head2);
    
    return 0;
}