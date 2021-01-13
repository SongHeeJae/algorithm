#include <iostream>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;
int t, h, w, ans = 0, f;
char map[100][101], temp[27];
bool visit[100][100];
bool keys[26] = { false };
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void bfs(int sx, int sy) {
    if (map[sx][sy] == '*') return;
    if (('A' <= map[sx][sy] && map[sx][sy] <= 'Z') && !keys[map[sx][sy] - 'A']) return;
    if (visit[sx][sy]) return;
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    visit[sx][sy] = true;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (map[x][y] == '$') map[x][y] = '.', cnt++;
        if ('a' <= map[x][y] && map[x][y] <= 'z' && !keys[map[x][y] - 'a']) {
            // 열쇠 찾음
            f = 0;
            keys[map[x][y] - 'a'] = true;
            while (!q.empty()) q.pop(); // 큐를 다 비워주고 현재 위치에서부터 재탐색
            memset(visit, false, sizeof(visit));
            visit[x][y] = true;
            q.push({ x, y });
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (visit[nx][ny]) continue;
            if (map[nx][ny] == '*') continue;
            if ('A' <= map[nx][ny] && map[nx][ny] <= 'Z' && !keys[map[nx][ny] - 'A'])
                continue; // 열쇠 없으면 이동 못함
            visit[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
    ans += cnt;
}

void startPoint(int flag) { // 빌딩 진입 위치 탐색. 상하좌우 모서리.
    if (flag == 0)
        for (int i = 0; i < w; i++) bfs(0, i);
    else if (flag == 1)
        for (int i = 0; i < w; i++) bfs(h - 1, i);
    else if (flag == 2)
        for (int i = 1; i < h - 1; i++) bfs(i, 0);
    else
        for (int i = 1; i < h - 1; i++) bfs(i, w - 1);
}

int main() {
    scanf("%d", &t);
    while (t-- && scanf("%d %d", &h, &w)) {
        ans = 0;
        memset(keys, false, sizeof(keys));
        memset(visit, false, sizeof(visit));
        for (int i = 0; i < h; i++) scanf("%s", map[i]);
        scanf("%s", temp);
        if (temp[0] != '0') // 열쇠 등록
            for (int i = 0; i < strlen(temp); i++) keys[temp[i] - 'a'] = true;
        while (1) {
            f = 1;
            for (int i = 0; i < 4; i++) startPoint(i);
            if (f) break; // 열쇠를 새로이 찾은 상황이라면 재탐색
        }
        printf("%d\n", ans);
    }
}


/*
먼저 모서리 부분들을 계속 돌면서, 빌딩에 진입할 수 있는 위치를 찾아줬습니다.

여기서 주의할 점은 빌딩 진입 부분에는 빈공간과 문, 벽 외에도 문서나 열쇠가 올 수도 있었습니다.

따라서 모서리 부분에서 열쇠를 새로이 습득하는 상황이라면, 모서리 부분을 계속해서 재탐색해주었습니다.

빌딩에 진입하면, BFS를 돌며 열쇠와 문서를 탐색합니다.

열쇠를 습득한다면, 큐를 다 비워주고, 그 위치에서부터 다시 탐색을 수행하였습니다.

한번 찾은 문서는 중복 카운트를 방지하기 위해 빈 공간으로 바꿔주었습니다.

*/