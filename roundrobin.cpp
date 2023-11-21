#include <stdio.h>

struct cpus {
    int pname;
    int burst;
    int arrival;
    int priority;
} s[10];

int main() {
    int num_p, i, quantum, time = 0;
    int remaining_burst[10], wt[10], rt[10], tat[10], execution_order[100], execution_time[100];

    printf("Enter number of processes: ");
    scanf("%d", &num_p);

    printf("Enter time quantum for Round Robin: ");
    scanf("%d", &quantum);

    for (i = 0; i < num_p; i++) {
        printf("Enter data for process %d in order pname burst arrival and priority: ", i + 1);
        scanf("%d %d %d %d", &s[i].pname, &s[i].burst, &s[i].arrival, &s[i].priority);
        remaining_burst[i] = s[i].burst;
    }

    int index = 0; // Index for the execution_order array

    while (1) {
        int completed = 1;

        for (i = 0; i < num_p; i++) {
            if (remaining_burst[i] > 0) {
                completed = 0; // There are still processes to execute

                if (remaining_burst[i] > quantum) {
                    time += quantum;
                    remaining_burst[i] -= quantum;
                } else {
                    time += remaining_burst[i];
                    wt[i] = time - s[i].burst - s[i].arrival;
                    remaining_burst[i] = 0;

                    // Store execution order and execution time
                    execution_order[index] = s[i].pname;
                    execution_time[index] = time;
                    index++;
                }
            }
        }

        if (completed) {
            break; // All processes have completed execution
        }
    }

    // Calculate turnaround time (tat) and response time (rt)
    for (i = 0; i < num_p; i++) {
        tat[i] = wt[i] + s[i].burst;
        rt[i] = wt[i];
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

    // Print sequence of execution
    printf("Sequence of Execution:\n");
    for (i = 0; i < index; i++) {
        printf("P%d ", execution_order[i]);
    }
    printf("\n");

    // Print execution time for each process
    printf("Execution Time:\n");
    for (i = 0; i < index; i++) {
        printf("P%d: %d\n", execution_order[i], execution_time[i]);
    }

    return 0;
}

