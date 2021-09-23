#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX 1001

int n, m, a, b, c, v = 0;
vector<pair<int, int>> graph[MAX];
int visit[MAX] = { 0 };

int getDist(int src, int dst) {
	queue<pair<int, int>> q;
	visit[src] = ++v;
	q.push({ src, 0 });
	while (!q.empty()) {
		int node = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (node == dst) {
			return dist;
		}
		for (auto& nxt : graph[node]) {
			if (visit[nxt.first] == v) continue;
			visit[nxt.first] = v;
			q.push({ nxt.first, dist + nxt.second });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	while (m--) {
		cin >> a >> b;
		cout << getDist(a, b) << "\n";
	}
}

/*
N, M 범위가 작으므로 단순히 BFS로 두 노드 사이의 거리를 구해주었습니다.
*/