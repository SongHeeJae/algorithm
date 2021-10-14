#include <iostream>
#include <vector>
using namespace std;

int t, n, a, v = 1, visit[1001] = { 0 };
vector<vector<int>> graph;

void dfs(int node) {
	visit[node] = v;
	for (int nxt : graph[node]) {
		if (visit[nxt] != v)
			dfs(nxt);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		graph.clear();
		graph.resize(n + 1);

		for (int i = 1; i <= n; i++) {
			cin >> a;
			graph[i].push_back(a);
		}

		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (visit[i] != v) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
		v++;
	}
}

/*
주어진 순열로 그래프를 만들어서, 분리된 그래프의 개수를 구해주었습니다.
*/