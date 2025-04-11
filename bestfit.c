#include <stdio.h>
void bestFit(int b[], int m, int p[], int n) {
    int alloc[10], i, j, bi;
    for (i = 0; i < n; i++) {
        alloc[i] = -1;
        for (j = 0, bi = -1; j < m; j++)
            if (b[j] >= p[i] && (bi == -1 || b[j] < b[bi]))
                bi = j;
        if (bi != -1) {
            alloc[i] = bi;
            b[bi] -= p[i];
        }
    }
    printf("Process No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%s\n", i, p[i], alloc[i] != -1 ? (char[3]){alloc[i] + '0', '\0'} : "Not Allocated");
}
int main() {
    int i, m, n, b[10], p[10];
    printf("Enter no. of blocks: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter %d block size: ", i);
        scanf("%d", &b[i]);
    }
    printf("Enter no. of processes: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter %d process size: ", i);
        scanf("%d", &p[i]);
    }
    bestFit(b, m, p, n);
    return 0;
}
