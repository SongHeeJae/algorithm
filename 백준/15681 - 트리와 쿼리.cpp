#include <iostream>
#include <vector>
using namespace std;

int n, r, q, u, v;
vector<int> graph[100001];
int dp[100001] = { 0 };

int init(int node) {
	dp[node] = 1;
	for (int i = 0; i < graph[node].size(); i++) {
		if (dp[graph[node][i]] != 0) continue;
		dp[node] += init(graph[node][i]);
	}
	return dp[node];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> r >> q;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	init(r);

	while (q--) {
		cin >> u;
		cout << dp[u] << "\n";
	}
}

/*
루트에서 시작하여 각 정점들을 깊이 우선 탐색하여 방문하고, 방문한 정점들을 빠져나오면서 각 정점이 방문했던 정점의 개수들을 기억해주었습니다.
*/