#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m, num = 0, ans = INF, map[10][10];
int dx[] = { -1,0,1,0 }, dy[] = { 0, -1, 0, 1 };
bool visit[10][10] = { false }, island[7] = { false };
vector<pair<int, int>> pos[7]; // pos[i], i번 섬의 모든 좌표

void islandNumbering(int x, int y, int c) { // 각 섬의 번호 붙이기
	visit[x][y] = true;
	map[x][y] = c;
	pos[c].push_back({ x, y }); // 각 섬의 좌표 저장
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (map[nx][ny] == 0 || visit[nx][ny]) continue;
		islandNumbering(nx, ny, c);
	}
}

void bridge(int x, int y, int idx, int c, int sum) { // 다리 놓기

    // 섬이 X개이고, 두 섬 사이에 중복해서 다리를 놓지 않는다면,
    // X - 1개의 다리로 모든 섬을 연결시킬 수 있음.
	if (c == num - 1) { 
		ans = min(ans, sum); // 최솟값 업데이트
		return;
	}
	island[map[x][y]] = true; // 방문 섬 표시
	for (int i = 0; i < pos[map[x][y]].size(); i++) { // 각 섬의 모든 좌표. map[x][y]는 섬의 번호.
		if (i == idx) continue; // 이미 확인했던 지점 continue;
		int cx = pos[map[x][y]][i].first;
		int cy = pos[map[x][y]][i].second;
		for (int j = 0; j < 4; j++) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] != 0) continue;
            // 바다를 찾으면, 다리 놓을 수 있는지 확인
			int cnt = 1, f = 0, nnx = nx, nny = ny;
			while (1) {
				nnx = nnx + dx[j];
				nny = nny + dy[j]; // 현재의 방향으로 계속 이동
				if (nnx < 0 || nny < 0 || nnx >= n || nny >= m) break;
				if (map[nnx][nny] == map[x][y]) break; // 바다 지나온 곳이 현재 섬인지 확인
				if (map[nnx][nny] != 0) { // 다른 섬 도착
					f = 1;
					break;
				}
				cnt++; // 다리의 길이
			}
			if (f == 1 && cnt >= 2 && !island[map[nnx][nny]]) { 
            // 다리를 놓을 수 있는 위치 + 아직 다리를 놓지 않은 섬이라면,
			    bridge(nnx, nny, -1, c + 1, sum + cnt); // 다음 섬에 다리를 놓고, 그 섬으로 이동
				bridge(x, y, i, c + 1, sum + cnt); // 다음 섬에 다리만 놓고, 현재 섬에서 다른 위치 탐색(윗줄코드에서 이미 다리는 놓아져있음)
				island[map[nnx][nny]] = false;
			}
		}
	}
	
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%d", &map[i][j]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visit[i][j] && map[i][j] != 0)
				islandNumbering(i, j, ++num); // 넘버링

	for (int i = 1; i <= num; i++) {
		bridge(pos[i][0].first, pos[i][0].second, -1, 0, 0);
		island[map[pos[i][0].first][pos[i][0].second]] = false;
	}
	printf("%d", ans != INF ? ans : -1);
}

/*

먼저 입력을 받은 뒤, 각 섬을 구분하기 위해 DFS(islandNumbering)로 섬마다 별도의 번호를 붙여줬습니다.
그리고 각 섬들의 좌표를 pos[i]에 저장해두었습니다.
각 섬들마다 시작 점을 정하고 그거에 대해서 DFS(bridge)로 다리 놓는 작업을 시작하였습니다.

일단 섬이 X개라면, 모든 섬은 X-1개의 다리로 연결이 된다는 것을 눈치챘습니다.
이 점을 통해 X-1개의 다리가 놓아지는 것을, 모든 섬이 연결되는 것으로 보았습니다.

다리의 조건은 길이가 2 이상이고, 한 방향으로만 뻗을 수 있으며, 교차할 수 있다는 것이었습니다. 또한, 다리의 끝과 끝으로만 두 섬이 연결됩니다.
pos[i][j]에 저장해둔 각 섬들의 좌표를 모두 돌면서 다리를 놓아줬습니다.
현재 좌표에서 다리를 놓을 수 있는 지점으로 를 놓는다면, 두 가지 경우로 나누어주었습니다.
첫째로, 다음 섬으로 이동하여 그 섬에서 새롭게 다리를 놓을 지점을 찾는다.
둘째로, 다음 섬에 다리만 놓고, 현재의 섬에서 새롭게 다리를 놓을 지점을 찾는다. (하나의 섬에서 여러개의 다리를 놓을 수도 있기 때문)
그리고 다리를 놓은 지점은 별도로 방문 표시를 해두었습니다.


또, 질의응답 게시판에서 테스트 케이스를 확인해보며,
1 1
0 1
1 1
위와 같은 형태의 섬도 있다는 것을 알아두었습니다.

​

이러한 과정을 재귀적으로 돌며 문제를 해결하였습니다. 
*/