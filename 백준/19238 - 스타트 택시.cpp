#include <iostream>
#include <queue>
#include <unordered_map>
#define INF 2147483647
using namespace std;

int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

int n, m, k, tx, ty, a, b, c, d, cnt = 0, v = 1;
int map[21][21] = { 0 };
int visit[21][21] = { 0 };
unordered_map<int, pair<int, int>> dest;

vector<int> filterGuest(vector<vector<int>>& finded) {
	int fg = finded[0][0], fx = finded[0][1], fy = finded[0][2];
	for (int i = 1; i < finded.size(); i++) {
		int g = finded[i][0], x = finded[i][1], y = finded[i][2];
		if (x < fx) {
			fg = g, fx = x, fy = y;
		}
		else if (x == fx) {
			if (y < fy) {
				fg = g, fx = x, fy = y;
			}
		}
	}
	return { fg, fx, fy };
}

vector<int> pickUpGuest() {
	v++;
	vector<vector<int>> finded;
	int dist = INF;
	queue<vector<int>> q;
	q.push({ tx, ty, 0 });
	visit[tx][ty] = v;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int g = q.front()[2];
		q.pop();
		if (map[x][y] < 0) {
			if (k >= g && dist >= g) {
				finded.push_back({ -map[x][y], x, y });
				dist = g;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > n || visit[nx][ny] == v || map[nx][ny] == 1) continue;
			q.push({ nx, ny, g + 1 });
			visit[nx][ny] = v;
		}
	}
	if (finded.size() == 0) return { -1 };
	vector<int> filteredGuest = filterGuest(finded);
	map[filteredGuest[1]][filteredGuest[2]] = 0;
	k -= dist;
	return filteredGuest;
}

pair<int, int> findDest(int guest) {
	return dest[guest];
}

vector<int> dropGuest(int guest) {
	v++;
	pair<int, int> d = findDest(guest);
	queue<vector<int>> q;
	q.push({ tx, ty, 0 });
	visit[tx][ty] = v;
	while (!q.empty()) {
		int x = q.front()[0];
		int y = q.front()[1];
		int g = q.front()[2];
		q.pop();
		if (x == d.first && y == d.second) {
			if (k >= g) {
				k -= g;
				k += 2 * g;
				return { x, y };
			}
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || ny < 1 || nx > n || ny > n || visit[nx][ny] == v || map[nx][ny] == 1) continue;
			q.push({ nx, ny, g + 1 });
			visit[nx][ny] = v;
		}
	}
	return { -1, -1 };
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	scanf("%d %d", &tx, &ty);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		map[a][b] = -i;
		dest.insert({ i, {c, d} });
	}

	while (cnt < m) {
		vector<int> pPos = pickUpGuest();
		if (pPos[0] == -1) break;
		tx = pPos[1], ty = pPos[2];
		vector<int> dPos = dropGuest(pPos[0]);
		if (dPos[0] == -1) break;
		tx = dPos[0], ty = dPos[1];
		cnt++;
	}
	printf("%d", cnt == m ? k : -1);
}

/*
몇 가지 예외사항을 잘 신경써줘야했습니다.

"모든 출발지는 서로 다르며, 각 손님의 출발지와 목적지는 다르다."
즉, 각 손님의 출발지는 다르지만, 목적지는 같을 수 있습니다.
따라서 출발지는 기존의 지도 위에 표현해도 되었지만, 목적지는 손님의 번호를 붙여서 별도로 기억해줘야 했습니다.

연료는 손님을 태운 시점부터 도착지까지의 이동거리의 두 배가 늘어나게 됩니다.

최단 거리의 승객이 여러 명일 때, (행 번호, 열 번호)가 더 작은 승객을 선택해줘야 합니다.
*/