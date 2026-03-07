/*Problem: Queue Using Array - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of elements)
- Second line: n space-separated integers

Output:
- Print queue elements from front to rear, space-separated

Example:
Input:
5
10 20 30 40 50

Output:
10 20 30 40 50*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = value;
    temp->next = NULL;

    if(front == NULL && rear == NULL) {
        front = rear = temp;
    }
    else {
        rear->next = temp;
        rear = temp;
    }
}

void display() {
    struct node *ptr = front;

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main() {
    int n, x;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    display();

    return 0;
}