#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>
#define MAX 51 * 50 + 1
typedef long long ll;
using namespace std;

int n, m, num = 1;
int indegree[MAX] = { 0 };
string out;
stack<string> stk;
vector<int> sccGraph[MAX];
vector<vector<string>> scc;
unordered_map<string, ll> score;
unordered_map<string, int> id, sccIdx;
unordered_map<string, vector<string>> graph;

int dfs(string node) {
	id[node] = num++;
	stk.push(node);

	int res = id[node];

	for (string& nxt : graph[node]) {
		if (id[nxt] == 0) res = min(res, dfs(nxt));
		else if (!sccIdx[nxt]) res = min(res, id[nxt]);
	}

	if (res == id[node]) {
		vector<string> temp;
		int idx = scc.size() + 1;
		while (1) {
			string top = stk.top();
			sccIdx[top] = idx;
			temp.push_back(top);
			stk.pop();
			if (top == node) break;
		}
		scc.push_back(temp);
	}

	return res;
}

void createScc() {
	for (auto it = graph.begin(); it != graph.end(); it++) {
		string node = it->first;
		if (id[node] == 0) {
			dfs(node);
		}
	}
}

void initSccGraphAndSccIndegree() {
	for (auto it = graph.begin(); it != graph.end(); it++) {
		string cur = it->first;
		int curSccIdx = sccIdx[cur];
		for (auto& nxt : it->second) {
			int nxtSccIdx = sccIdx[nxt];
			if (curSccIdx != nxtSccIdx) {
				indegree[nxtSccIdx]++;
				sccGraph[curSccIdx].push_back(nxtSccIdx);
			}
		}
	}
}

void calculateWebSiteScore() {
	queue<int> q;
	for (int i = 1; i <= scc.size(); i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (auto& curNode : scc[cur - 1]) {
			for (auto& nxtNode : graph[curNode]) {
				if (sccIdx[curNode] != sccIdx[nxtNode]) {
					score[nxtNode] += score[curNode];
				}
			}
		}

		for (auto nxt : sccGraph[cur]) {
			if (--indegree[nxt] == 0) {
				q.push(nxt);
			}
		}
	}
}

void initGraphKey(string& key) {
	if (graph.find(key) == graph.end()) {
		graph.insert({ key, vector<string>() });
		id.insert({ key, 0 });
		sccIdx.insert({ key, 0 });
		score.insert({ key, 1 });
	}
}

void inputAndInitGraph() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string cur, nxt;
		cin >> nxt >> m;
		initGraphKey(nxt);
		for (int j = 0; j < m; j++) {
			cin >> cur;
			initGraphKey(cur);
			graph[cur].push_back(nxt);
		}
	}
	cin >> out;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	inputAndInitGraph();

	createScc();

	initSccGraphAndSccIndegree();

	calculateWebSiteScore();
	
	cout << score[out];
}

/*
같은 scc에 묶인 웹사이트들은, 서로 간의 점수에 영향을 줄 수 없습니다.
다른 scc에 있을 때만, 연결된 간선으로 인해 점수를 추가시킬 수 있습니다.
유의할 점은 같은 scc라고 해서, 같은 점수를 가지는 것은 아니라는 것입니다.
해당 웹사이트로 연결된 간선이 있을 때만, 기존의 점수를 추가시킬 수 있습니다.
또, scc의 개수를 간과해서 범위 오류가 났었는데, 하나의 링크 정보에서는 51개의 scc가 만들어질 수 있습니다.

scc를 구해둔 상태에서, 각 웹사이트들의 점수를 구한 방법은 다음과 같습니다.
1. scc들의 진입 차수와 그래프를 구하고, 위상 정렬 알고리즘을 수행합니다.
2. 순서대로 방문하는 scc에 속한 노드에서, 인접한 노드가 다른 scc라면, 속한 노드의 점수를 추가시켜줍니다.
*/