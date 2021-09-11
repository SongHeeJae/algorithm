#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX 20001
using namespace std;

int t, n, m, num;
vector<vector<int>> graph;
int id[MAX] = { 0 };
int sccIdx[MAX] = { 0 };
vector<vector<int>> scc;
stack<int> stk;
int indegree[MAX] = { 0 };
int outdegree[MAX] = { 0 };

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

void init() {
	num = 1;
	memset(id, 0, sizeof(id));
	memset(sccIdx, 0, sizeof(sccIdx));
	memset(indegree, 0, sizeof(indegree));
	memset(outdegree, 0, sizeof(outdegree));
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

		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
		}

		createScc();

		if (scc.size() == 1) {
			cout << "0\n";
			continue;
		}

		for (int i = 1; i <= n; i++) {
			for (auto e : graph[i]) {
				if (sccIdx[i] != sccIdx[e]) {
					indegree[sccIdx[e]]++;
					outdegree[sccIdx[i]]++;
				}
			}
		}

		int inCnt = 0;
		int outCnt = 0;
		for (int i = 1; i <= scc.size(); i++) {
			if (indegree[i] == 0) inCnt++;
			if (outdegree[i] == 0) outCnt++;
		}
		cout << max(inCnt, outCnt) << "\n";
	}
}

/*
'a이면 b이다'라는 함축을 a에서 b로 가는 간선으로 표시해줍니다.
만약 이미 동치 관계에 있는 함축이라면, 명제 간에 사이클을 형성하고 있습니다.
만들어진 그래프로 scc를 만들어내고,
사이클이 없는 컴포넌트 간에 사이클을 형성해주는 간선의 최소 개수가,
동치임을 증명하기 위해 사용하는 함축의 최소 수가 됩니다.
즉, 여러 개의 scc를 하나의 scc로 묶어내면 됩니다. ( 이미 1개라면 함축을 추가할 필요가 없습니다. )
컴포넌트 간에 사이클을 만들어내기 위해서 indegree와 outdegree를 이용하였습니다.
outdegree가 0인 컴포넌트를 indegree가 0인 컴포넌트에 연결시키거나,
indegree가 0인 컴포넌트를 outdegree가 0인 컴포넌트에 연결시키면 사이클이 만들어집니다.
결국 모든 컴포넌트를 하나로 묶으려면,
outdegree가 0인 컴포넌트의 개수와 indegree가 0인 컴포넌트의 개수 중에 더 큰 값이 사용해야 하는 함축의 수의 최솟값이 됩니다. 
*/