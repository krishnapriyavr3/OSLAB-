#include <stdio.h>

int main() {
    int n, at[10], bt[10], ct[10], tt[10], wt[10], temp[10], pr[10], smallest, count = 0, time;
    double avg_tt = 0, avg_wt = 0, end = 0;

    printf("Enter the number of processes\n");
    scanf("%d", &n);

    printf("Enter the arrival time, burst time, and priority of the processes\n");
    for (int i = 0; i < n; i++) {
        printf("p%d\n", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        temp[i] = bt[i]; // Store the original burst time
    }

    pr[9] = 9876; // Ensure no process is selected if no new process is found

    // Track execution of each process over time
    char ganttChart[100] = {0};  // Assuming the maximum time length for Gantt chart is 100

    for (time = 0; count != n; time++) {
        smallest = 9;  // Assume no process is selected
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && pr[i] < pr[smallest] && bt[i] > 0) {
                smallest = i;  // Select the process with highest priority
            }
        }

        if (smallest != 9) {
            bt[smallest]--;  // Decrease the burst time for the selected process
            ganttChart[time] = 'P' + smallest;  // Mark the process executing at this time
            if (bt[smallest] == 0) {
                count++;
                end = time + 1;
                ct[smallest] = end;
                wt[smallest] = end - at[smallest] - temp[smallest];
                tt[smallest] = end - at[smallest];
            }
        }
    }

    // Display the Gantt Chart
    printf("\nGantt Chart: ");
    for (int i = 0; i < time; i++) {
        if (ganttChart[i] != 0) {
            printf(" %c", ganttChart[i]);
        }
    }
    printf("\n");

    // Display process details
    printf("\n---------------------------------------------\n");
    printf("Proc\tAT\tBT\tCT\tWT\tTT\n");
    printf("---------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("p%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], temp[i], ct[i], wt[i], tt[i]);
        avg_wt += wt[i]; // Summing up waiting time
        avg_tt += tt[i]; // Summing up turnaround time
    }

    printf("------------------------------------------------\n");
    printf("Average turn around time: %lf\n", avg_tt / n);
    printf("Average waiting time: %lf", avg_wt / n);

    return 0;
}

