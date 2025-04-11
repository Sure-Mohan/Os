#include <stdio.h>
void worstFit(int b[], int m, int p[], int n) {
    int alloc[10], i, j, c;
    for (i = 0; i < n; i++) {
        alloc[i] = -1;
        for (j = 0, c = -1; j < m; j++)
            if (b[j] >= p[i] && (c == -1 || b[j] > b[c]))
                c= j;
        if (c != -1) {
            alloc[i] = c;
            b[c] -= p[i];
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
    worstFit(b, m, p, n);
    return 0;
}
