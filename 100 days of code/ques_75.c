/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the 
longest contiguous subarray whose sum is equal to zero.

Input Format
An integer array arr[].

Output Format
Print the length of the longest subarray with sum equal to zero.

Sample Input
15 -2 2 -8 1 7 10 23

Sample Output
5*/

#include <stdio.h>

int maxLen(int arr[], int n) {
    int max_len = 0;
    int sum = 0;

    // Hash map using array (for simplicity)
    // Assuming sum range is manageable
    int hash[10000] = {0}; 
    int visited[10000] = {0};

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        // Case 1: sum is 0
        if (sum == 0) {
            max_len = i + 1;
        }

        // Case 2: sum seen before
        if (visited[sum + 5000]) {
            int prev_index = hash[sum + 5000];
            int length = i - prev_index;
            if (length > max_len)
                max_len = length;
        } else {
            // store first occurrence
            hash[sum + 5000] = i;
            visited[sum + 5000] = 1;
        }
    }

    return max_len;
}

int main() {
    int arr[] = {15, -2, 2, -8, 1, 7, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("%d", maxLen(arr, n));
    return 0;
}
