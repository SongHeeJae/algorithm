#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 100001
using namespace std;

int t, n, m, num;
int id[MAX];
int indegree[MAX];
bool finished[MAX];
int grp[MAX];
vector<vector<int>> graph;
vector<vector<int>> scc;
stack<int> stk;

void init() {
	num = 1;
	graph.clear();
	graph.resize(MAX);
	scc.clear();
	memset(finished, false, sizeof(finished));
	memset(id, 0, sizeof(id));
	memset(indegree, 0, sizeof(indegree));
	memset(grp, 0, sizeof(grp));
}

int dfs(int node) {
	id[node] = num++;
	stk.push(node);

	int res = id[node];
	for (auto nxt : graph[node]) {
		if (id[nxt] == 0) {
			res = min(res, dfs(nxt));
		}
		else if (!finished[nxt]) {
			res = min(res, id[nxt]);
		}
	}

	if (res == id[node]) {
		vector<int> temp;
		while (1) {
			int top = stk.top();
			stk.pop();
			finished[top] = true;
			temp.push_back(top);
			grp[top] = scc.size() + 1;
			if (top == node) break;
		}
		scc.push_back(temp);
	}

	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		init();

		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
		}

		for (int i = 0; i < n; i++) {
			if (id[i] == 0) dfs(i);
		}

		for (int i = 0; i < n; i++) {
			for (auto e : graph[i]) {
				if (grp[i] != grp[e]) {
					indegree[grp[e]]++;
				}
			}
		}

		int cnt = 0, idx = -1;
		for (int i = 1; i <= scc.size(); i++) {
			if (indegree[i] == 0) {
				idx = i - 1;
				cnt++;
			}
		}

		if (cnt == 1) {
			sort(scc[idx].begin(), scc[idx].end());
			for (auto e : scc[idx]) {
				printf("%d\n", e);
			}
		}
		else {
			printf("Confused\n");
		}
		printf("\n");
	}
}

/*
진입 차수가 0인 SCC가 한 개만 있다면, 해당 SCC에 포함된 노드를 시작 지점으로 했을 때 다른 모든 구역에 도달할 수 있습니다.
*/