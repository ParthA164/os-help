#include <stdio.h>

struct cpus {
    int pname;
    int burst;
    int arrival;
    int priority;
} s[10];

int main() {
    int num_p, i, time = 0;
    int remaining_burst[10], wt[10], rt[10], tat[10], execution_order[100];

    printf("Enter number of processes: ");
    scanf("%d", &num_p);

    for (i = 0; i < num_p; i++) {
        printf("Enter data for process %d in order pname burst arrival and priority: ", i + 1);
        scanf("%d %d %d %d", &s[i].pname, &s[i].burst, &s[i].arrival, &s[i].priority);
        remaining_burst[i] = s[i].burst;
    }

    int completed = 0;

    while (completed < num_p) {
        int min_burst = 9999; // A high value to find the minimum burst time
        int selected_process = -1;

        for (i = 0; i < num_p; i++) {
            if (s[i].arrival <= time && remaining_burst[i] > 0 && s[i].burst < min_burst) {
                min_burst = s[i].burst;
                selected_process = i;
            }
        }

        if (selected_process == -1) {
            time++; // No process is ready yet
            continue;
        }

        remaining_burst[selected_process]--;

        if (remaining_burst[selected_process] == 0) {
            completed++;
            tat[selected_process] = time + 1 - s[selected_process].arrival;
            wt[selected_process] = tat[selected_process] - s[selected_process].burst;
        }

        execution_order[time] = s[selected_process].pname;
        time++;
    }

    // Print execution order
    printf("Execution Order:\n");
    for (i = 0; i < time; i++) {
        printf("%d ", execution_order[i]);
    }
    printf("\n");

    // Print response times
    printf("Response Times:\n");
    for (i = 0; i < num_p; i++) {
        rt[i] = wt[i]; // Response time is the same as waiting time in preemptive SJF
        printf("P%d: %d\n", s[i].pname, rt[i]);
    }

    // Print waiting times
    printf("Waiting Times:\n");
    for (i = 0; i < num_p; i++) {
        printf("P%d: %d\n", s[i].pname, wt[i]);
    }

    // Print turnaround times
    printf("Turnaround Times:\n");
    for (i = 0; i < num_p; i++) {
        printf("P%d: %d\n", s[i].pname, tat[i]);
    }

    return 0;
}

