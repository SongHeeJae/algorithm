#include <iostream>
#include <vector>
#include <queue>
#define TUBE 100001
using namespace std;

int n, k, m, a;
vector<int> graph[101001];
bool visit[101001] = { false };

int bfs() {
	queue<pair<int, int>> q;
	q.push({1, 1});
	visit[1] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int c = q.front().second;
		q.pop();
		if (x == n) return c;
		for (int i = 0; i < graph[x].size(); i++) {
			if (visit[graph[x][i]]) continue;
			visit[graph[x][i]] = true;
			q.push({ graph[x][i], c + (x < TUBE) });
		}
	}
	return -1;
}

int main() {
	scanf("%d %d %d", &n, &k, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			scanf("%d", &a);
			graph[TUBE + i].push_back(a);
			graph[a].push_back(TUBE + i);
		}
	}
	printf("%d", bfs());
}

/*
역 뿐만 아니라, 하이퍼튜브도 하나의 정점으로 보고 그래프 형태를 만들어주었습니다.
BFS를 수행하며 역의 개수만 세어주면 됩니다.
*/