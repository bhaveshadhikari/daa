#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;       // Job ID
    int profit;   // Profit from the job
    int deadline; // Deadline for the job
} Job;

int compareJobs(const void *a, const void *b) {
    return ((Job *)b)->profit - ((Job *)a)->profit;
}
void jobSequencing(Job jobs[], int n) {
    // Sort jobs in descending order of profit
    qsort(jobs, n, sizeof(Job), compareJobs);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {  // Find the maximum deadline
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Create a time slot array and initialize all slots to -1 (free)
    int slots[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        slots[i] = -1;
    int totalProfit = 0;

    // Iterate through jobs
    for (int i = 0; i < n; i++) {
        // Find free slot for this job, starting from the last possible slot
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id; // Assign job to this slot
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Print the sequence of jobs and total profit
    printf("Selected jobs in order: ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slots[i] != -1)
            printf("J%d ", slots[i]);
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

int main() {
    int n = 5;
    Job jobs[] = {
        {1, 100, 2},
        {2, 19, 1},
        {3, 27, 2},
        {4, 25, 1},
        {5, 15, 3}
    };
    jobSequencing(jobs, n);
    return 0;
}

/*
Output:

Selected jobs in order: J3 J1 J5 
Total profit: 142
*/
