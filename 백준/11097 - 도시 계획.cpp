#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX 301
using namespace std;

int t, n, num;
vector<vector<int>> graph;
int id[MAX] = { 0 };
int sccIdx[MAX] = { 0 };
vector<vector<int>> scc;
stack<int> stk;
vector<pair<int, int>> edges;
bool conn[MAX][MAX] = { false };

int dfs(int node) {
	id[node] = num++;
	stk.push(node);

	int res = id[node];

	for (int nxt : graph[node]) {
		if (id[nxt] == 0) res = min(res, dfs(nxt));
		else if (!sccIdx[nxt]) res = min(res, id[nxt]);
	}

	if (res == id[node]) {
		vector<int> temp;
		int idx = scc.size() + 1;
		while (1) {
			int top = stk.top();
			stk.pop();
			sccIdx[top] = idx;
			temp.push_back(top);
			if (top == node) break;
		}
		scc.push_back(temp);
	}

	return res;
}

void createScc() {
	for (int i = 1; i <= n; i++) {
		if (id[i] == 0) {
			dfs(i);
		}
	}
}

void addAdgesBetweenSameScc() {
	for (auto sc : scc) {
		int sz = sc.size();
		if (sz < 2) continue;
		for (int i = 0; i < sz; i++) {
			edges.push_back({ sc[i], sc[(i + 1) % sz] });
		}
	}
}

void initConnectedScc() {
	for (int i = 1; i <= n; i++) {
		for (auto e : graph[i]) {
			if (sccIdx[i] != sccIdx[e]) {
				conn[sccIdx[i]][sccIdx[e]] = true;
			}
		}
	}
}

void removeAlreadyConnectedShortestSccEdge() {
	for (int i = 1; i <= scc.size(); i++) {
		for (int j = 1; j <= scc.size(); j++) {
			if (!conn[i][j]) continue;
			for (int k = 1; k <= scc.size(); k++) {
				if (conn[i][k] && conn[k][j]) {
					conn[i][j] = false;
					break;
				}
			}
		}
	}
}

void addAdgesBetweenDiffScc() {
	initConnectedScc();
	removeAlreadyConnectedShortestSccEdge();
	for (int i = 1; i <= scc.size(); i++) {
		for (int j = 1; j <= scc.size(); j++) {
			if (conn[i][j]) edges.push_back({ scc[i - 1][0], scc[j - 1][0] });
		}
	}
}

void init() {
	num = 1;
	memset(id, 0, sizeof(id));
	memset(sccIdx, 0, sizeof(sccIdx));
	memset(conn, false, sizeof(conn));
	edges.clear();
	scc.clear();
	graph.clear();
	graph.resize(MAX);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		init();

		cin >> n;
		for (int i = 1; i <= n; i++) {
			string ab;
			cin >> ab;
			for (int j = 0; j < n; j++) {
				if (ab[j] == '1') graph[i].push_back(j + 1);
			}
		}

		createScc();

		addAdgesBetweenSameScc();

		addAdgesBetweenDiffScc();

		cout << edges.size() << "\n";
		for (auto edge : edges) {
			cout << edge.first << " " << edge.second << "\n";
		}
		cout << "\n";
	}
}

/*
동일한 SCC 간에는, 서로 이동할 수 있도록 노드들 간에 사이클을 형성하여 최소한의 간선을 만들어주면 됩니다.

다른 SCC 간에는, 인접한 SCC를 연결하는 하나의 간선을 만들어주면 됩니다.
하지만, A에서 B로 이동하는 경로가 여러 개 있고,
어차피 다른 곳으로 경유해서 갈 수 있다면, 경유하지 않는 다른 경로는 제외할 수 있습니다.
예를 들어,
A -> B -> C
A -> C
위와 같이 컴포넌트 사이에 세 개의 간선이 만들어져있다면,
A -> C 간선은 B를 경유해서 갈 수 있으므로 제거할 수 있습니다.
*/