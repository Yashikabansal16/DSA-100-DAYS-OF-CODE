/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop() {
    if(top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int evaluate(char exp[]) {
    int i = 0;
    while(exp[i] != '\0') {

        if(exp[i] == ' ') {
            i++;
            continue;
        }

        if(isdigit(exp[i])) {
            int num = 0;

            while(isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }

            push(num);
        }

        else {
            int b = pop();
            int a = pop();

            switch(exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/': push(a / b); break;
            }
            i++;
        }
    }

    return pop();
}

int main() {
    char exp[100];

    printf("Enter Postfix Expression:\n");
    fgets(exp, sizeof(exp), stdin);

    int result = evaluate(exp);

    printf("Result = %d", result);

    return 0;
}