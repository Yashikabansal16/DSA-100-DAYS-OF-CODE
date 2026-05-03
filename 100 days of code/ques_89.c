/*Problem Statement
Given an array of integers where each element represents the number of pages in a book,
and m students, allocate books such that each student gets at least one book and the maximum 
number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113*/

#include <stdio.h>

// Check how many students are needed if max pages = limit
int countStudents(int pages[], int n, int limit) {
    int students = 1;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (sum + pages[i] <= limit) {
            sum += pages[i];
        } else {
            students++;
            sum = pages[i];
        }
    }
    return students;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int pages[n];
    int sum = 0, max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
        sum += pages[i];
        if (pages[i] > max)
            max = pages[i];
    }

    int low = max;
    int high = sum;
    int ans = sum;

    // Binary Search
    while (low <= high) {
        int mid = (low + high) / 2;

        int students = countStudents(pages, n, mid);

        if (students <= m) {
            ans = mid;        // possible answer
            high = mid - 1;   // try smaller max
        } else {
            low = mid + 1;    // increase limit
        }
    }

    printf("%d", ans);

    return 0;
}
