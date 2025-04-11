#include <stdio.h>
int main() {
    int n, a[50], b[10], m, i, k = 0, j, c = 0, hit;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter page numbers:\n");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter number of frames: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) b[i] = -1;
    printf("\nRef\tString\tPage\tFrames\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t\t", a[i]);
        hit = 0;
        for (j = 0; j < m; j++)
            if (b[j] == a[i]) hit = 1;
        if (!hit) {
            b[k] = a[i];
            k = (k + 1) % m;
            c++;
        }
        for (j = 0; j < m; j++) printf("%d\t", b[j]);
        printf("\n");
    }
    printf("\nPage fault count is: %d\n", c);
    return 0;
}
