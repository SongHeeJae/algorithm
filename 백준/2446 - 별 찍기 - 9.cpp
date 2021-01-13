#include <cstdio>
int main() {
    int n, k=0;
    scanf("%d", &n);
    for (int i = 0; i < n * 2 - 1; i > n - 2 ? k-- : k++, i++) {
        for (int j = 0; j < k; j++) printf(" ");
        for (int j = 0; j < n*2-(k*2) - 1; j++) printf("*");
        printf("\n");
    }
}