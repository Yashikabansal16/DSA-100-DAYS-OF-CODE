/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/

#include <stdio.h>
#include <stdlib.h>

// Comparator for sorting intervals by start time
int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    // Step 1: sort intervals by start time
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    // Allocate result
    int** result = (int**)malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(intervalsSize * sizeof(int));

    int idx = 0;

    // Initialize with first interval
    result[idx] = (int*)malloc(2 * sizeof(int));
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];
    (*returnColumnSizes)[idx] = 2;

    // Step 2: merge intervals
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] <= result[idx][1]) {
            // Overlapping → merge
            if (intervals[i][1] > result[idx][1]) {
                result[idx][1] = intervals[i][1];
            }
        } else {
            // No overlap → new interval
            idx++;
            result[idx] = (int*)malloc(2 * sizeof(int));
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
            (*returnColumnSizes)[idx] = 2;
        }
    }

    *returnSize = idx + 1;
    return result;
}