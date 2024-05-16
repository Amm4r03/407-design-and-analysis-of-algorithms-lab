#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

int compareJobs(const void* a, const void* b) {
    return ((Job*)b)->profit - ((Job*)a)->profit;
}

int findMaxDeadline(Job jobs[], int n) {
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > max) {
            max = jobs[i].deadline;
        }
    }
    return max;
}

void jobSequencing(Job jobs[], int n) {
    qsort(jobs, n, sizeof(Job), compareJobs);

    int maxDeadline = findMaxDeadline(jobs, n);
    char result[maxDeadline];
    int profit = 0;

    int slots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++) {
        slots[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = i;
                profit += jobs[i].profit;
                break;
            }
        }
    }

    int k = 0;
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i] != -1) {
            result[k++] = jobs[slots[i]].id;
        }
    }
    result[k] = '\0';

    printf("Job Sequence: %s\n", result);
    printf("Total Profit: %d\n", profit);
}

int main() {
    Job jobs[] = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);

    jobSequencing(jobs, n);

    return 0;
}
