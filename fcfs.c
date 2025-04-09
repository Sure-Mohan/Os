#include <stdio.h>
int main() {
    int at[10], bt[10], wt[10], ft[10], tat[10], i, j, n, temp1, temp2, x = 0;
    int twt = 0, ttat = 0;
    float awt1, atat1;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter arrival times:\n");
    for(i = 0; i < n; i++) scanf("%d", &at[i]);
    printf("Enter burst times:\n");
    for(i = 0; i < n; i++) scanf("%d", &bt[i]);
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(at[i] > at[j]) {
                temp1 = at[i]; at[i] = at[j]; at[j] = temp1;
                temp2 = bt[i]; bt[i] = bt[j]; bt[j] = temp2;
            }
    printf("Arrival Time\tBurst Time\n");
    for(i = 0; i < n; i++) printf("%d\t\t%d\n", at[i], bt[i]);
    printf("Calculating Finishing Time, Waiting Time, Turnaround Time\n");
    for(i = 0; i < n; i++) {
        x += bt[i];
        ft[i] = x;
        wt[i] = ft[i] - at[i] - bt[i];
        tat[i] = ft[i] - at[i];
        twt += wt[i];
        ttat += tat[i];
        printf("Process %d: FT=%d, WT=%d, TAT=%d\n", i+1, ft[i], wt[i], tat[i]);
    }
    awt1 = (float)twt/n;
    atat1 = (float)ttat/n;
    printf("Average Waiting Time: %.2f\n", awt1);
    printf("Average Turnaround Time: %.2f\n", atat1);
    return 0;
}
