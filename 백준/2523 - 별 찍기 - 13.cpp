#include <cstdio>
int main() {
    int n, k = 0;
    scanf("%d", &n);
    for (int i = 0; i < n * 2 - 1; i++) {
        for (int j = 0; j <= k; j++)
            printf("*");
        k = i >= n - 1 ? k - 1 : k + 1;
        printf("\n");
    }
}