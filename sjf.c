#include <stdio.h>
int main() {
    int at[10], bt[10], wt[10], ft[10], tat[10];
    int i, j, n, temp1, temp2, temp3, x = 0, completed = 0, min_index;
    int twt = 0, ttat = 0, min_bt;
    float awt1, atat1;
    int is_completed[10] = {0};
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter arrival times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
    }
    printf("Arrival Time\tBurst Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\n", at[i], bt[i]);
    }
    printf("Calculating Finishing Time, Waiting Time, Turnaround Time\n");
    while (completed != n) {
        min_bt = 9999;
        min_index = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= x && is_completed[i] == 0) {
                if (bt[i] < min_bt) {
                    min_bt = bt[i];
                    min_index = i;
                } else if (bt[i] == min_bt) {
                    if (at[i] < at[min_index]) {
                        min_index = i;
                    }
                }
            }
        }
        if (min_index == -1) {
            x++; // CPU idle
        } else {
            x += bt[min_index];
            ft[min_index] = x;
            tat[min_index] = ft[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];
            is_completed[min_index] = 1;
            completed++;
            twt += wt[min_index];
            ttat += tat[min_index];
            printf("Process %d: FT=%d, WT=%d, TAT=%d\n", min_index + 1, ft[min_index], wt[min_index], tat[min_index]);
        }
    }
    awt1 = (float)twt / n;
    atat1 = (float)ttat / n;
    printf("Average Waiting Time: %.2f\n", awt1);
    printf("Average Turnaround Time: %.2f\n", atat1);
    return 0;
}
