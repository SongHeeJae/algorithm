#include <cstdio>
int n, m, a[10000], c = 0;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        long long int s = 0;
        for (int j = i; j < n; j++) {
            s += a[j];
            if (s == m) c++;
        }
    }
    printf("%d", c);
}