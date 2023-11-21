#include <stdio.h>

struct cpus {
    int pname;
    int burst;
    int arrival;
    int priority;
} s[10];

int main() {
    int num_p, i;
    int wt[10], rt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &num_p);

    for (i = 0; i < num_p; i++) {
        printf("Enter data for process %d in order pname burst arrival and priority: ", i + 1);
        scanf("%d %d %d %d", &s[i].pname, &s[i].burst, &s[i].arrival, &s[i].priority);
    }

    // Calculate waiting time (wt), turnaround time (tat), and response time (rt)
    wt[0] = 0; // Waiting time for the first process is zero
    rt[0] = 0; // Response time for the first process is zero

    for (i = 1; i < num_p; i++) {
        wt[i] = wt[i - 1] + s[i - 1].burst;
        rt[i] = wt[i];
    }

    // Calculate turnaround time (tat)
    for (i = 0; i < num_p; i++) {
        tat[i] = wt[i] + s[i].burst;
    }

    // Print turnaround times
    printf("Turnaround Times:\n");
    for (i = 0; i < num_p; i++) {
        printf("P%d: %d\n", s[i].pname, tat[i]);
    }

    // Print waiting times
    printf("Waiting Times:\n");
    for (i = 0; i < num_p; i++) {
        printf("P%d: %d\n", s[i].pname, wt[i]);
    }

    // Print response times
    printf("Response Times:\n");
    for (i = 0; i < num_p; i++) {
        printf("P%d: %d\n", s[i].pname, rt[i]);
    }

    return 0;
}

