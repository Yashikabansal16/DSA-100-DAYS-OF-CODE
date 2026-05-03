/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. 
Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60*/

#include <stdio.h>

// Count painters needed for given max time limit
int countPainters(int boards[], int n, int limit) {
    int painters = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + boards[i] <= limit) {
            sum += boards[i];
        } else {
            painters++;
            sum = boards[i];
        }
    }
    return painters;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int boards[n];
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &boards[i]);
        sum += boards[i];
        if (boards[i] > max)
            max = boards[i];
    }

    int low = max;
    int high = sum;
    int ans = sum;

    // Binary Search
    while (low <= high) {
        int mid = (low + high) / 2;

        int painters = countPainters(boards, n, mid);

        if (painters <= k) {
            ans = mid;        // possible answer
            high = mid - 1;   // try smaller time
        } else {
            low = mid + 1;    // increase time
        }
    }

    printf("%d", ans);

    return 0;
}
