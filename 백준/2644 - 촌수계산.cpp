#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph(101, vector<int>());
bool visited[101] = { false, };
int n, a, b, m, c, d;

void bfs() {
	queue<pair<int, int>> q;
	q.push({ a, 0 });
	visited[a] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int t = q.front().second;
		q.pop();
		if (x == b) {
			printf("%d", t);
			return;
		}
		for (int i = 0; i < graph[x].size(); i++) {
			if (!visited[graph[x][i]]) {
				visited[graph[x][i]] = true;
				q.push({ graph[x][i], t + 1 });
			}
		}
	}
	printf("-1");
}


int main() {
	scanf("%d %d %d %d", &n, &a, &b, &m);
	while (m--) {
		scanf("%d %d", &c, &d);
		graph[c].push_back(d);
		graph[d].push_back(c);
	}
	bfs();
}