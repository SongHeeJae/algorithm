#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;
int w, h, ox, oy, ans, nums[10];
char map[20][20];
bool visit[20][20], nvisit[10];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int d[20][20][20][20] = { 0 };
vector<pair<int, int>> pos;

bool setDist() {
    pos.push_back({ ox, oy });
    for (int i = 1; i < pos.size(); i++) {
        int cnt = 0;
        int cx = pos[i].first;
        int cy = pos[i].second;
        memset(visit, false, sizeof(visit));
        queue<pair<pair<int, int>, int>> q;
        visit[cx][cy] = true;
        q.push({ { cx, cy }, 0 });
        while (!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int c = q.front().second;
            if (map[x][y] == '*') {
                d[x][y][cx][cy] = d[cx][cy][x][y] = c;
                cnt++;
                if (cnt == pos.size() - 1) break;
            }
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if (visit[nx][ny]) continue;
                if (map[nx][ny] == 'x') continue;
                visit[nx][ny] = true;
                q.push({ { nx, ny }, c + 1 });
            }
        }
        if (cnt != pos.size() - 1) return false;
    }
    pos.pop_back();
    return true;
}

void dfs(int c) {
    if (c == pos.size()) {
        int dist = 0, tx = ox, ty = oy;
        for (int i = 0; i < c; i++) {
            dist += d[tx][ty][pos[nums[i]].first][pos[nums[i]].second];
            tx = pos[nums[i]].first;
            ty = pos[nums[i]].second;
        }
        ans = min(ans, dist);
        return;
    }
    for (int i = 0; i < pos.size(); i++) {
        if (nvisit[i]) continue;
        nvisit[i] = true;
        nums[c] = i;
        dfs(c + 1);
        nvisit[i] = false;
    }
}
int main() {
    while (scanf("%d %d", &w, &h) && w) {
        ans = INF;
        pos.clear();
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w && scanf(" %c", &map[i][j]); j++)
                if (map[i][j] == '*') pos.push_back({ i, j });
                else if (map[i][j] == 'o') ox = i, oy = j;
        if (setDist()) dfs(0);
        printf("%d\n", ans == INF ? -1 : ans);
    }
}

/*
먼저 각 좌표 사이의 거리를 모두 구해줍니다.
그 뒤, 가능한 청소 순서를 모두 만들어내서 최소의 거리를 구해줬습니다.
*/