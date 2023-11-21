//#include <stdio.h>
//
//struct cpus {
//    int pname;
//    int burst;
//    int arrival;
//    int priority;
//} s[10];
//
//int main() {
//    int num_p, i, j, k;
//    int arr[100], wt[10], rt[10], tat[10];
//
//    printf("Enter number of processes: ");
//    scanf("%d", &num_p);
//
//    for (i = 0; i < num_p; i++) {
//        printf("Enter data for process %d in order pname burst arrival and priority: ", i + 1);
//        scanf("%d %d %d %d", &s[i].pname, &s[i].burst, &s[i].arrival, &s[i].priority);
//    }
//
//    k = 0;
//
//    for (i = 0; i < num_p; i++) {
//        for (j = 0; j < s[i].burst; j++) {
//            arr[k] = s[i].pname;
//            k++;
//        }
//    }
//
//    // Sort processes based on burst time (SJF)
//    for (i = 0; i < num_p - 1; i++) {
//        for (j = 0; j < num_p - i - 1; j++) {
//            if (s[j].burst > s[j + 1].burst) {
//                struct cpus temp = s[j];
//                s[j] = s[j + 1];
//                s[j + 1] = temp;
//            }
//        }
//    }
//
//    // Calculate waiting time (wt), turnaround time (tat), and response time (rt)
//    int total_waiting_time = 0;
//    int total_turnaround_time = 0;
//    for (i = 0; i < num_p; i++) {
//        rt[i] = total_waiting_time;
//        wt[i] = rt[i];
//        total_waiting_time += s[i].burst;
//        tat[i] = total_waiting_time;
//        total_turnaround_time += total_waiting_time;
//    }
//
//    // Print response times
//    printf("Response Times:\n");
//    for (i = 0; i < num_p; i++) {
//        printf("P%d: %d\n", s[i].pname, rt[i]);
//    }
//
//    // Print waiting times
//    printf("Waiting Times:\n");
//    for (i = 0; i < num_p; i++) {
//        printf("P%d: %d\n", s[i].pname, wt[i]);
//    }
//
//    // Print turnaround times
//    printf("Turnaround Times:\n");
//    for (i = 0; i < num_p; i++) {
//        printf("P%d: %d\n", s[i].pname, tat[i]);
//    }
//
//    return 0;
//}

//#include <stdio.h>
//
//struct cpus {
//    int pname;
//    int burst;
//    int arrival;
//    int priority;
//} s[10];
//
//int main() {
//    int num_p, i, j, k;
//    int arr[100], wt[10], rt[10], tat[10], execution_order[10];
//
//    printf("Enter number of processes: ");
//    scanf("%d", &num_p);
//
//    for (i = 0; i < num_p; i++) {
//        printf("Enter data for process %d in order pname burst arrival and priority: ", i + 1);
//        scanf("%d %d %d %d", &s[i].pname, &s[i].burst, &s[i].arrival, &s[i].priority);
//    }
//
//    k = 0;
//
//    for (i = 0; i < num_p; i++) {
//        for (j = 0; j < s[i].burst; j++) {
//            arr[k] = s[i].pname;
//            k++;
//        }
//    }
//
//    // Sort processes based on burst time (SJF)
//    for (i = 0; i < num_p - 1; i++) {
//        for (j = 0; j < num_p - i - 1; j++) {
//            if (s[j].burst > s[j + 1].burst) {
//                struct cpus temp = s[j];
//                s[j] = s[j + 1];
//                s[j + 1] = temp;
//            }
//        }
//    }

    // Calculate waiting time (wt), turnaround time (tat), response time (rt), and execution order
//    int total_waiting_time = 0;
//    int total_turnaround_time = 0;
//    for (i = 0; i < num_p; i++) {
//        rt[i] = total_waiting_time;
//        wt[i] = rt[i];
//        total_waiting_time += s[i].burst;
//        tat[i] = total_waiting_time;
//        total_turnaround_time += total_waiting_time;
//        execution_order[i] = s[i].pname;
//    }
//
//    // Print execution order
//    printf("Execution Order:\n");
//    for (i = 0; i < num_p; i++) {
//        printf("%d ", execution_order[i]);
//    }
//    printf("\n");
//
//    // Print response times
//    printf("Response Times:\n");
//    for (i = 0; i < num_p; i++) {
//        printf("P%d: %d\n", s[i].pname, rt[i]);
//    }
//
//    // Print waiting times
//    printf("Waiting Times:\n");
//    for (i = 0; i < num_p; i++) {
//        printf("P%d: %d\n", s[i].pname, wt[i]);
//    }
//
//    // Print turnaround times
//    printf("Turnaround Times:\n");
//    for (i = 0; i < num_p; i++) {
//        printf("P%d: %d\n", s[i].pname, tat[i]);
//    }
//
//    return 0;
//}

#include <stdio.h>

struct cpus {
    int pname;
    int burst;
    int arrival;
    int priority;
} s[10];

int main(){
    int num_p, i, j, k;
    int arr[100], wt[10], rt[10], tat[10], execution_order[10];

    printf("Enter number of processes: ");
    scanf("%d", &num_p);

    for (i = 0; i < num_p; i++) {
        printf("Enter data for process %d in order pname burst arrival and priority: ", i + 1);
        scanf("%d %d %d %d", &s[i].pname, &s[i].burst, &s[i].arrival, &s[i].priority);
    }

    // Sort processes based on arrival time
    for (i = 0; i < num_p - 1; i++) {
        for (j = 0; j < num_p - i - 1; j++) {
            if (s[j].arrival > s[j + 1].arrival) {
                struct cpus temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    k = 0;

    for (i = 0; i < num_p; i++) {
        for (j = 0; j < s[i].burst; j++) {
            arr[k] = s[i].pname;
            k++;
        }
    }

    // Calculate waiting time (wt), turnaround time (tat), response time (rt), and execution order
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (i = 0; i < num_p; i++) {
        rt[i] = total_waiting_time;
        wt[i] = rt[i] - s[i].arrival; // Adjusted waiting time calculation
        if (wt[i] < 0) wt[i] = 0;  // Waiting time cannot be negative
        total_waiting_time += s[i].burst;
        tat[i] = total_waiting_time;
        total_turnaround_time += total_waiting_time;
        execution_order[i] = s[i].pname;
    }

    // Print execution order
    printf("Execution Order:\n");
    for (i = 0; i < num_p; i++) {
        printf("%d ", execution_order[i]);
    }
    printf("\n");

    // Print response times
    printf("Response Times:\n");
    for (i = 0; i < num_p; i++) {
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

