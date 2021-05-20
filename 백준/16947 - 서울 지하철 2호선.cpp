#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[3001];
int n, a, b;
int dist[3001] = { 0 };
bool cycle[3001] = { false };
bool visit[3001] = { false };

int dfs(int node, int prev) {
	if (visit[node]) return node; // 이미 방문한 역이면 사이클
	visit[node] = true;
	for (int i = 0; i < graph[node].size(); i++) {
		if (prev == graph[node][i]) continue;
		int ret = dfs(graph[node][i], node);
		if (ret > 0) {
			cycle[node] = true;
			if (ret == node) return -node; // 이 지점까지가 사이클을 형성. 음수로 반환
			else return ret;
		}
		else if(ret < 0) return ret; // 사이클을 형성하는 역 중 하나 반환
	}
	return 0;
}

void bfs(int start) { // start : 사이클을 형성하는 역 중 하나
	memset(visit, false, sizeof(visit));
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			if (visit[graph[x][i]]) continue;
			visit[graph[x][i]] = true;
			dist[graph[x][i]] = dist[x] + !cycle[graph[x][i]];
			q.push(graph[x][i]);
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(-dfs(1, -1));
	for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
}

/*
먼저, 주어진 노선에서 사이클을 형성하는 역들을 찾아서 기억해줍니다.

사이클을 형성하는 역 중 하나를 선택해서, 그 지점부터 BFS를 수행합니다.
*/