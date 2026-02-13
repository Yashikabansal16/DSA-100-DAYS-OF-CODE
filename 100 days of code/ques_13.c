/*Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, 
traverse the matrix in a clockwise manner and continue moving inward layer by layer until 
all elements are visited.

Input:
- First line: two integers r and c representing the number of rows and columns
- Next r lines: c integers each representing the matrix elements

Output:
- Print all visited elements in the order of traversal, separated by spaces

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5*/

#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int mat[r][c];

    // Input matrix
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int top = 0, bottom = r - 1;
    int left = 0, right = c - 1;

    while(top <= bottom && left <= right) {

        // Top row
        for(int j = left; j <= right; j++) {
            printf("%d ", mat[top][j]);
        }
        top++;

        // Right column
        for(int i = top; i <= bottom; i++) {
            printf("%d ", mat[i][right]);
        }
        right--;

        // Bottom row
        if(top <= bottom) {
            for(int j = right; j >= left; j--) {
                printf("%d ", mat[bottom][j]);
            }
            bottom--;
        }

        // Left column
        if(left <= right) {
            for(int i = bottom; i >= top; i--) {
                printf("%d ", mat[i][left]);
            }
            left++;
        }
    }

    return 0;
}

