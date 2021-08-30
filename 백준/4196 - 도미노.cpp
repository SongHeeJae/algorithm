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
        init();

		scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			graph[a].push_back(b);
		}

		for (int i = 1; i <= n; i++) {
			if (id[i] == 0) dfs(i);
		}

		for (int i = 1; i <= n; i++) {
			for (auto e : graph[i]) {
				if (grp[i] != grp[e]) {
					indegree[grp[e]]++;
				}
			}
		}

		int cnt = 0;
		for (int i = 1; i <= scc.size(); i++) {
			if (indegree[i] == 0) cnt++;
		}
		printf("%d\n", cnt);
	}
}

/*
여러 개의 도미노로 이루어진 하나의 SCC를 하나의 새로운 노드로 보고,
이렇게 만들어진 새로운 노드의 indegree가 0이라면, 그 곳에 속한 하나의 도미노는 수동으로 넘어뜨려야합니다.
*/