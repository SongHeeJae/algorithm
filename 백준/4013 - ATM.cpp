#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAX 500001
using namespace std;

int n, m, s, p, num;
int id[MAX] = { 0 };
bool finished[MAX] = { false };
bool rest[MAX] = { false };
bool grpRest[MAX] = { false };
int grp[MAX];
int cost[MAX];
int grpCost[MAX] = { 0 };
int startGrpIdx = -1;
vector<int> graph[MAX];
vector<vector<int>> scc;
vector<vector<int>> sccGraph;
stack<int> stk;

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
		bool restContained = false;
		int grpIdx = scc.size() + 1;
		while (1) {
			int top = stk.top();
			stk.pop();
			finished[top] = true;
			temp.push_back(top);
			grp[top] = grpIdx;
			restContained |= rest[top];
			grpCost[grpIdx] += cost[top];
			if (s == top) startGrpIdx = grpIdx;
			if (top == node) break;
		}
		grpRest[grpIdx] = restContained;
		scc.push_back(temp);
	}

	return res;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}

	cin >> s >> p;
	for (int i = 0; i < p; i++) {
		int pp;
		cin >> pp;
		rest[pp] = true;
	}
}

void createScc() {
	for (int i = 1; i <= n; i++) {
		if (id[i] == 0) dfs(i);
	}
}

void createSccGraph() {
	sccGraph.resize(scc.size() + 1);
	for (int i = 1; i <= n; i++) {
		for (auto e : graph[i]) {
			if (grp[i] != grp[e]) {
				sccGraph[grp[i]].push_back(grp[e]);
			}
		}
	}
}

int calMaximumGrp() {
	int mx = 0;
	priority_queue<pair<int, int>> pq;
	vector<int> d(scc.size() + 1, 0);

	pq.push({ grpCost[startGrpIdx], startGrpIdx });
	d[startGrpIdx] = grpCost[startGrpIdx];

	while (!pq.empty()) {
		int gCost = pq.top().first;
		int gIdx = pq.top().second;
		if (grpRest[gIdx]) mx = max(mx, gCost);
		pq.pop();
		if (d[gIdx] > gCost) continue;
		for (auto& nextIdx : sccGraph[gIdx]) {
			int nextCost = gCost + grpCost[nextIdx];
			if (d[nextIdx] < nextCost) {
				d[nextIdx] = nextCost;
				pq.push({ nextCost, nextIdx });
			}
		}
	}
	return mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	input();

	createScc();
	
	createSccGraph();
		
	cout << calMaximumGrp();
}

/*
교차로들을 SCC로 묶어줬을 때, 레스토랑이 포함되어있다면, 해당 SCC 내에 있는 모든 은행을 방문할 수 있습니다.
SCC를 만들어서, 각 SCC 간의 이동 관계를 별도의 그래프로 만들어줍니다.
이 때, 각 SCC 별로 레스토랑이 포함되어있는지를 기록해주고, 시작 지점이 포함된 SCC의 번호, 각 SCC 별 은행의 총 비용을 구해줍니다.
그렇게 만들어진 그래프로, 시작 지점이 포함된 SCC에서부터 다익스트라 알고리즘을 수행하여, 다른 SCC를 방문하는 최대 비용을 구해주었습니다.
레스토랑이 포함되어있는 SCC에 도달했을 때, 인출할 수 있는 현금의 최대 액수를 업데이트해주었습니다.
*/