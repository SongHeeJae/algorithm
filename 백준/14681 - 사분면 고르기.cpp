#include <cstdio>
int main() {
    int x, y;
    scanf("%d %d", &x, &y);
    if (x > 0) printf("%d", y > 0 ? 1 : 4);
    else printf("%d", y > 0 ? 2 : 3);
}