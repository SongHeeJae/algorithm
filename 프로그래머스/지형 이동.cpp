#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#define INF 2147483647
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0, -1,1};
bool visit[300][300] = {false};
int area[300][300] = {0};
int landCnt = 0;
vector<vector<int>> ladder;

void bfs(vector<vector<int>>& land, int x, int y, int height) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true;
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        area[xx][yy] = landCnt;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx < 0 || ny < 0 || nx >= land.size() ||  ny >= land.size()) continue;
            if(visit[nx][ny]) continue;
            if(abs(land[xx][yy] - land[nx][ny]) > height) continue;  
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    landCnt++;
}

void seperateLand(vector<vector<int>>& land, int height) {
    for(int i=0; i<land.size(); i++) {
        for(int j=0; j<land.size(); j++) {
            if(visit[i][j]) continue;
            bfs(land, i, j, height);
        }
    }
}

void initLadder(vector<vector<int>>& land, int height) {
    for(int i=0; i<land.size(); i++) {
        for(int j=0; j<land.size(); j++) {
            int h = land[i][j];
            for(int k=0; k<4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || ny < 0 || nx >= land.size() ||  ny >= land.size()) continue;
                if(area[nx][ny] == area[i][j]) continue;
                int nh = land[nx][ny];
                int diff = abs(h - nh);
                if(diff <= height) continue;
                ladder.push_back({diff, area[i][j], area[nx][ny]});
            }
        }
    }
}

int findParent(vector<int>& parent, int x) {
    if(parent[x] == x) return x;
    else return parent[x] = findParent(parent, parent[x]);
}

int getMinimumCost() {
    int ans = 0;
    sort(ladder.begin(), ladder.end());
    vector<int> parent(ladder.size());
    for(int i=0; i<parent.size(); i++) parent[i] = i;
    for(int i=0; i<ladder.size(); i++) {
        int cost = ladder[i][0];
        int a1 = ladder[i][1];
        int a2 = ladder[i][2];
        int pa1 = findParent(parent, a1);
        int pa2 = findParent(parent, a2);
        if(pa1 != pa2) {
            ans += cost;
            if(--landCnt == 1) break;
            parent[pa2] = pa1;
        }
    }
    return ans;
}

int solution(vector<vector<int>> land, int height) {
    seperateLand(land, height);
    initLadder(land, height);
    return getMinimumCost();
}

/*
먼저 주어진 height로 이동 가능한 각 영역들을 묶어줍니다.
그 뒤, 각 영역에서 다른 영역으로 이동 가능한 간선(사다리)의 비용을 구해줍니다.
마지막으로 간선을 통해 모든 영역을 이동할 수 있는 최소 비용을 구해줍니다.
*/