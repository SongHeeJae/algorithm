#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>
#define NOT 1000
#define MAX 2 * NOT + 1
using namespace std;

int n, m, num = 1;
int id[MAX];
int finished[MAX];
vector<vector<int>> graph;
vector<vector<int>> scc;
stack<int> stk;

int notValue(int val) {
	if (val > NOT) return val - NOT;
	else return val + NOT;
}

int fitValue(int val) {
	if (val < 0) return -val + NOT;
	else return val;
}

int dfs(int node) {
	id[node] = num++;
	stk.push(node);

	int res = id[node];

	for (int nxt : graph[node]) {
		if (id[nxt] == 0) res = min(res, dfs(nxt));
		else if (!finished[nxt]) res = min(res, id[nxt]);
	}

	if (res == id[node]) {
		vector<int> temp;
		int idx = scc.size() + 1;
		while (1) {
			int top = stk.top();
			stk.pop();
			finished[top] = idx;
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
		if (id[notValue(i)] == 0) dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (cin >> n >> m) {
		num = 1;
		memset(id, 0, sizeof(id));
		memset(finished, 0, sizeof(finished));
		graph.clear();
		graph.resize(MAX);
		scc.clear();

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			a = fitValue(a);
			b = fitValue(b);
			graph[notValue(a)].push_back(b);
			graph[notValue(b)].push_back(a);
		}

		createScc();

		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (finished[i] == finished[notValue(i)]) {
				flag = false;
				break;
			}
		}

		cout << flag << "\n";
	}
}

/*
M개의 답변을 하나의 OR 절로 보고, 모든 답변을 만족시키도록 2-SAT 문제를 풀었습니다.
*/