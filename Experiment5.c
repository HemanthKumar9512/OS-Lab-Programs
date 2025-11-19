#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], pr[n], rt[n], wt[n], tat[n], p[n];
    int completed = 0, time = 0;

    for (i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        printf("Priority of P%d: ", i + 1);
        scanf("%d", &pr[i]);
        rt[i] = bt[i]; // remaining time
    }

    while (completed != n) {
        int highest = -1, hp = -1;

        // select highest priority ready process
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && pr[i] > hp) {
                hp = pr[i];
                highest = i;
            }
        }

        rt[highest]--;  // run for 1 time unit
        time++;

        if (rt[highest] == 0) {
            completed++;
            tat[highest] = time;
            wt[highest] = tat[highest] - bt[highest];
        }
    }

    printf("\nProcess\tPri\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", p[i], pr[i], bt[i], wt[i], tat[i]);

    return 0;
}
