#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n;
int map[125][125];
bool visit[125][125];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool input() {
    scanf("%d", &n);
    if (!n) return false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) scanf("%d", &map[i][j]);
    return true;
}

void init() {
    memset(visit, false, sizeof(visit));
}

void minRupee() {
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    visit[0][0] = true;
    pq.push({ map[0][0], {0, 0} });
    while (!pq.empty()) {
        int c = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        if (x == n - 1 && y == n - 1) break;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visit[nx][ny]) continue;
            visit[nx][ny] = true;
            map[nx][ny] = map[nx][ny] + c;
            pq.push({ map[nx][ny], {nx, ny} });
        }
    }
}

int main() {
    for (int i = 1; input(); i++) {
        init();
        minRupee();
        printf("Problem %d: %d\n", i, map[n - 1][n - 1]);
    }
}

/*
우선순위큐를 이용하여 좌표의 누적합이 낮은 곳으로만 이동하다가, 도착점에 도달하면 종료하였습니다.
*/

