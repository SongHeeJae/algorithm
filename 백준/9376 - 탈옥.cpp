#include <iostream>
#include <queue>
#include <cstring>
#define INF 987654321
using namespace std;
int t, h, w, ans;
char map[102][102] = { 0 };
int visit[3][102][102];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> prisoners;

void bfs() {
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
    pq.push({{ 0, 0,}, { 0, 0 } });
    pq.push({ {0, 1},{prisoners[0].first, prisoners[0].second} });
    pq.push({ {0, 2},{prisoners[1].first, prisoners[1].second} });
    visit[0][0][0] = 0;
    visit[1][prisoners[0].first][prisoners[0].second] = 0;
    visit[2][prisoners[1].first][prisoners[1].second] = 0;
    
    while (!pq.empty()) {
        int c = pq.top().first.first;
        int t = pq.top().first.second;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (visit[0][x][y] >= 0 && visit[1][x][y] >= 0 && visit[2][x][y] >= 0) {
            if(x > 0 && y > 0 && x <= h && y <= w) // 동시 만나는 지점
                ans = min(ans, visit[0][x][y] + visit[1][x][y] + visit[2][x][y] + (map[x][y] == '#' ? -2 : 0));    
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1) continue;
            if (visit[t][nx][ny] >= 0) continue;
            if (map[nx][ny] == '*') continue;
            int nc = map[nx][ny] == '#' ? c + 1 : c; // 다음 위치가 문이면 + 1
            visit[t][nx][ny] = visit[t][x][y] + (map[nx][ny] == '#' ? 1 : 0);
            pq.push({ {nc, t}, { nx, ny } });
        }
    }
}

int main() {
    scanf("%d", &t);
    while (t-- && scanf("%d %d", &h, &w)) {
        ans = INF;
        memset(map, 0, sizeof(map));
        memset(visit, -1, sizeof(visit));
        prisoners.clear();
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++) {
                scanf(" %c", &map[i][j]);
                if (map[i][j] == '$') prisoners.push_back({ i, j }); // 죄수 위치 기억
            }
        bfs();
        printf("%d\n", ans);
    }
}

/*
deque를 이용한 동일 구현

#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#define INF 987654321
using namespace std;
int t, h, w;
char map[102][102];
int visit[3][102][102]; // 모든 지점에서 지나온 문의 최수 갯수
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
vector<pair<int, int>> p;
deque<pair<int, pair<int, int>>> dq;
int bfs() {
    int ans = INF;
    dq.push_front({ 0,{0,0} });
    dq.push_front({ 1,{p[0].first, p[0].second} });
    dq.push_front({ 2,{p[1].first, p[1].second} });
    visit[0][0][0] = visit[1][p[0].first][p[0].second] = visit[2][p[1].first][p[1].second] = 0;
    while (!dq.empty()) {
        int t = dq.front().first; // 죄수 또는 입구인지 구분
        int x = dq.front().second.first;
        int y = dq.front().second.second;
        dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1) continue;
            if (visit[t][nx][ny] >= 0 || map[nx][ny] == '*') continue;
            if (map[nx][ny] == '#') { // 문이면 나중에
                visit[t][nx][ny] = visit[t][x][y] + 1;
                dq.push_back({ t, { nx, ny } });
            }
            else { // 아니면 먼저
                visit[t][nx][ny] = visit[t][x][y];
                dq.push_front({ t, { nx, ny } });
            }
        }
    }
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (map[i][j] != '*')
                ans = min(ans, visit[0][i][j] + visit[1][i][j] + visit[2][i][j] + (map[i][j] == '#' ? -2 : 0));
    return ans;
}

int main() {
    scanf("%d", &t);
    while (t-- && scanf("%d %d", &h, &w)) {
        memset(map, 0, sizeof(map));
        memset(visit, -1, sizeof(visit));
        p.clear();
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w && scanf(" %c", &map[i][j]); j++)
                if (map[i][j] == '$') p.push_back({ i, j });
        printf("%d\n", bfs());
    }
}

*/

/*
처음에는 입구 또는 각 죄수에서 입구 또는 각 죄수를 찾는 모든 경우의 최솟값으로 했는데, 시간도 오래 걸리고 오류가 있었습니다.

​

우선순위큐를 이용하여 두 죄수와 입구에서 통과할 수 있는 모든 공간에서 지나온 문의 최소 개수를 구해줍니다.

그러다가 두 죄수와 입구가 동시에 한 지점에서 만나는 곳이 있다면, 탈옥이 가능했던 지점입니다.

그 지점에서 지나온 문의 개수의 합을 구해줍니다.

만약 그 장소가 문이었다면, 세 개가 동시에 중첩되어있으므로 -2를 해줍니다.

이렇게 구해진 최솟값이 두 죄수를 탈옥시키기 위해서 열어야하는 문의 최소 개수입니다.

주의해야할 점은, 상근이는 감옥 밖을 자유롭게 이동할 수 있다는 점입니다.

꼭 특정 지점에서 문을 통과할 필요는 없었습니다.

(이거 안해주면 대회 테스트데이터에서는 다 맞는데도 백준 100%에서 자꾸 틀렸었습니다..)

이 때문에 기존 크기보다 가로세로의 여백공간을 한줄씩 더 만들어준 뒤, 입구는 그 곳에서부터 시작하게 해주었습니다.
*/