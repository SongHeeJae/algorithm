#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 2147483647
using namespace std;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
vector<pair<int, pair<int, int>>> cardPos;
vector<pair<int, int>> selectPos; // 고른 카드 위치
vector<vector<int>> temp(4, vector<int>(4));
bool cardVisit[4] = {false};
int answer = INF;

void copy(vector<vector<int>>& a, vector<vector<int>>& b) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void swap(pair<int, int> &a, pair<int, int> &b) {
    pair<int, int> t = a;
    a = b;
    b = t;
}

int getMinDist(int sx, int sy, int ex, int ey, vector<vector<int>>& b) {
    bool visit[4][4] = {false};
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {sx, sy}});
    visit[sx][sy] = true;
    while(!q.empty()) {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int t = q.front().first;
        q.pop();
        if(x == ex && y == ey) return t;
        // 컨트롤키로 이동
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > 3 || ny > 3) continue;
            while(!b[nx][ny]) {
                int nnx = nx + dx[i];
                int nny = ny + dy[i];
                if(nnx < 0 || nny < 0 || nnx > 3 || nny > 3) break;
                nx = nnx;
                ny = nny;
            }
            if(visit[nx][ny]) continue;
            visit[nx][ny] = true;
            q.push({t + 1,{nx, ny}});
        }
        
        for(int i=0; i<4; i++) { // 한칸 이동
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx > 3 || ny > 3) continue;
            if(visit[nx][ny]) continue;
            visit[nx][ny] = true;
            q.push({t + 1,{nx, ny}});
        }
    }
    return -1;
}

void dfs(int d, vector<vector<int>>& board) {
    if(d == cardPos.size()) {
        copy(temp, board);
        int dist = 0;
        for(int i=1; i<selectPos.size(); i+=2) {
            int sx = selectPos[i].first;
            int sy = selectPos[i].second;
            int ex = selectPos[i+1].first;
            int ey = selectPos[i+1].second;
            int px = selectPos[i-1].first;
            int py = selectPos[i-1].second;
            dist += getMinDist(px, py, sx, sy, temp);
            dist += getMinDist(sx, sy, ex, ey, temp) + 2; // 엔터 두번
            temp[sx][sy] = temp[ex][ey] = 0;
        }
        if(answer > dist) answer = dist;
        return;
    }
    
    for(int i=0; i<cardPos.size(); i+=2) {
        if(cardVisit[cardPos[i].first]) continue;
        cardVisit[cardPos[i].first] = true;
        selectPos.push_back({cardPos[i].second.first, cardPos[i].second.second});
        selectPos.push_back({cardPos[i+1].second.first, cardPos[i+1].second.second});
        dfs(d+2, board);
        swap(selectPos[selectPos.size()-1], selectPos[selectPos.size()-2]);
        dfs(d+2, board);
        cardVisit[cardPos[i].first] = false;
        selectPos.pop_back();
        selectPos.pop_back();
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board.size(); j++) {
            if(board[i][j] != 0)
                cardPos.push_back({board[i][j], {i, j}});
        }
    }
    sort(cardPos.begin(), cardPos.end()); // 종류별로 정렬
    selectPos.push_back({r, c}); // 출발점 기억
    dfs(0, board);
    return answer;
}

/*
먼저 DFS를 이용하여 각 종류별 두 장의 카드를 선택하는 모든 좌표의 경우의 수를 구해주었습니다.
그리고 각 경우의 수 마다 BFS를 이용하여 해당 좌표로 이동 가능한 최단 거리를 구해주었습니다.
*/