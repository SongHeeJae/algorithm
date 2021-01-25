#include <string>
#include <vector>
#include <queue>
using namespace std;
int dx[] = {-1,1,0,0, -1, 1, -1, 1};
int dy[] = {0,0, -1,1, 1, 1, -1, -1};
bool visit[100][100][100][100] = {false};
int tDir[] = {5, 7}, bDir[] = {4, 6};

void checkAndPush(queue<pair<int, pair<pair<int, int>, pair<int, int>>>> &q, vector<vector<int>> &board, int x1, int y1, int x2, int y2, int bx, int by, int t, int n) {
    if(x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || x1 >=n || y1 >= n || x2 >= n || y2 >= n) return;
    if(visit[x1][y1][x2][y2] || visit[x2][y2][x1][y1] || board[bx][by] || board[x1][y1] || board[x2][y2]) return;
    visit[x1][y1][x2][y2] = visit[x2][y2][x1][y1] = true;
    q.push({t + 1, {{x1, y1}, {x2, y2}}});
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    queue<pair<int, pair<pair<int, int>, pair<int, int>>>> q;
    visit[0][0][0][1] = true;
    q.push({0, {{0, 0}, {0,1}}});
    while(!q.empty()) {
        int x1 = q.front().second.first.first;
        int y1 = q.front().second.first.second;
        int x2 = q.front().second.second.first;
        int y2 = q.front().second.second.second;
        int t = q.front().first;
        q.pop();
        if(x1 == n - 1 && y1 == n - 1 || x2 == n - 1 && y2 == n - 1) return t;
        for(int i=0; i<4; i++) // 그대로 이동하는 경우
            checkAndPush(q, board, x1 + dx[i], y1 + dy[i], x2 + dx[i], y2 + dy[i], 0, 0, t, n);
        // 회전 하는 경우
        if(x1 == x2) { // 가로로 있는 경우
            int leftY = y1 < y2 ? y1 : y2;
            int rightY = y1 < y2 ? y2 : y1;
            for(int i=4; i<6; i++) // 왼쪽에 있는게 우하, 우상으로 이동
                checkAndPush(q, board, x1 + dx[i], leftY + dy[i], x1, rightY, x1 + dx[i], leftY, t, n);
            for(int i=6; i<8; i++) // 오른쪽에 있는게 좌상, 좌하로 이동
                checkAndPush(q, board, x1 + dx[i], rightY + dy[i], x1, leftY, x1 + dx[i], rightY, t, n);
        } else { // 세로로 있는 경우
            int topX = x1 < x2 ? x1 : x2;
            int botX = x1 < x2 ? x2 : x1;
            for(int i=0; i<2; i++) // 위쪽에 있는게 좌하, 우하로 이동
                checkAndPush(q, board, topX + dx[tDir[i]], y1 + dy[tDir[i]], botX, y1, topX, y1 + dy[tDir[i]], t, n);
            for(int i=0; i<2; i++) // 아래쪽에 있는게, 좌상, 우상으로 이동
                checkAndPush(q, board, botX + dx[bDir[i]], y1 + dy[bDir[i]], topX, y1, botX, y1 + dy[bDir[i]], t, n);
        }
    }
    return 0;
}

/*
BFS로 모든 이동 가능한 방향, 위치로 회전 및 이동하며 최소 시간을 구했습니다.
*/