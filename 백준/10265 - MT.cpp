#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, k, num = 1;
int id[MAX] = { 0 };
int sccIdx[MAX] = { 0 };
vector<int> graph[MAX];
vector<vector<int>> scc;
stack<int> stk;
int indegree[MAX] = { 0 };
int visit[MAX] = { 0 };
vector<int> sccGraph[MAX];
bool dp[MAX] = { true }; // dp[i] = i명을 태울 수 있는지, default dp[0] = true

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
		if (id[i] == 0) dfs(i);
	}
}

int sccDfs(int node, int v) {
	visit[node] = v;
	int s = scc[node - 1].size();
	for (auto nxt : sccGraph[node]) {
		if (visit[nxt] == v) continue;
		s += sccDfs(nxt, v);
	}
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		// x번이 타지 않으면 i번도 타지 않으므로, x번이 타야만 i번도 탄다.
		// 하지만 x번이 탄다고 i번이 꼭 타야하는 것은 아님.
		int x;
		cin >> x;
		graph[x].push_back(i);
	}

	createScc();

	for (int i = 1; i <= n; i++) {
		for (auto e : graph[i]) {
			if (sccIdx[i] != sccIdx[e]) {
				indegree[sccIdx[e]]++;
				sccGraph[sccIdx[i]].push_back(sccIdx[e]);
			}
		}
	}

	dp[0] = true;
	for (int i = 1; i <= scc.size(); i++) {
		if (indegree[i] != 0) continue;
		int mn = scc[i - 1].size();
		int mx = sccDfs(i, i);
		for (int j = k; j >= 0; j--) {
			for (int m = mn; m <= mx && j - m >= 0; m++) {
				dp[j] |= dp[j - m];
			}
		}
	}

	for (int i = k; i >= 0; i--) {
		if (dp[i]) {
			cout << i;
			break;
		}
	}
}

/*
x번이 버스에 타지 않는다면 i번도 버스에 타지 않으므로, x번이 타야만 i번이 타게 됩니다.
하지만, x번이 탄다고 해서 i번이 꼭 타야하는 것은 아닙니다. 이것을 x->i 그래프의 간선으로 표시해줍니다.
주어진 그래프로 scc를 구하고, 진입 차수가 0인 scc를 찾아줍니다.
진입 차수가 0이라면, 선행되어야 하는 사람들이 없으므로, 해당 컴포넌트의 사람들은 남들에게 구애받지 않고 탈 수 있습니다.
또, 해당 컴포넌트에서 이동할 수 있는 다른 컴포넌트의 사람들은, 해당 컴포넌트의 사람들이 버스에 타야만 탑승할 수 있습니다.
즉, 진입 차수가 0인 컴포넌트의 인원 수 ~ 현재 컴포넌트에서 이동할 수 있는 모든 컴포넌트의 인원 수까지 버스에 탑승할 수 있습니다.
dp[i] = i명이 버스에 탑승할 수 있는지 여부를 저장해주고,
탑승 가능한 인원 수 중에 k에 가장 가까운 수를 구해주면 됩니다.
탑승 여부를 중복으로 검사하는 것을 방지하기 위해, 반복 인덱스 i는 역순으로 수행해주었습니다.

---

아래는 처음 풀이했던 방식인데, 컴포넌트 개수가 m일 때,
dp[i][j] = i~m번 컴포넌트에서 태울 수 있는 인원 수가 j일 때, 탑승 가능한 최대 인원수를 구해주었습니다.

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

int n, k, num = 1;
int id[MAX] = { 0 };
int sccIdx[MAX] = { 0 };
vector<int> graph[MAX];
vector<vector<int>> scc;
stack<int> stk;
int indegree[MAX] = { 0 };
int visit[MAX] = { 0 };
vector<int> sccGraph[MAX];
int dp[MAX][MAX];
vector<pair<int, int>> cnt; // {최소, 최대}

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
		if (id[i] == 0) dfs(i);
	}
}

int sccDfs(int node, int v) {
	visit[node] = v;
	int s = scc[node - 1].size();
	for (auto nxt : sccGraph[node]) {
		if (visit[nxt] == v) continue;
		s += sccDfs(nxt, v);
	}
	return s;
}

int solve(int idx, int w) {

	if (idx >= cnt.size()) {
		return 0;
	}

	int& ret = dp[idx][w];

	if (ret != -1) return ret;

	ret = max(ret, solve(idx + 1, w));

	for (int i = cnt[idx].first; i <= cnt[idx].second; i++) {
		if (w - i < 0) break;
		ret = max(ret, solve(idx + 1, w - i) + i);
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(dp, -1, sizeof(dp));

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		// x번이 타지 않으면 i번도 타지 않으므로, x번이 타야만 i번도 탄다.
		// 하지만 x번이 탄다고 i번이 꼭 타야하는 것은 아님.
		int x;
		cin >> x;
		graph[x].push_back(i);

	}

	createScc();


	for (int i = 1; i <= n; i++) {
		for (auto e : graph[i]) {
			if (sccIdx[i] != sccIdx[e]) {
				indegree[sccIdx[e]]++;
				sccGraph[sccIdx[i]].push_back(sccIdx[e]);
			}
		}
	}

	for (int i = 1; i <= scc.size(); i++) {
		if (indegree[i] == 0) {
			int res = sccDfs(i, i);
			cnt.push_back({ scc[i - 1].size(), res });
		}
	}

	cout << solve(0, k) << endl;
}
*/