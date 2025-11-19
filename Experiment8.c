#include <stdio.h>

int main() {
    int n, i, quantum;
    printf("Enter total number of processes: ");
    scanf("%d", &n);

    int bt[n], rem_bt[n], wt[n], tat[n];
    for (i = 0; i < n; i++) {
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem_bt[i] = bt[i];   // remaining burst time
        wt[i] = 0;           // initialize
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);

    int time = 0;   // current time

    printf("\nGantt Chart: ");

    // Round Robin Simulation
    while (1) {
        int done = 1;

        for (i = 0; i < n; i++) {

            if (rem_bt[i] > 0) {
                done = 0;  // still processes left

                printf(" | P%d ", i + 1);

                if (rem_bt[i] > quantum) {
                    time += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i];
                    rem_bt[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    // Calculate turnaround times
    for (i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    // Output
    printf("|\n\n");
    printf("Process\t BT\t WT\t TAT\n");

    float avg_wt = 0, avg_tat = 0;
    for (i = 0; i < n; i++) {
        printf("P%d\t %d\t %d\t %d\n", i + 1, bt[i], wt[i], tat[i]);
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}
