#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 100001
using namespace std;

int n, m, num = 1;
vector<int> graph[MAX];
int id[MAX] = { 0 };
int sccIdx[MAX] = { 0 };
vector<vector<int>> scc;
stack<int> stk;
int indegree[MAX] = { 0 };

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
	for (int i = 0; i < n; i++) {
		if (id[i] == 0) {
			dfs(i);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	createScc();

	for (int i = 0; i < n; i++) {
		for (auto e : graph[i]) {
			if (sccIdx[i] != sccIdx[e]) {
				indegree[sccIdx[e]]++;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= scc.size(); i++) {
		if (indegree[i] == 0) {
			ans++;
		}
	}
	cout << ans;
}

/*
진입 차수가 0인 scc의 개수를 구해주면 됩니다.
*/