#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

int dx[] = { -1, 0, 0, 1 };
int dy[] = { 0, -1, 1, 0 };

void block(vector<vector<int>>& graph, int x, int y) {
	int n = graph.size();
	int m = graph[0].size();
	vector<vector<int>> d(n, vector<int>(m, INF));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	d[x][y] = 0;
	pq.push({0,  {x, y} });
	while (!pq.empty()) {
		int xx = pq.top().second.first;
		int yy = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();

		if (xx == n - 1 && yy == m - 1) break;
		if (d[xx][yy] < cost) continue;

		for (int i = 0; i < 4; i++) {
			int nextX = xx + dx[i];
			int nextY = yy + dy[i];
			if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < m) {
				int nextCost = cost + graph[nextX][nextY];
				if (d[nextX][nextY] > nextCost) {
					d[nextX][nextY] = nextCost;
					pq.push({ nextCost, {nextX, nextY} });
				}
			}

		}
	}
	printf("%d\n", d[n - 1][m - 1]);
}

int main()
{
	int n, m;
	scanf("%d %d", &m, &n);
	vector<vector<int>> graph(n, vector<int>(m));
	getchar();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			graph[i][j] = getchar() - '0';
		getchar();
	}

	block(graph, 0, 0);
}