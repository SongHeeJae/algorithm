#include <iostream>
#include <queue>
using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int n, m;
int sx, sy, ex, ey, ans = 0;
char map[300][301];
queue<pair<int, int>> q1, q2;
bool visit[300][300] = { false }, finished = false;

int main() {
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    for (int i = 0; i < n; i++) {
        scanf("%s", map[i]);
    }
    q1.push({ sx - 1, sy - 1 });
    visit[sx - 1][sy - 1] = true;
    while (!finished) {
        ans++;
        queue<pair<int, int>>& cur = ans % 2 ? q1 : q2;
        queue<pair<int, int>>& next = ans % 2 ? q2 : q1;
        while (!cur.empty()) {
            int x = cur.front().first;
            int y = cur.front().second;
            cur.pop();
            if (map[x][y] == '#') {
                finished = true;
                break;
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || visit[nx][ny]) continue;
                visit[nx][ny] = true;
                if (map[nx][ny] == '1') {
                    next.push({ nx, ny });
                }
                else {
                    cur.push({ nx, ny });
                }
            }
        }
    }
    printf("%d", ans);
}

/*
현재 사용하는 큐와 다음에 사용될 큐 두 개를 미리 선언해줍니다.
현재 큐에서 BFS를 수행한 뒤, 친구가 있어서 진입하지 못하는 공간이라면, 다음 큐에 그 위치를 기억해줍니다.
주난이가 점프를 하고 난 후, 다음 큐에서 다시 BFS를 수행해줍니다.
*/