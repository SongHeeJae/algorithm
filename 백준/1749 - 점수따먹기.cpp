#include <cstdio>

int n, m, arr[201][201] = { 0 }, ans = -10000;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[i][j]);
            arr[i][j] += arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = i; k <= n; k++) {
                for (int l = j; l <= m; l++) {
                    int sum = arr[k][l] - arr[i-1][l] - arr[k][j-1] + arr[i - 1][j - 1];
                    if (ans < sum) ans = sum;
                }
            }
        }
    }
    printf("%d", ans);
}

/*
arr[i][j] = 왼쪽 위 좌표가 (1, 1), 오른쪽 아래 좌표가 (i, j)인 직사각형의 넓이를 저장해줍니다.
만들어질 수 있는 모든 직사각형을 검사하면서, 그 넓이의 최댓값을 찾아줍니다.
*/