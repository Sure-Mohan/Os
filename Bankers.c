#include <stdio.h>
int main() {
    int total[3], available[3], work[3], max[5][3], alloc[5][3], need[5][3], safe[5];
    char finish[5] = {'f', 'f', 'f', 'f', 'f'};
    int i, j, k, count = 0;
    printf("Enter instances of each resources:\n");
    for (i = 0; i < 3; i++) {
        scanf("%d", &total[i]);
    }
    printf("Enter maximum no of resources for each process:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter process %d resource %d: ", i, j + 1);
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter no of resources allocated to each process:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter the resource %d allocated to process %d: ", j + 1, i);
            scanf("%d", &alloc[i][j]);
        }
    }
    for (j = 0; j < 3; j++) {
        int sum = 0;
        for (i = 0; i < 5; i++) {
            need[i][j] = max[i][j] - alloc[i][j];
            sum += alloc[i][j];
        }
        available[j] = total[j] - sum;
        work[j] = available[j];
    }
    printf("Allocated resources:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\n");
    }
    printf("Maximum resources:\n");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }
    printf("Available resources: ");
    for (i = 0; i < 3; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");

    while (count < 5) {
        int found = 0;
        for (i = 0; i < 5; i++) {
            if (finish[i] == 'f') {
                for (j = 0; j < 3; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == 3) {
                    for (k = 0; k < 3; k++) {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = 't';
                    safe[count++] = i;
                    found = 1;
                }
            }
        }
        if (!found) {
            break;
        }
    }
    if (count == 5) {
        printf("Safe sequence is:\n");
        for (i = 0; i < 5; i++) {
            printf("P%d ", safe[i]);
        }
    } else {
        printf("System is not in a safe state.\n");
    }
    return 0;
}
