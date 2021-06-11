#include <cstdio>

int m, n, k, a, b, c, d, joi[3][1001][1001] = { 0 };
char map[1001][1002] = { 0 };

int main() {
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%s", &map[i][1]);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            joi[0][i][j] = (map[i][j] == 'J') + joi[0][i - 1][j] + joi[0][i][j - 1] - joi[0][i - 1][j - 1];
            joi[1][i][j] = (map[i][j] == 'O') + joi[1][i - 1][j] + joi[1][i][j - 1] - joi[1][i - 1][j - 1];
            joi[2][i][j] = (map[i][j] == 'I') + joi[2][i - 1][j] + joi[2][i][j - 1] - joi[2][i - 1][j - 1];
        }
    }
    while (k--) {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int i = 0; i < 3; i++) {
            printf("%d ", joi[i][c][d] - joi[i][a - 1][d] - joi[i][c][b - 1] + joi[i][a - 1][b - 1]);
        }
        printf("\n");
    }
}

/*
J[i][j] = 왼쪽 위 좌표가 (1,1), 오른쪽 아래 좌표가 (i, j)인 직사각형에서 J의 개수를 저장해줍니다.
J[i][j] = J[i - 1][j] + J[i][j - 1] - J[i - 1][j - 1] + (map[i][j] == 'J' ? 1 : 0) 으로 계산될 수 있습니다.

입력 값이 (a, b, c, d)일 때, 그 범위 내에 있는 J의 개수는,
J[c][d] - J[a - 1][d] - J[c][b - 1] + J[a - 1][b - 1] 입니다.
*/