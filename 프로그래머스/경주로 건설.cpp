#include <string>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
int dx[] = {-1,1,0,0};
int dy[] = {0, 0, -1,1};

int getCost(vector<vector<int>> board) {
    int n = board.size(), visit[25][25][4];
    priority_queue<pair<pair<int, int>, pair<int, int>>> pq;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<4; k++)
                visit[i][j][k] = INF;
    for(int i=0; i<4; i++) visit[0][0][i] = 0;
    pq.push({{0, -1}, {0, 0}});
    while(!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int d = pq.top().first.second; // 넘어온 방향 상하좌우 0123
        int c = -pq.top().first.first;
        pq.pop();
        if(x == n - 1 && y == n - 1) return c - 500; // 초기 -1 방향 500원 제외
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || board[nx][ny] == 1) continue;
            int nextPrice = c + (i != d ? 600 : 100);
            if(visit[nx][ny][i] > nextPrice) {
                visit[nx][ny][i] = nextPrice;
                pq.push({{-nextPrice, i}, {nx, ny}});
            }
        }
    }
    return -1;
}

int solution(vector<vector<int>> board) {
    return getCost(board);
}

/*
DFS로 풀었다가 케이스 14번이 통과되지않아서 확인해보니, 건너뛰어서 최소 비용이 나오는 경우를 잊고 있었습니다.

9999 5100 9999 9999 9999 
5600 5000 5600 9999 6300 
5100 4900 5500 5600 5700 
9999 4800 9999 6200 6300

위와 같은 상황이라고 가정하겠습니다.

5500 좌표는 5100에서 넘어온 경우라면, 5300이 될 수도 있습니다.
그런데 기존에 짠 DFS 코드에서는, 인근의 좌표만 보기때문에 케이스 14번과 같은 상황에서 5100을 통해 넘어온 상황을 인지할 수 없었습니다.
그래서 다익스트라로 코드를 바꿨습니다.
현재 좌표로 넘어온 방향을 기억해서 다음 진행 방향에 따른 가격을 구해주었습니다.
*/