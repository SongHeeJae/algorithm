#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, m, cnt = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int map[102][102] = { 0 };
bool visit[102][102] = { false };

void checkOutsideSpace(int x, int y) {
    visit[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx > n || ny > m) continue;
        if (visit[nx][ny]) continue;
        if (map[nx][ny] == 1) continue;
        checkOutsideSpace(nx, ny);
    }
}

bool checkMelting(int x, int y) {
    int c = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (visit[nx][ny] && map[nx][ny] == 0) c++;
    }
    return c >= 2;
}

int calTime() {
    int time = 0;
    checkOutsideSpace(0, 0);
    vector<pair<int, int>> melted;
    while (1) {
        time++;
        melted.clear();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] == 1 && checkMelting(i, j)) {
                    melted.push_back({ i, j });
                    cnt--;
                }
            }
        }
        if (cnt == 0) break;
        for (int i = 0; i < melted.size(); i++) {
            map[melted[i].first][melted[i].second] = 0;
            checkOutsideSpace(melted[i].first, melted[i].second);
        }
    }

    return time;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 1) cnt++;
        }
    }
    printf("%d", calTime());
}

/*
먼저 바깥 공간을 다 구해놓고, 치즈가 녹을 때마다 바깥 공간을 업데이트해주었습니다.
그리고 바깥 공간과 접촉면이 두 개 이상이면, 치즈를 녹여주었습니다.
*/