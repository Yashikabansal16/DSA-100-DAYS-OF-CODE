/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/

#include <stdlib.h>

// Compare function for sorting by start time
int cmp(const void* a, const void* b) {
    int* x = *(int**)a;
    int* y = *(int**)b;
    return x[0] - y[0];
}

// Swap
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Heapify down (min heap)
void heapifyDown(int heap[], int size, int i) {
    while (1) {
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest == i) break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

// Heapify up
void heapifyUp(int heap[], int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i]) break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

// Main function
int minMeetingRooms(int** intervals, int intervalsSize) {
    if (intervalsSize == 0) return 0;

    // Sort intervals by start time
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int* heap = (int*)malloc(intervalsSize * sizeof(int));
    int size = 0;

    for (int i = 0; i < intervalsSize; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // If room free, reuse
        if (size > 0 && heap[0] <= start) {
            heap[0] = end;
            heapifyDown(heap, size, 0);
        } else {
            // New room
            heap[size] = end;
            heapifyUp(heap, size);
            size++;
        }
    }

    free(heap);
    return size;
}